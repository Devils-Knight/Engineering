#include<bits/stdc++.h>
using namespace std;
class Topological_sort{
	int vertices;
	int edges;
	bool **gr;
	queue<int> Q;
	int *incoming;
	bool *present;
public:
	void make_graph(){
		cout<<" Enter the maximum value of vertices in the graph: ";
		cin>> vertices;
		incoming = new int[vertices];
		present = new bool[vertices];
		for( int i=0; i< vertices; i++){
			incoming[i]= 0;
		}
		for( int i=0; i< vertices; i++){
			present[i]= false;
		}
		gr = new bool*[vertices];
		for(int i=0; i< vertices; i++){
			gr[i]= new bool[vertices];
			for(int j=0; j< vertices; j++){
				gr[i][j]= false;
			}
		}
		// memset(gr, false, sizeof(gr));
		cout<< " Enter the number of Edges in the Graph: ";
		cin>> edges;
		for( int i=0; i< edges; i++){
			int m, n;
			cout<< "Enter the edge: \n";
			cout<< "From : ";
			cin>> m;
			cout<< "To: ";
			cin>> n;
			present[m]= true;
			present[n] = true;
//			m--, n--;
			gr[m][n]= true;

		}
	}
	void show_graph(){
		for(int i=0; i< vertices; i++){
			for(int j=0; j< vertices; j++){
				cout<< gr[i][j]<< " ";
			}
			cout<< "\n";
		}
	}

	int get_vertices(){
		return vertices;
	}
	void algo(){
		for( int i=0; i< vertices; i++){
			for( int j=0; j< vertices; j++){
				if(gr[i][j] ){
					incoming[j]++;
				}
			}
		}
		for( int i=0; i< vertices; i++){
			if(!incoming[i] ) {
				Q.push(i);
			}
		}
		if(Q.size() == 0){
			cout<< "\n\t----Graph is Cyclic-----\n";
			return;
		}
		cout<< "\n\tTOPOLOGICAL SORT -> ";
		while( Q.size()){
			int ele = Q.front();
			Q.pop();
			if(present[ele])
			cout<< ele<< " ";
			for( int i=0; i< vertices; i++){
				if(gr[ele][i]){
					incoming[i]--;
					if( !incoming[i]){
						Q.push(i);
					}
				}
			}
		}
	}


};
int main(){
	Topological_sort T;
	T.make_graph();
	T.algo();
}

