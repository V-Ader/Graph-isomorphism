#include <iostream>
#include "graph.hpp"

int main(){

    Graph g1 = Graph(5);
    Graph g2 = g1;

    g2.setConnection(1, 1, 2);

    g1.printGraph();

    g2.printGraph();



}