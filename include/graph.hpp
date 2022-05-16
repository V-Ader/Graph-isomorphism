#pragma once

class Graph
{
private:
    int size;
    int* body;

public:
    Graph();
    Graph(int size, bool setRandom=true);
    Graph(const Graph &g);

    void printGraph();

    int getConnection(int n, int m) const { return this->body[n*this->size + m]; }    
    int getConnection(int k) const { return this->body[k]; }

    int getSize() const { return this->size; }

    void setConnection(int n, int m, int val) { this->body[n*this->size + m] = val; }

    bool operator==(const Graph& g);


    ~Graph();


};
