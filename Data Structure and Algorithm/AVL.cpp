#include<bits/stdc++.h>
using namespace std;

class Node{
	string data;
	Node* left;
	Node* right;
	int height;
public:
	Node(){
		this->data = "";
		this->height = -1;
		this->left = nullptr;
		this->right = nullptr;
	}
	void set_data(string dat){
		this->data = dat;
	}
	void set_height(int h){
		this->height = h;
	}
	void set_leftptr(Node* ptr){
		this->left = ptr;
	}
	void set_rightptr(Node* ptr){
		this->right = ptr;
	}

	string get_data(){
		return this->data ;
	}
	int get_height(Node* ptr){
		if( ptr == nullptr){
			return 0;
		}
		return ptr->height;
	}
	Node* get_leftptr(){
		return this->left ;
	}
	Node* get_rightptr(){
		return this->right ;
	}
};
class AVL{
	Node* Head;
public:
	AVL(){
		this->Head  = nullptr;
	}
	Node* get_headptr(){
		return Head;
	}
	void set_headptr(Node* ptr){
		this->Head = ptr;
	}
	Node* left_rotation(Node* temp){
		Node* temp1= temp->get_rightptr();
		temp->set_rightptr(temp1->get_leftptr());
		temp1->set_leftptr(temp);
		temp->set_height(1 + max( temp->get_leftptr()->get_height(temp->get_leftptr()), temp->get_rightptr()->get_height(temp->get_rightptr() ) ) );
		temp1->set_height(1 + max( temp1->get_leftptr()->get_height(temp1->get_leftptr()), temp1->get_rightptr()->get_height(temp1->get_rightptr() ) ) );
		return temp1;
	}
	Node* right_rotation(Node* temp){
		Node* temp1= temp->get_leftptr();
		temp->set_leftptr(temp1->get_rightptr());
		temp1->set_rightptr(temp);
		temp->set_height(1 + max( temp->get_leftptr()->get_height(temp->get_leftptr()), temp->get_rightptr()->get_height(temp->get_rightptr() ) ) );
		temp1->set_height(1 + max( temp1->get_leftptr()->get_height(temp1->get_leftptr()), temp1->get_rightptr()->get_height(temp1->get_rightptr() ) ) );
		return temp1;
	}

	Node* insert( Node* root, Node* curr){
		if(root == nullptr){
			return curr;
		}
		if( curr->get_data()<  root->get_data() ){
			// root-> left  = insert(root->left, curr);
			root->set_leftptr(insert(root->get_leftptr(), curr));
		}
		else root->set_rightptr(insert(root->get_rightptr(), curr));

		root->set_height(1 + max(root->get_leftptr()->get_height(root->get_leftptr()) , root->get_rightptr()->get_height(root->get_rightptr())));

		if(abs(root->get_leftptr()->get_height(root->get_leftptr()) - root->get_rightptr()->get_height(root->get_rightptr()) ) <= 1 ){
			return root;
		}
		else{
			if(root->get_leftptr()->get_height(root->get_leftptr()) - root->get_rightptr()->get_height(root->get_rightptr()) < -1){
				if( root->get_rightptr()->get_leftptr()->get_height(root->get_rightptr()->get_leftptr()) - root->get_rightptr()->get_rightptr()->get_height(root->get_rightptr()->get_rightptr()) < 0){ // LL rotation
					root = left_rotation(root);
				}
				else{				// RL rotation
					root->set_rightptr( right_rotation(root->get_rightptr()));
					root = left_rotation(root);
				}
			}
			else {
				if( root->get_leftptr()->get_leftptr()->get_height(root->get_leftptr()->get_leftptr()) - root->get_leftptr()->get_rightptr()->get_height(root->get_leftptr()->get_rightptr()) > 0){ // RR rotation
					root = right_rotation(root);
				}
				else{				// LR rotation
					root->set_leftptr( left_rotation(root->get_leftptr()));
					root = right_rotation(root);
				}
			}
		}
		return root;

	}
	void insert_Node(string d, Node* H){
		Node* newnode = new Node;
		newnode->set_data(d);
		newnode->set_height(1);
		if( H == nullptr){
			this->set_headptr(newnode);
			return;
		}
		this->set_headptr(insert(H, newnode));
	}
	void InorderTraversal(Node* ptr){
		if( ptr == nullptr){
			return;
		}
		InorderTraversal(ptr->get_leftptr());
		cout<< ptr->get_data() <<  " ";
		InorderTraversal(ptr->get_rightptr());

	}
	int search_AVL(Node* h, string data){
		int counter= 0;
		Node* temp = h;
		while( temp != nullptr){
			if( temp->get_data() == data){
				return counter+1;
			}
			if(temp->get_data() < data){
				counter++;
				temp = temp->get_rightptr();
			}
			else{
				counter++;
				temp = temp->get_leftptr();
			}
		}
		return 0;
	}
};

int choice(){
	int a;
	cout<< "\n\t Enter your choice: ";
	cout<< "\n\t Enter 1 for insertion into the AVL Tree: ";
	cout<< "\n\t Enter 2 for Inorder Display of the AVL Tree: ";
	cout<< "\n\t Enter 3 for Searching into the AVL Tree: ";
	cout<< "\n\t Enter any other key to exit: ";
	cin >> a;
	return a;
}
int main(){
	AVL obj;
	int ch = choice();
	while( ch >= 1 && ch <= 3){
		if( ch == 1){
			string data;
			cout<< "\nEnter the data you would like to Enter: ";
			cin>> data;
			obj.insert_Node(data, obj.get_headptr());
		}
		else if(ch == 2){
			cout<< "\nINORSER TRAVERSAL:\n ";
			obj.InorderTraversal(obj.get_headptr());
		}
		else if( ch == 3){
			cout<< "\nEnter the element you want to enter: ";
			string a;cin>> a;
			int found = obj.search_AVL(obj.get_headptr(), a);
			if( found ){
				cout<< "\n The element is found after "<< found << " comparisions\n";
			}
			else cout<< "\n The element is not present in the tree \n";
		}
		ch = choice();

	}
}
