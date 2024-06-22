#include "../src/graph/graph_service.h"
// #include "../src/db/db_operations.hpp"

int main() {
    // Create a graph_access object
    Graph graph;

    // Start constructing a graph with 3 nodes and 3 edges
    graph.startConstruction(3, 3);

    // Add nodes to the graph
    NodeID node0 = graph.addNode();  // Node 0
    NodeID node1 = graph.addNode();  // Node 1
    NodeID node2 = graph.addNode();  // Node 2

    // Add edges to the graph
    std::cout << graph.addEdge(node0, node1) << std::endl; // Edge from Node 0 to Node 1
    std::cout << graph.addEdge(node1, node2) << std::endl; // Edge from Node 1 to Node 2
    std::cout << graph.addEdge(node2, node0) << std::endl; // Edge from Node 2 to Node 0


    // Output the number of nodes and edges in the graph
    std::cout << "Number of nodes: " << graph.numberOfNodes() << std::endl;
    std::cout << "Number of edges: " << graph.numberOfEdges() << std::endl;

    // Output the edges
    for (NodeID n = 0; n < graph.numberOfNodes(); ++n) {
        std::cout << "Node " << n << " has edges to: ";
        for (EdgeID e = graph.getFirstEdge(n); e < graph.getFirstInvalidEdge(n); ++e) {
            std::cout << graph.getEdgeTarget(e) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
