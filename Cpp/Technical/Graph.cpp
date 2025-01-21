#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

// learn graph theory

// Adjacency Matrix = A 2D array to store 1's/0's to represents edge
// runtime complexity to check an Edge: O(1)
// space complexity: O(v^2);


class Node{
    char data;
    public:
    Node(char data) : data(data) {}
    Node() : data(char()) {}
    char getData(){
        return data;
    }
};

class Graph{
    
    vector<vector<int>> matrix;
    int n;
    public:
    vector<Node> nodes;
    Graph(int size){
        matrix.resize(size, vector<int>(size, 0));
    }
    Graph(){
        matrix.resize(0, vector<int>(0, 0));
    }
    void addNode(Node node){
        nodes.push_back(node);
    }
    // void addNode(Node *node){
    //     nodes.push_back(node);
    // }
    void addEdege(int src, int dst){
        matrix[src][dst] = 1;
    }
    bool checkEdge(int src, int dst){
        return matrix[src][dst] == 1;
    }
    void print(){
        cout<<"  ";
        for(Node node: nodes){
            cout<<node.getData()<<" ";
        }
        cout<<endl;
        for(int i = 0; i < matrix.size(); i++){
            cout<<nodes[i].getData()<<" ";
            for(int j = 0; j < matrix[i].size(); j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    // deapth first search with visited
    void dFSHelper(int src, vector<bool>& visited){
        if(visited[src]){
            return;
        }
        visited[src] = true;
        cout<<nodes[src].getData()<<" = Visited"<<endl;
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[src][i]){
                dFSHelper(i, visited);
            }
        }
        return;
    }
    void deapthFirstSearch(int src){
        vector<bool> visited(matrix.size(), false);
        dFSHelper(src, visited);
    }
    void input()
    {
        cin>>n;
        matrix.resize(n, vector<int>(n, 0));
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                cin >> matrix[i][j];
            }
        }
    }
    // use stack with dfs
    void dfs(int src){
        vector<bool> visited(matrix.size(), false);
        stack<int> s;
        s.push(src);
        while(!s.empty()){
            int curr = s.top();
            s.pop();
            if(!visited[curr]){
                visited[curr] = true;
                cout<<nodes[curr].getData()<<" is visited"<<endl;
                for(int i = matrix.size()-1; i>= 0; i--){
                    if(matrix[curr][i] &&!visited[i]){
                        s.push(i);
                    }
                }
            }
        }
    }    


    /*  different between dfs and bfs

        Breadth FS = Traverse a graph level by level
        Utilizes a queue
        better if destination is on average close to start

        Depth FS = Traverse a graph branch by branch
        Utilizes a stack
        better if destination is on average far from the start

    */



    // breadth first search
    void breadthFirstSearch(int src){
        queue<int> que;
        vector<bool> visited(matrix.size(), false);
        que.push(src);
        visited[src] = true;
        while(!que.empty()){
            src = que.front();
            que.pop();
            cout<<nodes[src].getData()<<" = visited"<<endl;
            for(int i = 0; i < matrix[src].size(); i++){
                if(matrix[src][i] == 1 && !visited[i]){
                    que.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};

int main(){
    Graph graph;
    graph.input();
    graph.deapthFirstSearch(0);
    
    // graph.deapthFirstSearch(2);
    // cout<<"__________________________________"<<endl;
    // // graph.breadthFirstSearch(4);
    // graph.breadthFirstSearch(4);
}   