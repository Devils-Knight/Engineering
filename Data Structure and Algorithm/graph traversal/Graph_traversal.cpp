#include<bits/stdc++.h>
using namespace std;

class Graph{
	int vertices;
	int edges;
	bool **gr;
public:
	void make_graph(){
		cout<<" Enter the maximum value of vertices in the graph: ";
		cin>> vertices;
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
			cout<< "Enter the edge: ";
			cin>> m>> n;
			m--, n--;
			gr[m][n]= true;
			gr[n][m] = true;

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



	void bfs(){
//		loop for first vertex in the graph
		int first=-1;
		bool flag= true;
		for(int i=0; i< vertices; i++){
			flag =true;
			for(int j=0; j< vertices; j++){
				if(gr[i][j]){
					first= i;
					flag =false;
					break;
				}
			}
			if(!flag)break;
		}
		queue<int> q;
		vector<bool>ispresent(vertices, false);
		q.push(first);
		ispresent[first]= true;
		cout<< "\nBFS TRAVERSAL--> ";
		while(q.size() != 0){
			int element= q.front();
			q.pop();
			cout<< element+1<< " ";
			for(int i=0; i< vertices; i++){
				if(gr[element][i] && ispresent[i] == false){
					q.push(i);
					ispresent[i] = true;
				}
			}

		}
	}
	void dfs_traversal(int element, vector<bool>&is_traversed){
//		static vector<bool>is_traversed(vertices, false);
		if(is_traversed[element] == true){
			return ;
		}
		cout<< element+1<<" ";
		is_traversed[element]= true;
		for(int i=0; i< vertices; i++){
			if(gr[element][i] && is_traversed[i] == false){
//				cout<< i+1<<" ";
				dfs_traversal(i, is_traversed);
			}
		}

	}
	void DFS(){
		int first=-1;
		bool flag= true;
		for(int i=0; i< vertices; i++){
			flag =true;
			for(int j=0; j< vertices; j++){
				if(gr[i][j]){
					first= i;
					flag =false;
					break;
				}
			}
			if(!flag)break;
		}
		if(first !=-1){
			vector<bool>traversed(vertices, false);
//			cout<<"first "<<first<< endl;
			cout<< "\nDFS TRAVERSAL--> ";
			dfs_traversal(first, traversed);
		}

	}
	void connected_component(){
		int first=-1;
		bool flag= true;
		for(int i=0; i< vertices; i++){
			flag =true;
			for(int j=0; j< vertices; j++){
				if(gr[i][j]){
					first= i;
					flag =false;
					break;
				}
			}
			if(!flag)break;
		}
		int counter= 0;
		vector<bool>check(vertices, false);
		int i=0;
		while(i < vertices){
			if(check[i] == false){
				cout<<endl;
				counter++;
				queue<int> q;
				q.push(i);
				check[i]= true;
				cout<< "\nBFS TRAVERSAL--> "<<counter<<"---> ";
				while(q.size() != 0){
					int element= q.front();
					q.pop();
					cout<< element+1<< " ";
					for(int i=0; i< vertices; i++){
						if(gr[element][i] && check[i] == false){
							q.push(i);
							check[i] = true;
						}
					}

				}
			}
			else{
				i++;
				continue;
			}
		}
		cout<<"\nNo. Of connected Component "<<counter<<"\n";
	}

};
int choice(){
	int chh;
	cout<<"\n";
	cout<<"\t 1-> for showing Graph: \n";
	cout<<"\t 2-> for Breadth first search Traversal: \n";
	cout<<"\t 3-> for Depth first search Traversal: \n";
	cout<<"\t 4-> for connected Graph: \n";
	cout<<"\n\t Enter your choice: ";
	cin>> chh;
	return chh;
}
int main(){
	Graph G;
	G.make_graph();
	int  ch =choice();
	while(ch >=1  && ch <= 4){
		if(ch == 1)G.show_graph();
		else if(ch == 2)G.bfs();
		else if(ch == 3)G.DFS();
		else G.connected_component();
		ch= choice();

	}


}




