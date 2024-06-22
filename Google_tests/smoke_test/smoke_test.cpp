#include <gtest/gtest.h>

#include "../../src/graph/graph_service.h"

TEST(GraphTest, GraphConstruction) {
Graph graph;
graph.startConstruction(3, 3);

NodeID node0 = graph.addNode();
NodeID node1 = graph.addNode();
NodeID node2 = graph.addNode();

graph.addEdge(node0, node1);
graph.addEdge(node1, node2);
graph.addEdge(node2, node0);


EXPECT_EQ(graph.numberOfNodes(), 3);
EXPECT_EQ(graph.numberOfEdges(), 3);
}

TEST(GraphTest, NodeAndEdgeCounts) {
Graph graph;
graph.startConstruction(3, 3);

graph.addNode();
graph.addNode();
graph.addNode();

graph.addEdge(0, 1);
graph.addEdge(1, 2);
graph.addEdge(2, 0);


EXPECT_EQ(graph.numberOfNodes(), 3);
EXPECT_EQ(graph.numberOfEdges(), 3);
}
