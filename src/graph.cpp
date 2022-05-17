#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "graph.hpp"
#include "utils.hpp"


Graph::Graph()
{
}

Graph::Graph(int size, bool setRandom)
: size(size)
{
    srand(time(NULL));
    this->body = new int[size*size];

    if(setRandom){
        for(int i = 0; i < this->size * this->size; ++i){
            if(rand() % 10 < 5)
                this->body[i] = 1;
            else
                this->body[i] = 0;
        }
    }
    else{
        for(int i = 0; i < this->size * this->size; ++i){
            this->body[i] = 0;
        }
    }

}

Graph::Graph(const Graph &g){
    this->size = g.size;
    this->body = new int[this->size*this->size];

    for(int i = 0; i < this->size * this->size; ++i){
        this->body[i] = g.getConnection(i);
    }
}

void Graph::printGraph()
{
    for(int i = 0; i < (this->size * this->size); ++i){
        if(i % this->size == 0)
            std::cout << std::endl;
        
        std::cout << this->body[i] << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;
}

bool Graph::operator==(const Graph &g)
{
    if(this->size != g.size) return false;

    for(int i = 0; i < this->size * this->size; ++i){
        if(this->body[i] != g.getConnection(i)) return false;
    }

    return true;
}

bool Graph::isIsomorfic(Graph& g) {
    std::vector<int> ids;
    std::vector<int> permutation;

    for(int i = 0; i < g.getSize(); ++i){
        ids.push_back(i);
    }

    bool isomorfism = false;

    for(int k = 0; k < fatorial(ids.size()); ++k){
        permutation = nth_permutation(ids, k);

        Graph g3 = g;

        for(int i = 0; i < g.getSize(); ++i){
            for(int j = 0; j < g.getSize(); ++j){
                g3.setConnection(permutation.at(i), permutation.at(j), g.getConnection(i, j));
   
            }
        }

        if( g3 == *this ){
            isomorfism = true;
        }
    }

    return isomorfism;
}

bool Graph::isIsomorficParallel(Graph& g) {


    bool isomorfism = false;
    std::vector<int> ids;

    for(int i = 0; i < g.getSize(); ++i){
        ids.push_back(i);
    }

    #pragma omp parallel num_threads(8)
    { 
    std::vector<int> permutation;

    #pragma omp for
    for(int k = 0; k < fatorial(ids.size()); ++k){
        permutation = nth_permutation(ids, k);

        Graph g3 = g;

        for(int i = 0; i < g.getSize(); ++i){
            for(int j = 0; j < g.getSize(); ++j){
                g3.setConnection(permutation.at(i), permutation.at(j), g.getConnection(i, j));
   
            }
        }

        if( g3 == *this ){
            isomorfism = true;
        }
    }
    }

    return isomorfism;
}

Graph::~Graph()
{
    delete [] this->body;
}
