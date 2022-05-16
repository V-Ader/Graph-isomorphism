#include "graph.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

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
}

bool Graph::operator==(const Graph &g)
{
    if(this->size != g.size) return false;

    for(int i = 0; i < this->size * this->size; ++i){
        if(this->body[i] != g.getConnection(i)) return false;
    }

    return true;
}

Graph::~Graph()
{
    delete [] this->body;
}
