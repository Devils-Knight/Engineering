#include<bits/stdc++.h>
using namespace std;
class node{
    int data;
public:
    node* left;
    node* right;
    node(int a){
        this->data = a;
        this->left = nullptr;
        this->right = nullptr;
    }
    int get_data(){
        return this->data;
    }
};
class OBST{
    int no_nodes;
    int **weight;
    int **cost;
    int **root;
    int *keys;
    int *suc;
    int *unsuc;
    public:
    node* head;
    OBST(){
        this->head = nullptr;
    }
    void input(){
        cout<< " Enter The No of Nodes: ";
        cin>> no_nodes;
        keys = new int[no_nodes + 1];
        cout<< " Enter Values of "<< no_nodes << " Nodes: ";
        keys[0] = 0;
        for( int i=1; i<=no_nodes ;i++){
            cin>> keys[i];
        }
        cout<< "\n Enter the array for the Successful probability: ";
        suc = new int[no_nodes + 1];
        suc[0] = 0;
        for( int i=1; i<= no_nodes ;i++){
            cin>> suc[i];
        }
        cout<< "\n Enter the array for the Unsuccessful probability: ";
        unsuc = new int[no_nodes + 1];
        for( int i=0; i<= no_nodes ; i++){
            cin>> unsuc[i];
        }
        weight = new int*[no_nodes +1];
        for( int i=0; i<= no_nodes; i++){
            weight[i] = new int[no_nodes +1];
        }
        cost = new int*[no_nodes +1];
        for( int i=0; i<= no_nodes; i++){
            cost[i] = new int[no_nodes +1];
        }
        root = new int*[no_nodes +1];
        for( int i=0; i<= no_nodes; i++){
            root[i] = new int[no_nodes +1];
        }
///        cout<< " Exiting from the input()\n";
    }
    void build(){
//        weight[0][0] = unsuc[0];
        for( int i=0; i<= no_nodes ;  i++){
            for( int j = i; j<= no_nodes; j++){
                if( i == j)weight[i][j] = unsuc[i];
                else weight[i][j] = weight[i][j-1] + suc[j] + unsuc[j];
            }
        }
        for( int i =0; i<= no_nodes; i++ ){
            for( int j=0; j + i <= no_nodes; j++){
                if( !i){
                    cost[j][j + i] = 0;
                    root[j][j] = 0;

                }
                else {
                    int index = -1;
                    int minn = INT_MAX;
                    for( int k = j + 1; k<= j+ i; k++){
                        if( cost[j][k-1] + cost[k][j + i] + weight[j][j+i] < minn){
                            index = k;
                            minn = cost[j][k-1] + cost[k ][j + i] +  weight[j][j+i];

                        }
                    }
                    cost[j][ j+ i] = minn;
                    root[j][j + i] = index;
                }

            }
        }

        cout<< "\nWEIGHT MATRIX: \n";
        for( int i=0; i<= no_nodes; i++){
                cout<< "\t";
            for( int j=0; j<= no_nodes; j++){
                cout<< weight[i][j]<< " ";
            }cout<< endl;
        }cout<< endl;
        cout<< "\nCOST MATRIX: \n";

        for( int i=0; i<= no_nodes; i++){
            cout<< "\t";
            for( int j=0; j<= no_nodes; j++){
                cout<< cost[i][j]<< " ";
            }cout<< endl;
        }cout<< endl;
        cout<< "\nROOT MATRIX: \n";

        for( int i=0; i<= no_nodes; i++){
            cout<< "\t";
            for( int j=0; j<= no_nodes; j++){
                cout<< root[i][j]<< " ";
            }cout<< endl;
        }
        node* newnode= new node(keys[root[0][no_nodes]]);
        this->head = newnode;
        newnode->left = build_tree(0, root[0][no_nodes] - 1);       ///  building tree from i to k -1  (for left side)
        newnode->right = build_tree( root[0][no_nodes] , no_nodes);  /// building tree from k to j  (for right tree)
    }
    node* build_tree(int first, int last){
        if( first >= last)return nullptr;
        node* newnode = new node(keys[root[first][last]]);
        newnode->left = build_tree(first , root[first][last] - 1);  /// for left subtree ( i to k -1)
        newnode->right = build_tree(root[first][last] , last);      /// for right subtree ( k to j)
        return newnode;
    }
    void inorder(node* h){
        if( h == nullptr){
            return;
        }
        inorder(h->left);
        cout<< h->get_data() << " ";
        inorder(h->right);
    }
};
int main(){
    OBST obj;
    obj.input();
    obj.build();
    obj.inorder(obj.head);

}


/**
case 1
4
10 20 30 40
3 3 1 1
2 3 1 1 1


case 2
6
13 24 45 66 78 88
10 3 9 2 0 10
5 6 4 4 3 8 0

**/