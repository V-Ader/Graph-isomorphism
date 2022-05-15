#pragma once

class Graph
{
private:
    int size;
    int** body;

public:
    Graph();
    Graph(int);

    int getConnection(int n, int m) const { return this->body[n][m]; }
    int getSize() const { return this->size; }

    void setConnection(int n, int m, int val) { this->body[n][m] = val; }


    ~Graph();


};
