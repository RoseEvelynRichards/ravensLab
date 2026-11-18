#include <iostream>
#include <vector>


class Graph{
    private:
        std::vector<std::vector<int>> adjList;
        bool isDirected;
    public:
        Graph(int vertices, bool directed=false){
            adjList.resize(vertices);
            isDirected = directed;
        }

        void addEdge(int src, int dest){
            adjList[src].push_back(dest);
            if (!isDirected) adjList[dest].push_back(src);
        }

        void printGraph(){
            for (int i = 0; i < adjList.size(); i++){
                std::cout << i << " ";
                for (int j; i < adjList[i].size(); j++) std::cout << adjList[i][j] << " -> ";
                std::cout << "NULL";
            }
        }
};

int main(){


    std::cout << std::endl;
    return 0;
}