#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
struct Node {

    int data;
    Node *Left;
    Node *right;
    bool LeftThread;
    bool rightThread;
};

class Threaded_Binary_Tree{
public:

    Node* insert(Node *root,int k){
        Node *x = root;
        Node *y = NULL;

        while(x != NULL){
            if(x->data == k){
                cout<<"Already Present."<<endl;
                return root;
            }
            y = x;
            if(x->data >k ){
                if(x->LeftThread == false){
                    x = x->Left;
                }else{
                    break;
                }
            }else{
                if(x->rightThread == false){
                    x = x->right;
                }else{
                    break;
                }
            }
        }

        Node *temp = new Node();
        temp->data = k;
        temp->LeftThread = temp->rightThread = true;

        if(x == NULL){
            root = temp;
            root->Left = root->right = NULL;
        }else if(y->data > k){
            temp->right = y;
            temp->Left = y->Left;
            y->LeftThread = false;
            y->Left = temp;
        }else{
            temp ->Left = y;
            temp->right = y->right;
            y->right = temp;
            y->rightThread = false;
        }
        return root;
    }

    Node *In_order_Successor(Node *x){

        if(x->rightThread == true){
            return x->right;
        }
        x = x->right;
        while(x->LeftThread == false){
            x = x->Left;
        }
        return x;
    }

    Node *In_order_Traversal(Node *root){

        if(root == NULL){
            cout<<"Empty Tree"<<endl;
            return root;
        }

        Node *x = root;
        while(x->LeftThread == false){
            x = x->Left;
        }
        while(x){
            cout<<x->data<<" ";
            x = In_order_Successor(x);
        }
        return root;

    }

    Node *preorderSuccessor(Node *temp){

        if(temp->rightThread){

            return temp->right;
        }
        temp = temp->right;
        cout<<temp->data<<" ";

        while(temp->LeftThread == false){

            temp = temp->Left;
            cout<<temp->data<<" ";
        }
        return temp;
    }

    Node *preorder(Node *root){

        if(root == NULL){

            cout<<"Empty Tree."<<endl;
            return root;
        }
        Node *x = root;
        cout<<x->data<<" ";

        while(x->LeftThread == false){
            x = x->Left;
            cout<<x->data<<" ";

        }

        while(x != NULL){
            x = preorderSuccessor(x);
        }
        return root;
    }

};


int main()
{
    Threaded_Binary_Tree t;
    Node *root = NULL;
    int c = -1;
    do{
        cout<<"Enter Choice \n";
        cout<<"1. Insert an Element."<<endl;
        cout<<"2. In-order Traversal"<<endl;
        cout<<"3. Pre-order Traversal"<<endl;
        cout<<"-1. Exit"<<endl;

        cin>>c;

        switch(c){
        case 1:

            cout<<"Enter Value to be inserted. ";
            int a;
            cin>>a;
            root = t.insert(root,a);
            break;

        case 2:

            cout<<"Inorder Traversal =  ";
            root = t.In_order_Traversal(root);
            cout<<endl;
            break;

        case 3:

            cout<<"Post Order Traversal =  "<<endl;
            root=t.preorder(root);
            cout<<endl;
            break;
        default :
            cout<<"Wrong Choice .. :(\n";

        }
    }while(c != -1);

    return 0;
}
