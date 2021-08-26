#include<bits/stdc++.h>
#define MAX 30
using namespace std;

class node
{
    int data;
    node *left;
    node *right;
public:

    node()
    {
        left = right = NULL;
    }
    void insert_i(node*,int key);
    void inorder(node*);
    void postorder(node*);
    void levord(node*);
    node* copy_tree(node*);
    node* mirror(node*);
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
    void print_a(node* t)
    {
        cout<<t->data;
    }

}*root=NULL;

class q
{
    struct queueue
    {
        node* s[MAX];
        int frnt,rear;
    }Q;
public:
    q()
    {
        Q.frnt = -1;
        Q.rear = -1;
    }
    void insrt(node*);
    node* dq();
    void disp();
    bool isEmpty()
    {
        if(Q.frnt == -1 || Q.frnt > Q.rear)
            return true;
        return false;
    }
};

void q::disp()
{
    for (int i=0;i<MAX;i++)
        cout<<Q.s[i]<<" ";
}
void q::insrt(node* p)
{
    if (p!=NULL)
    {
        if (Q.frnt==-1)
            Q.frnt++;
        Q.s[++Q.rear] = p;
    }

}

node* q::dq()
{
    if(Q.frnt == -1 || Q.frnt>Q.rear)
        cout<<"Queue is empty ";
    node* val;
    val = Q.s[Q.frnt];
    Q.frnt++;
    return val;
}



void node::levord(node* p)
{
    q obj;
    obj.insrt(p);
    node *temp;
    while (!obj.isEmpty())
    {
        temp = obj.dq();
        print_a(temp);
        cout<<endl;
        obj.insrt(temp->left);
        obj.insrt(temp->right);
    }
}

node* node::copy_tree(node* root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        node* new_root=NULL;
        new_root = new node;
        new_root->data = root->data;

        new_root->left = copy_tree(root->left);
        new_root->right = copy_tree(root->right);
        return new_root;
    }

}
node* node::mirror(node* root)
{
    if (root == NULL)
        return NULL;
    else
    {
        node* new_root=NULL;
        new_root = new node;
        new_root->data = root->data;

        new_root->right = mirror(root->left);
        new_root->left = mirror(root->right);
        return new_root;
    }

}
void node::insert_i(node *root,int key)
{
    node *ptr,*t;
    ptr = new node(key);

    if(root == NULL)
    {
        ::root = ptr;
        cout<<"Inserted "<<ptr->data;
    }
    else
    {
        t = root;
        while(true)
        {
            if(key < t->data)
            {
                if(t->left == NULL)
                {
                    t->left = ptr;
                    cout<<"Inserted the element successfully";
                    break;
                }

                else
                    t = t->left;
            }
            else
            {
                if(t->right == NULL)
                {
                    t->right = ptr;
                    cout<<"Inserted the element successfully";
                    break;
                }
                else
                    t = t->right;
            }
        }
    }
}

void node ::inorder(node* root)
{
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << ",";
    inorder(root->right);
}

void node::postorder(node* root)
{
    if (root==NULL)
    {
        cout<<"Empty";
        return;
    }
    stack<node *> s1,s2;
    node *m;
    s1.push(root);
    while(!s1.empty())
    {   m = s1.top();
        s1.pop();
        s2.push(m);
        if (m->left)
            s1.push(m->left);
        if (m->right)
            s1.push(m->right);
    }
}

int main()
{
    node l1;
    node* temp1 = NULL;
    node* temp2 = NULL;
    int data,ch=0;
    cout<<"\t\t\tBINARY SEARCH TREE\n";
    while(ch!= 4)
    {
        cout<<  "\n1. Enter the element to be inserted"
                "\n2. Print the Binary Search Tree(RECURSIVE INORDER)"
                "\n3. Copy the Binary Search Tree"
                "\n4. Mirror the Binary Search Tree"
                "\n5. Print Binary Search Tree(Level order)"
                "\n6. Print the Binary Search Tree(ITERATIVE POSTORDER)"
                "\n7. Exit"
                "\n\nEnter your choice: ";

        cin>>ch;
        if(ch==1)
        {
            cout<<"Enter the element to be inserted : ";
            cin>>data;
            l1.insert_i(root,data);
            cout<<endl;
        }
        else if(ch==2)
        {
            l1.inorder(root);
            cout<<endl;
        }
        else if (ch==3)
        {
            temp1 = l1.copy_tree(root);
            cout<<"Copied Successfully: (Inorder print) ->";
            l1.inorder(temp1);
            cout<<endl;
        }
        else if (ch==4)
        {
            temp2 = l1.mirror(root);
            cout<<"\nMirrored Successfully : (Inorder print) ->";
            l1.inorder(temp2);
            cout<<endl;
        }
        else if (ch==5)
        {
            l1.levord(root);
            cout<<endl;
        }
        else if(ch==6)
        {
            l1.postorder(root);
            cout<<endl;
        }
            continue;
    }
    return 0;
}
