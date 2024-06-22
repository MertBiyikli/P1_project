#ifndef GRAPHMICROSERVICE_GRAPH_SERVICE_H
#define GRAPHMICROSERVICE_GRAPH_SERVICE_H

#include <iostream>
#include <vector>
#include <limits>
#include <memory>
#include <cassert>

// Constants and types
typedef unsigned int NodeID;
typedef double EdgeRatingType;
typedef unsigned int PathID;
typedef unsigned int PartitionID;
typedef unsigned int NodeWeight;
typedef int EdgeWeight;
typedef EdgeWeight Gain;
#ifdef MODE64BITEDGES
typedef uint64_t EdgeID;
#else
typedef unsigned int EdgeID;
#endif
typedef int Color;
typedef unsigned int Count;
typedef std::vector<NodeID> boundary_starting_nodes;
typedef long FlowType;

const EdgeID UNDEFINED_EDGE = std::numeric_limits<EdgeID>::max();
const NodeID UNDEFINED_NODE = std::numeric_limits<NodeID>::max();
const NodeID UNASSIGNED = std::numeric_limits<NodeID>::max();
const NodeID ASSIGNED = std::numeric_limits<NodeID>::max() - 1;
const PartitionID INVALID_PARTITION = std::numeric_limits<PartitionID>::max();
const PartitionID BOUNDARY_STRIPE_NODE = std::numeric_limits<PartitionID>::max();
const int NOTINQUEUE = std::numeric_limits<int>::max();
const int ROOT = 0;

struct edge_source_pair {
    EdgeID e;
    NodeID source;
};

struct source_target_pair {
    NodeID source;
    NodeID target;
};

// Define basicGraph as a type
typedef std::vector<std::vector<NodeID>> basicGraph;

// Graph class definition
class Graph {
public:
    Graph() : m_max_degree_computed(false), m_max_degree(0), graphref(std::make_shared<basicGraph>()), m_separator_block_ID(2) {}

    ~Graph() = default; // Smart pointer handles deletion

    // Disallow copying to maintain unique ownership of graphref
    Graph(const Graph&) = delete;
    Graph& operator=(const Graph&) = delete;

    // Build methods
    void startConstruction(NodeID nodes, EdgeID edges) {
        graphref->reserve(nodes);
        // edges.reserve(edges);
        // Reserve space for edges in each node's adjacency list
        for (NodeID i = 0; i < nodes; ++i) {
            (*graphref)[i].reserve(edges / nodes);
        }
    }

    NodeID addNode() {
        graphref->emplace_back(); // Add an empty adjacency list for the new node
        return graphref->size() - 1;
    }


    // for now keep track of an vector of pairs as well for the edges
    EdgeID addEdge(NodeID source, NodeID target) {
        assert(source < graphref->size());
        (*graphref)[source].push_back(target);
        edges.push_back({source, target});
        return edges.size() - 1;
    }


    // Graph access methods
    NodeID numberOfNodes() const {
        return graphref->size();
    }

    EdgeID numberOfEdges() const {
        EdgeID count = 0;
        for (const auto& neighbors : *graphref) {
            count += neighbors.size();
        }
        assert(edges.size() == count);
        return count;
    }

    EdgeID getFirstEdge(NodeID node) const {
        assert(node < graphref->size());
        return 0; // Always the first edge index
    }

    EdgeID getFirstInvalidEdge(NodeID node) const {
        assert(node < graphref->size());
        return (*graphref)[node].size();
    }

    PartitionID getPartitionCount() const {
        return m_partition_count;
    }

    void setPartitionCount(PartitionID count) {
        m_partition_count = count;
    }

    PartitionID getSeparatorBlock() const {
        return m_separator_block_ID;
    }

    void setSeparatorBlock(PartitionID id) {
        m_separator_block_ID = id;
    }

    PartitionID getPartitionIndex(NodeID node) const {
        // Placeholder, assuming partitionIndex is stored elsewhere
        return 0;
    }

    void setPartitionIndex(NodeID node, PartitionID id) {
        // Placeholder, assuming partitionIndex is stored elsewhere
    }

    PartitionID getSecondPartitionIndex(NodeID node) const {
        return m_second_partition_index[node];
    }

    void setSecondPartitionIndex(NodeID node, PartitionID id) {
        m_second_partition_index[node] = id;
    }

    void resizeSecondPartitionIndex(unsigned no_nodes) {
        m_second_partition_index.resize(no_nodes);
    }

    NodeWeight getNodeWeight(NodeID node) const {
        // Placeholder, assuming node weights are stored elsewhere
        return 1;
    }

    void setNodeWeight(NodeID node, NodeWeight weight) {
        // Placeholder, assuming node weights are stored elsewhere
    }

    EdgeWeight getNodeDegree(NodeID node) const {
        assert(node < graphref->size());
        return (*graphref)[node].size();
    }

    EdgeWeight getWeightedNodeDegree(NodeID node) const {
        EdgeWeight degree = 0;
        for (const auto& neighbor : (*graphref)[node]) {
            degree += getEdgeWeight(neighbor);
        }
        return degree;
    }

    EdgeWeight getMaxDegree() {
        if (!m_max_degree_computed) {
            computeMaxDegree();
        }
        return m_max_degree;
    }

    EdgeWeight getEdgeWeight(EdgeID edge) const {
        // Placeholder, assuming edge weights are stored elsewhere
        return 1;
    }

    void setEdgeWeight(EdgeID edge, EdgeWeight weight) {
        // Placeholder, assuming edge weights are stored elsewhere
    }

    NodeID getEdgeTarget(EdgeID edge) const {
        // Placeholder, returning the edge ID itself
        return edge;
    }

    EdgeRatingType getEdgeRating(EdgeID edge) const {
        // Placeholder, assuming edge ratings are stored elsewhere
        return 0.0;
    }

    void setEdgeRating(EdgeID edge, EdgeRatingType rating) {
        // Placeholder, assuming edge ratings are stored elsewhere
    }

    NodeWeight getContractionOffset(NodeID node) const {
        // Placeholder, assuming contraction offsets are stored elsewhere
        return 0;
    }

    void setContractionOffset(NodeID node, NodeWeight offset) {
        // Placeholder, assuming contraction offsets are stored elsewhere
    }

    int* unsafeMetisStyleXadjArray() const {
        int* xadj = new int[graphref->size() + 1];
        int index = 0;
        for (NodeID n = 0; n < graphref->size(); ++n) {
            xadj[n] = index;
            index += (*graphref)[n].size();
        }
        xadj[graphref->size()] = index;
        return xadj;
    }

    int* unsafeMetisStyleAdjncyArray() const {
        int* adjncy = new int[numberOfEdges()];
        int index = 0;
        for (const auto& neighbors : *graphref) {
            for (NodeID neighbor : neighbors) {
                adjncy[index++] = neighbor;
            }
        }
        return adjncy;
    }

    int* unsafeMetisStyleVwgtArray() const {
        int* vwgt = new int[graphref->size()];
        for (NodeID n = 0; n < graphref->size(); ++n) {
            vwgt[n] = static_cast<int>(getNodeWeight(n));
        }
        return vwgt;
    }

    int* unsafeMetisStyleAdjwgtArray() const {
        int* adjwgt = new int[numberOfEdges()];
        int index = 0;
        for (const auto& neighbors : *graphref) {
            for (NodeID neighbor : neighbors) {
                adjwgt[index++] = static_cast<int>(getEdgeWeight(neighbor));
            }
        }
        return adjwgt;
    }

    int buildFromMetis(int n, int* xadj, int* adjncy) {
        graphref->clear();
        startConstruction(n, xadj[n]);

        for (int i = 0; i < n; ++i) {
            NodeID node = addNode();
            setNodeWeight(node, 1);
            setPartitionIndex(node, 0);

            for (int e = xadj[i]; e < xadj[i + 1]; ++e) {
                EdgeID edge = addEdge(node, adjncy[e]);
                setEdgeWeight(edge, 1);
            }
        }

        return 0;
    }

    int buildFromMetisWeighted(int n, int* xadj, int* adjncy, int* vwgt, int* adjwgt) {
        graphref->clear();
        startConstruction(n, xadj[n]);

        for (int i = 0; i < n; ++i) {
            NodeID node = addNode();
            setNodeWeight(node, vwgt[i]);
            setPartitionIndex(node, 0);

            for (int e = xadj[i]; e < xadj[i + 1]; ++e) {
                EdgeID edge = addEdge(node, adjncy[e]);
                setEdgeWeight(edge, adjwgt[e]);
            }
        }

        return 0;
    }

    void copy(const Graph& other) {
        startConstruction(other.numberOfNodes(), other.numberOfEdges());
        for (NodeID node = 0; node < other.numberOfNodes(); ++node) {
            NodeID shadow_node = addNode();
            setNodeWeight(shadow_node, other.getNodeWeight(node));
            for (EdgeID e = other.getFirstEdge(node); e < other.getFirstInvalidEdge(node); ++e) {
                NodeID target = other.getEdgeTarget(e);
                EdgeID shadow_edge = addEdge(shadow_node, target);
                setEdgeWeight(shadow_edge, other.getEdgeWeight(e));
            }
        }

    }

private:
    std::shared_ptr<basicGraph> graphref;
    std::vector<edge_source_pair> edges;
    bool m_max_degree_computed;
    unsigned int m_partition_count;
    EdgeWeight m_max_degree;
    PartitionID m_separator_block_ID;
    std::vector<PartitionID> m_second_partition_index;

    void computeMaxDegree() {
        m_max_degree = 0;
        for (NodeID node = 0; node < numberOfNodes(); ++node) {
            EdgeWeight cur_degree = getNodeDegree(node);
            if (cur_degree > m_max_degree) {
                m_max_degree = cur_degree;
            }
        }
        m_max_degree_computed = true;
    }
};

#endif // GRAPHMICROSERVICE_GRAPH_SERVICE_H
