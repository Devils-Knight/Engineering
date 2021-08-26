#include<bits/stdc++.h>
using namespace std;
class Djiktras{
	int vertices;
	int edges;
	int  **gr;
	bool *present;
	int *distance;
	int *path;
public:
	void make_graph(){
		cout<<" Enter the maximum value of vertices in the graph: ";
		cin>> vertices;
		present = new bool[vertices];
		distance = new int[vertices];
		path = new int[vertices];
		for( int i=0; i< vertices; i++){
			present[i]= false;
		}
		for( int i=0; i< vertices; i++){
			path[i]= -1;
		}
		for( int i=0; i< vertices; i++){
			distance[i] = INT_MAX;
		}
		gr = new int*[vertices];
		for(int i=0; i< vertices; i++){
			gr[i]= new int[vertices];
			for(int j=0; j< vertices; j++){
				gr[i][j]= 0;
			}
		}
		// memset(gr, false, sizeof(gr));
		cout<< " Enter the number of Edges in the Graph: ";
		cin>> edges;
		for( int i=0; i< edges; i++){
			int m, n, len;
			cout<< "Enter the edge: \n";
			cin>> m >> n;
			cout<< "Enter the Edge length: \n";
			cin >> len;
			gr[m][n] = len;
			gr[n][m] = len;
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
	void Djiktras_algo(){
		cout<< "Enter the source vertices: ";
		int s, source;
		cin >> source;
		s = source;
		distance[s] = 0;
		path[s] = s;
		present[s] = true;
		for( int i= 0 ; i< vertices -1; i++){
			for( int j=0; j< vertices; j++ ){
				if( gr[s][j]){
					if( !present[j]){
						int temp =  distance[s] + gr[s][j];
						if( temp < distance[j]){
							path[j] = s;
							distance[j] = temp;
						}
					}
				}
			}
			int minn = INT_MAX;
			for (int j=0; j< vertices; j++){
				if( distance[j] < minn  &&  present[j] == false){
					s = j;
					minn = distance[j];
				}
			}
//			cout<< s << " ";
			present[s] = true;
		}
		cout<< "DISTANCE OF VARIOUS NODES FROM THE SOURCE NODE IS: \n";
		for( int i=0; i< vertices; i++){
			cout<<"\n\tDistance from "<< source << " -> " << i <<" = "<< distance[i] << "\n";
		}
		for (int i=0; i< vertices ; i++){
			int p = i;
			cout<<"\n\tPath for " << p << " is=\t ";
			do{
				cout<< p<< " <- " ;
				p= path[p];

			}while( p != source);
			cout<<source << " ";
			cout<< "\n";
		}



	}


};
int main(){
	Djiktras D;
	D.make_graph();
	D.Djiktras_algo();
}
