#include<bits/stdc++.h>
using namespace std;
class node{
	int parent;
	int Rank;
	int value;

public:
	node(){
		Rank = 0;
		parent = -1;
	}
	void set_rank(int val){
		Rank = val;
	}
	int get_rank(){
		return Rank;
	}
	void set_parent(int var){
		parent = var;
	}
	int get_parent(){
		return parent;
	}
	void set_value(int v){
		value = v;
	}
	int get_value(){
		return value;
	}
};

class graph{
	priority_queue<int,vector<int>, greater<int>> pq;
	multimap<int, pair<int, int>> mp, ans;
	int  no_of_vertices;
	int Total_cost;
public:
	vector<node> parent;
	void insert_edges(){
//		cout<< "\n Enter the no. of nodes: ";cin>> no_of_node;
		cout<< "\n Enter the no. of vertices: ";
		cin>> no_of_vertices;
		for(int i=0; i<= no_of_vertices; i++){
			node a;
//			a.set_parent(-1);
//			a.set_rank(0);
			a.set_value(i);
			parent.push_back(a);
		}
		int x, y;
		int len;
		char ch='y';
		while(ch == 'y'){
			cout<< "\n Enter the Edge: ";
			cin>> x >> y;
			cout<< "\n Enter the Edge length: ";
			cin>> len;
			mp.insert({len, make_pair(x, y)});
			pq.push(len);
			cout<<" \n Do you want to add more edges:(y, Y) ";
			cin>> ch ;

		}
	}
	void show_mp(){
		cout<< "\n";
		for(auto x: mp){
			cout<< "weight: "<< x.first <<  " "<< " Edge is between: "<<x.second.first<< " "<<x.second.second<< endl;
		}
		cout<< "\n";
	}

	void show_ans(){
		cout<< "\n";
		for(auto x: ans){
			cout<< "weight: "<< x.first <<  " "<< " Edge is between: "<<x.second.first<< " "<<x.second.second<< endl;
		}
		cout<< "\n";
	}
	void show_pq(){
		cout<< endl;
		cout<< "\n Priority Queue: ";
		while(pq.size()!=0 ){
			cout<< pq.top()<< " ";
			pq.pop();
		}

	}
	int find_parent(node n){
		if(n.get_parent() == -1)return n.get_value();
		else{
			n.set_parent(find_parent(parent[n.get_parent()]));
			return n.get_parent();
		}
	}
	void kruskal_algorithm(){
		multimap<int, pair<int, int>>::iterator itr;
		itr= mp.begin();
		int i=0;
		while(i < no_of_vertices -1 && itr!= mp.end()){
			int first= itr->first;
			int second = itr->second.first;
			int third = itr->second.second;
			cout<<" first " <<first<< " second " << second<<" third "<< third<< endl;
			int parent1 = find_parent(parent[second]);
			int parent2 = find_parent(parent[third]);
			if(parent2  ==  parent1 ){
				itr++;
				continue;
			}
			else{
				ans.insert({first, {second, third}});
				if(parent[parent1].get_rank() >= parent[parent2].get_rank() )
				parent[parent2].set_parent(parent[parent1].get_value());
				else {
					parent[parent1].set_parent(parent[parent2].get_value());
				}
			}
			i++;
			itr++;
		}
		if(ans.size() != no_of_vertices -1){
			cout<< "\nMinimum Spanning Tree is not possible for this for the current graph\n";
			return ;
		}
		this->show_ans();
	}


};
int main(){
	graph g;
	g.insert_edges();
//	g.show_mp();
	g.kruskal_algorithm();
}
