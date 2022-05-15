#include "graph.hpp"

Graph::Graph()
{
}

Graph::Graph(int size)
: size(size)
{
    this->body = new int*[size];

    for(int i = 0; i < this->size; ++i){
        this->body[i] = new int[size];
    }

}

Graph::~Graph()
{
    for(int i = 0; i < this->size; ++i){
        delete [] this->body[i];
    }

    delete [] this->body;
}
