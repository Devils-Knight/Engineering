#include <bits/stdc++.h>
using namespace std;

//Printing in DFS order
void print(int n,int ** graph,int st, bool * visited){
  cout<<st<<endl;
  visited[st]=true;
  for(int i=0;i<n;i++){
    if(graph[st][i]==1){
      if(!visited[i])print(n,graph,i,visited);
    }
  }
}


// printing in bfs order
void print_bfs_helper(int n,int ** graph, queue<int>& q, bool * visited){
  if(q.empty())return;
  int head= q.front();
  cout<<head<<endl;
  q.pop();
  for(int i=0;i<n;i++){
    if(graph[head][i]==1){
      if(!visited[i]){
        q.push(i);
        visited[i]=true;
      }
    }
  }
  print_bfs_helper(n,graph,q,visited);

}

void print_bfs(int n,int ** graph, int st, bool * visited){
  queue<int> nodes;
  nodes.push(st);
  visited[st]=true;
  return print_bfs_helper(n, graph, nodes, visited);
}

// TEST case
// 8 10
// 0 1
// 0 2
// 0 3
// 1 4
// 2 4
// 2 5
// 3 6
// 4 7
// 5 7
// 6 7
