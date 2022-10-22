#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

template<typename T>
class treenode{
    public:
    T data;
    treenode<T>* left;
    treenode<T>* right;
    treenode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }

    ~treenode(){
        delete this->left;
        delete this->right;
    }
};

template<typename V>
class Binary_tree{
    // treenode<int>* root;

    public:

    void printtree(treenode<V>* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<": ";
        if(root->left){
            cout<<" L->"<<root->left->data<<" ";
        }
        if(root->right){
            cout<<" R->"<<root->right->data<<" ";
        }
        cout<<endl;
        printtree(root->left);
        printtree(root->right);

    }

    treenode<V>* const_from_in_and_pre(vector<int> preorder,vector<int> inorder,int pre_start,int pre_end,int in_start,int in_end){
        if(pre_start>pre_end || in_start>in_end)
            return NULL;
        int root_data=preorder[pre_start];
        treenode<V>* root=new treenode<V>(root_data);
        int root_index;
        for(int i=in_start;i<in_end+1;i++){
            if(root_data==inorder[i]){
                root_index=i;
                break;
            }
        }
        root->left=const_from_in_and_pre(preorder,inorder,pre_start+1,pre_start+(root_index-in_start),in_start,root_index-1);
        root->right=const_from_in_and_pre(preorder,inorder,pre_start+(root_index-in_start)+1,pre_end,root_index+1,in_end);
        // cout<<"inside func"<<endl;
        // printtree(root);
        return root;
    }

    void levelorder(treenode<V>* head){
        queue<treenode<V>*> q;
        q.push(head);
        q.push(NULL);
        cout<<"Level Order Traversal:"<<endl;
        int level=1;
        cout<<level<<".) ";
        while(true){
            treenode<V>* temp=q.front();
            if(temp==NULL){
                cout<<endl;
                q.pop();
                if(q.empty())break;
                else q.push(NULL);
                level++;
                cout<<level<<".) ";
            }
            else{
                cout<<temp->data<<" ";        
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
                q.pop();
            }
        }
    }

    treenode<V>* remove_leaf_node(treenode<V>* root){
        if(root==NULL)return NULL;
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        treenode<V>* l=remove_leaf_node(root->left);
        treenode<V>* r=remove_leaf_node(root->right);
        root->left=l;
        root->right=r;
        return root;
    }

    void zig_zag(treenode<V> *root){
        stack<treenode<V>*> s1;
        stack<treenode<V>*> s2;
        s1.push(root);
        cout<<"Zig-Zag: "<<endl;
        int layer=1;
        while(!s1.empty() || !s2.empty()){
            cout<<layer<<".) ";
            if(s2.empty()){
                while(!s1.empty()){
                    treenode<V>* temp=s1.top();
                    if(temp->left!=NULL)s2.push(temp->left);
                    if(temp->right!=NULL)s2.push(temp->right);
                    cout<<temp->data<<" ";
                    s1.pop();
                }
            }
            else{
                while(!s2.empty()){
                    treenode<V>* temp=s2.top();
                    if(temp->right!=NULL)s1.push(temp->right);
                    if(temp->left!=NULL)s1.push(temp->left);
                    cout<<temp->data<<" ";
                    s2.pop();
                }
            }
            cout<<endl;
            layer++;
        }
    }
};

int main(){
    Binary_tree<int> bt;
    vector<int> preorder,inorder;
    // preorder={1,2,4,5,3,6};          1
    // inorder={4,2,5,1,3,6};        2     3
    //                             4   5     6
    preorder={1,2,4,5,8,10,3,6,9,7};
    inorder={4,2,8,10,5,1,6,9,3,7};
    treenode<int>* root=bt.const_from_in_and_pre(preorder,inorder,0,9,0,9);
    bt.printtree(root);
    bt.levelorder(root);
    // treenode<int>* root2=bt.remove_leaf_node(root);
    // bt.levelorder(root2);
    bt.zig_zag(root);
    return 0;
}
