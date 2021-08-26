#include<bits/stdc++.h>
using namespace std;
class graph{
private:
	int no_of_vertices;
	int **gr;
	int *parent;
	int *distance;
	bool *present;
public:
	void build_graph(){
		cout<< "\tEnter the number of vertices:\t";
		cin>> no_of_vertices;

		gr = new int*[no_of_vertices];
		for( int i=0; i< no_of_vertices; i++){
			gr[i] = new int[no_of_vertices];
			for( int j=0; j< no_of_vertices; j++){
				gr[i][j] = 0;
			}
		}
		char choice = 'y';
		while( choice == 'y' || choice == 'Y'){
			cout<<"\tEnter the Edge: ";
			int a, b;
			cin>> a>> b;
			cout<< "\n\t Enter the Weight between the Edge:  ";
			int weight;
			cin>> weight;
			gr[a][b] = weight;
			gr[b][a] = weight;

			cout<< "\t Do you want to Continue:(y or Y for continue) \t";
			cin>> choice;

		}
	}
	void prims_algorithm(){
		parent = new int[no_of_vertices];
		distance = new int[no_of_vertices];
		present = new bool[no_of_vertices];

		for( int i=0; i< no_of_vertices; i++)parent[i]=-1;	/// no one have their parent yet
		for( int i=0; i< no_of_vertices; i++)present[i]=false; /// no one is present in the MST yet
		distance[0] = 0;					/// Distance for the initial node is zero (for choosing the minimum distance for the first time)
		for(int i=1; i< no_of_vertices; i++){
			distance[i] = INT_MAX;
		}

		int curr_node = 0;
		present[curr_node] = true;
		while(true){
			bool flag  = true;
			for (int i = 0; i< no_of_vertices ;  i++){
				if( gr[curr_node][i] && curr_node != i){
					if( distance[i] > gr[curr_node][i] && present[i] == false){
						distance[i] = gr[curr_node][i];
						parent[i] = curr_node;
					}
				}
			}
			present[curr_node ] = true;
			int minn = INT_MAX;
			for( int i=0; i< no_of_vertices; i++){
				if( present[i] == false && distance[i] < minn){
					curr_node = i;
					minn = distance[i];
					flag  = false;
				}
			}

			if( flag == true)break;
		}
		bool mst = true;
		for( int i=0; i< no_of_vertices; i++){
			if(present[i] == false)mst = false;
		}
		if( mst){
			cout<< "\n\n";
			int cost = 0;
			for( int i=1; i< no_of_vertices ; i++){
				cost+= distance[i];
				cout<< "\tEdge is Between : "<< i<< " and "<< parent[i] << "\t Weight is : "<< distance[i]<< " \n";

			}
			cout<< "\n\t TOTAL COST = "<< cost << "\n";

		}
		else{
			cout<< "\n\t------MST IS NOT POSSIBLE FOR THE CURRENT GRAPH-------\n";
		}
	}
};

int main(){
	graph gr;
	gr.build_graph();
	gr.prims_algorithm();
}
