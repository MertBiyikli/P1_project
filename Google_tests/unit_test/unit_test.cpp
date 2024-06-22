#include <gtest/gtest.h>
#include "../../src/graph/graph_service.h"


TEST(GraphTest, AddNodes) {
    Graph graph;
    graph.startConstruction(3, 3);

    NodeID node0 = graph.addNode();
    NodeID node1 = graph.addNode();
    NodeID node2 = graph.addNode();

    EXPECT_EQ(node0, 0);
    EXPECT_EQ(node1, 1);
    EXPECT_EQ(node2, 2);
}

TEST(GraphTest, AddEdges) {
    Graph graph;
    graph.startConstruction(3, 3);

    NodeID node0 = graph.addNode();
    NodeID node1 = graph.addNode();
    NodeID node2 = graph.addNode();

    EdgeID edge0 = graph.addEdge(node0, node1);
    EdgeID edge1 = graph.addEdge(node1, node2);
    EdgeID edge2 = graph.addEdge(node2, node0);

    EXPECT_EQ(edge0, 0);
    EXPECT_EQ(edge1, 1);
    EXPECT_EQ(edge2, 2);
}

TEST(GraphTest, GetFirstAndInvalidEdges) {
    Graph graph;
    graph.startConstruction(3, 3);

    graph.addNode();
    graph.addNode();
    graph.addNode();

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);


    EXPECT_EQ(graph.getFirstEdge(0), 0);
    EXPECT_EQ(graph.getFirstInvalidEdge(0), 1);
}
/*
TEST(GraphTest, NodeWeights) {
    Graph graph;
    graph.startConstruction(3, 3);

    NodeID node0 = graph.addNode();
    NodeID node1 = graph.addNode();
    NodeID node2 = graph.addNode();

    graph.setNodeWeight(node0, 5);
    graph.setNodeWeight(node1, 3);
    graph.setNodeWeight(node2, 7);

    EXPECT_EQ(graph.getNodeWeight(node0), 5);
    EXPECT_EQ(graph.getNodeWeight(node1), 3);
    EXPECT_EQ(graph.getNodeWeight(node2), 7);
}

TEST(GraphTest, EdgeWeights) {
    Graph graph;
    graph.startConstruction(3, 3);

    NodeID node0 = graph.addNode();
    NodeID node1 = graph.addNode();
    NodeID node2 = graph.addNode();

    EdgeID edge0 = graph.addEdge(node0, node1);
    EdgeID edge1 = graph.addEdge(node1, node2);
    EdgeID edge2 = graph.addEdge(node2, node0);

    graph.setEdgeWeight(edge0, 10);
    graph.setEdgeWeight(edge1, 20);
    graph.setEdgeWeight(edge2, 30);

    EXPECT_EQ(graph.getEdgeWeight(edge0), 10);
    EXPECT_EQ(graph.getEdgeWeight(edge1), 20);
    EXPECT_EQ(graph.getEdgeWeight(edge2), 30);
}

TEST(GraphTest, Partitioning) {
    Graph graph;
    graph.startConstruction(3, 3);

    NodeID node0 = graph.addNode();
    NodeID node1 = graph.addNode();
    NodeID node2 = graph.addNode();

    graph.addEdge(node0, node1);
    graph.addEdge(node1, node2);
    graph.addEdge(node2, node0);


    graph.setPartitionIndex(node0, 1);
    graph.setPartitionIndex(node1, 2);
    graph.setPartitionIndex(node2, 3);

    EXPECT_EQ(graph.getPartitionIndex(node0), 1);
    EXPECT_EQ(graph.getPartitionIndex(node1), 2);
    EXPECT_EQ(graph.getPartitionIndex(node2), 3);
}
*/
TEST(GraphTest, MaxDegree) {
    Graph graph;
    graph.startConstruction(3, 3);

    NodeID node0 = graph.addNode();
    NodeID node1 = graph.addNode();
    NodeID node2 = graph.addNode();

    graph.addEdge(node0, node1);
    graph.addEdge(node1, node2);
    graph.addEdge(node2, node0);

    EXPECT_EQ(graph.getMaxDegree(), 1);
}
