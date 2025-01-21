#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int info;
	Node*next;
	Node():next(nullptr){}
	Node(int inf, Node*n):info(inf), next(n){}
};

struct Graph{
	Node adjencyLinked[10];
	Graph(){
		for(int i = 0; i < 10; i++){
			adjencyLinked[i].info = i+1;
		}
	}
	
};
void view(Graph &t){
	for(auto x : t.adjencyLinked){
		cout<<x.info<<endl;
	}
}
// create adjency 
void addEdge(vector<vector<int>>& adj, int u, int v){
	// u and v is node
	// it's really help with optimise memory, easy add or 
	// delete edge
	adj[u].push_back(v); // edge u-v
	adj[v].push_back(u); // edge v-u
	
}
// but it really difficut when u want to access
// quickly between 2 edege is neighbours or not?
void printGraph(const vector<vector<int>>& adj) {
	for(int i = 0; i < adj.size();i++){
		cout<<"Dinh "<<i<<": ";
		for(auto v : adj[i]){
			cout<<v<<" ";
		}
		cout<<endl;
	}
}

int main(){
	//Graph graph;
	//view(graph);
	int V = 5;
	vector<vector<int>> adj(V);
	addEdge(adj,0, 1);
	addEdge(adj,0, 4);
	addEdge(adj,1, 2);
	addEdge(adj,1, 3);
	addEdge(adj,1, 4);
	addEdge(adj,2, 3);
	addEdge(adj,3, 3);
	printGraph(adj);
	return 0;
}
