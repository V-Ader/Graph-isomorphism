#pragma once

class Graph
{
private:
    int size;
    int* body;
    int threads_avaible;

public:
    Graph();
    Graph(int size, int threads_avaible, bool setRandom=true);
    Graph(const Graph &g);

    void printGraph();

    int getConnection(int n, int m) const { return this->body[n*this->size + m]; }    
    int getConnection(int k) const { return this->body[k]; }

    int getSize() const { return this->size; }

    void setConnection(int n, int m, int val) { this->body[n*this->size + m] = val; }

    bool operator==(const Graph& g);
    bool isIsomorfic(Graph& g);
    bool isIsomorficParallel(Graph& g);


    ~Graph();


};
