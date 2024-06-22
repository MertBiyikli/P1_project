#include <gtest/gtest.h>
#include "../../src/graph/graph_service.h"


TEST(GraphIntegrationTest, BuildFromMetis) {
    int n = 3;
    int xadj[] = {0, 2, 4, 6};
    int adjncy[] = {1, 2, 0, 2, 0, 1};

    Graph graph;
    graph.buildFromMetis(n, xadj, adjncy);

    EXPECT_EQ(graph.numberOfNodes(), 3);
    EXPECT_EQ(graph.numberOfEdges(), 6);
}
/*
TEST(GraphIntegrationTest, BuildFromMetisWeighted) {
    int n = 3;
    int xadj[] = {0, 2, 4, 6};
    int adjncy[] = {1, 2, 0, 2, 0, 1};
    int vwgt[] = {1, 2, 1};
    int adjwgt[] = {1, 1, 1, 1, 1, 1};

    Graph graph;
    graph.buildFromMetisWeighted(n, xadj, adjncy, vwgt, adjwgt);

    EXPECT_EQ(graph.numberOfNodes(), 3);
    EXPECT_EQ(graph.numberOfEdges(), 6);

    EXPECT_EQ(graph.getNodeWeight(0), 1);
    EXPECT_EQ(graph.getNodeWeight(1), 2);
    EXPECT_EQ(graph.getNodeWeight(2), 1);

    EXPECT_EQ(graph.getEdgeWeight(0), 1);
    EXPECT_EQ(graph.getEdgeWeight(1), 1);
    EXPECT_EQ(graph.getEdgeWeight(2), 1);
    EXPECT_EQ(graph.getEdgeWeight(3), 1);
    EXPECT_EQ(graph.getEdgeWeight(4), 1);
    EXPECT_EQ(graph.getEdgeWeight(5), 1);
}

TEST(GraphIntegrationTest, AddNodeAndEdge) {
    Graph graph;
    NodeID node0 = graph.addNode();
    NodeID node1 = graph.addNode();
    NodeID node2 = graph.addNode();

    EdgeID edge0 = graph.addEdge(node0, node1);
    EdgeID edge1 = graph.addEdge(node1, node2);
    EdgeID edge2 = graph.addEdge(node2, node0);

    EXPECT_EQ(graph.numberOfNodes(), 3);
    EXPECT_EQ(graph.numberOfEdges(), 3);

    EXPECT_EQ(graph.getNodeDegree(node0), 1);
    EXPECT_EQ(graph.getNodeDegree(node1), 2);
    EXPECT_EQ(graph.getNodeDegree(node2), 2);
}

TEST(GraphIntegrationTest, PartitionAndWeightIntegration) {
    Graph graph;
    NodeID node0 = graph.addNode();
    NodeID node1 = graph.addNode();

    graph.setPartitionIndex(node0, 1);
    graph.setPartitionIndex(node1, 2);

    EXPECT_EQ(graph.getPartitionIndex(node0), 1);
    EXPECT_EQ(graph.getPartitionIndex(node1), 2);

    graph.setNodeWeight(node0, 10);
    graph.setNodeWeight(node1, 20);

    EXPECT_EQ(graph.getNodeWeight(node0), 10);
    EXPECT_EQ(graph.getNodeWeight(node1), 20);
}
*/
