#include<bits/stdc++.h>
using namespace std;
#include "bits/stdc++.h"
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;
	bool left_thread;
	bool right_thread;
	node(int value){
		this->data= value;
		this->left_thread = true;
		this->right_thread = true;
		this->left= NULL;
		this->right= NULL;
	}
};
vector<node* > v;
class Threaded_Binary_Tree{
public:
	node* Dummy;
	node* Head;
//	Head->left= Head;
//	Head->right= Head;
	Threaded_Binary_Tree(){
		node *Dummy = new node(INT_MAX);
		Dummy->left= Dummy;
		Dummy->right= Dummy;
		Dummy->left_thread = true;
		Dummy->right_thread = true;

		this->Head = NULL;

	}
	void insert_Threaded( int val){
		node* newnode= new node(val);
		newnode->left= newnode;
		newnode->right= newnode;
		if(this->Head == NULL){
			this->Head = newnode;
			Dummy->left = newnode;
			Dummy->left_thread = false;
			newnode->right = Dummy;
			newnode->left = Dummy;
			return ;
		}
		else{
			node* temp = this->Head;
			while(true){
				if(val < temp->data && temp->left_thread == true){
					newnode->left= temp->left;
					newnode->right= temp;
					temp->left= newnode;
					temp->left_thread = false;
					return ;

				}
				else if(val > temp->data && temp->right_thread == true){
					newnode->right= temp->right;
					newnode->left= temp;
					temp->right = newnode;
					temp->right_thread = false;
					return ;

				}
				else if(val < temp->data ){
					temp= temp->left;
				}
				else temp=temp->right;
			}
		}
	}
	void inorder_traversal(){
		if( Dummy->left_thread == true){
			cout<<"The Tree is Empty \n";
			return ;
		}
		node* temp= Head;
		while(temp != Dummy){
			while( !temp -> left_thread ){
				temp= temp->left;
			}
			cout<< temp->data<<" ";
			while(temp->right_thread){
				temp= temp->right;
				if(temp == Dummy){
					return ;
				}
				cout<< temp->data<<" ";
			}
			temp= temp->right;
		}

	}
	void preorder_traversal(){
		if( Dummy->left_thread == true){
			cout<<"The Tree is Empty \n";
			return ;
		}
		node* temp= this->Head;

		while(temp != Dummy){
			while( !temp -> left_thread ){
				cout<< temp->data<<" ";
				temp= temp->left;
			}
			cout<< temp->data<<" ";
			while(temp->right_thread){
				temp= temp->right;
				if(temp == Dummy){
					return ;
				}
			}

			temp= temp->right;
		}
	}

	node* Insert_BST(node *head, int val){
		if(head == NULL){
			node* ptr= new node(val);
			ptr->left=NULL;
			ptr->right= NULL;
//			ptr->left_thread=false;
//			ptr->left_thread=false;
//			ptr->data = val;
			if(this->Head == NULL){
				this-> Head= ptr;
			}
			return ptr;
		}

		if(val < head -> data){
			head->left= Insert_BST(head->left, val ) ;
		}
		else{
			head->right= Insert_BST( head->right, val);
		}
		return head;

	}
	void Inorder_BST_vector( node *HEAD){
		if(HEAD == NULL){
			return;
		}
		Inorder_BST_vector(HEAD->left);
		v.push_back(HEAD);
		Inorder_BST_vector(HEAD->right);

	}
	void BST_TO_TBST(node* HEAD){
		char choice='y';
		while(choice == 'y' ){
			cout<<"Enter the value to be inserted into the tree :";
			int temp_val;
			cin>> temp_val;
			Insert_BST(this->Head, temp_val);
			cout<< "Do you  want to insert  more elements into the BST(y/n) ";
			cin>> choice;
		}
		Inorder_BST_vector(this->Head);
		int len= v.size();
		cout<< "\n----- len-----  "<<len<<"\n";

		cout<<"\nVector Traversal :\n";
		for(int i=0 ; i< v.size(); i++){
			cout<< v[i]->data<<" ";
		}
		if(len){
			this->Dummy->left= this->Head;
			this->Dummy->left_thread = false;
		}
		///if(v[0]->left == NULL)cout<< "\nv[0]->left = NULL\n";
		v[0]->left=Dummy;
		v[0]->left_thread=true;
		if( v[0]->right == NULL ){
			v[0]->right= v[1];
			v[0]->right_thread= true;

		}
		else{
			v[0] ->right_thread= false;
		}
		///if(v[len-1]->right== NULL)cout<< "\nv[len-1]->right = NULL\n";
		v[len-1]->right=Dummy;
		v[len-1]->right_thread=true;
		if( v[len-1]->left == NULL ){
			v[len-1]->left = v[len-2];
			v[len-1]->left_thread= true;
		}
		else{
			v[len-1] ->left_thread= false;
		}
		for(int i=1; i< len-1; i++){
			if(v[i]->left ==NULL){
				v[i]->left = v[i-1];
				v[i]->left_thread= true;
			}
			else{
				v[i]->left_thread= false;
			}
			if(v[i]->right == NULL){
				v[i]->right= v[i+1];
				v[i]->right_thread= true;
			}
			else{
				v[i]->right_thread= false;
			}
		}

		cout<<"\nINORDER TRAVERSAL OF TBST\n ";
		this->inorder_traversal();
	}
	void delete_node_TBST(int del_val){
		if(this->Head->data == del_val){
			node* parent= this->Head;
			node* child= this->Head->right != this->Dummy ?this->Head->right : this->Head->left;
			if(child == this->Head->right){
				while(child->left_thread == false  && child != this->Dummy){
					parent = child;
					child= child->left;
				}
				if(child != this->Dummy){
					this->Head->data= child->data;
					parent->left= child->left;
					parent->left_thread = child->left_thread;
					delete child;
					cout<< "\n--->The node with the value "<< del_val<< " is deleted successfully<---\n";
				}
				else{		 //for case when we want to delete the last element form the tree (i.e only head remains)
					delete parent;
					this->Head = NULL;
					this->Dummy->left = this->Dummy;
					this->Dummy->right = this->Dummy;
					this->Dummy->left_thread = true;
					this->Dummy->right_thread = true;
					cout<< "\n--->The node with the value "<< del_val<< " is deleted successfully<---\n";
					// parent->left= this->Dummy;
					// parent->right= this->Dummy;
					// this->Head = NULL;
					// parent->left_thread= true;
					// parent->right_thread= true;
				}

			}
			else{

				while(child->right_thread == false && child != this->Dummy ){
					parent = child;
					child= child->right;
				}
				if(child != this->Dummy){
					this->Head->data= child->data;
					parent->right= child->right;
					parent->right_thread = child->right_thread;
					delete child;
					cout<< "\n--->The node with the value "<< del_val<< " is deleted successfully<---\n";
				}
				else{		 //for case when we want to delete the last element form the tree (i.e only head remains)
					// parent->left= this->Dummy;
					// parent->right= this->Dummy;
					// this->Head = NULL;
					// parent->left_thread= true;
					// parent->right_thread= true;
					delete parent;
					this->Head = NULL;
					this->Dummy->left = this->Dummy;
					this->Dummy->right = this->Dummy;
					this->Dummy->left_thread = true;
					this->Dummy->right_thread = true;
					cout<< "\n--->The node with the value "<< del_val<< " is deleted successfully<---\n";

				}
			}
		}
		else{			// if we don't want to delete the head
			//search for the element
			node* parent = this->Head;
			node* child = del_val < parent->data ? parent->left : parent->right;
			while(child!= this->Dummy && child->data!= del_val){
				parent = child;
				child = parent->data > del_val? child->left: child->right;
			}
			if(child == NULL ){
				cout<< "There is no such value in the tree \n";
				return;
			}
			else{
				if(child->left_thread == false && child->right_thread == false){
					node* temp_parent= child;
					node* temp_child= child->right;
					while(temp_child->left_thread != true){
						temp_parent = temp_child;
						temp_child = temp_child->left;
					}
					child->data = temp_child->data;
					temp_parent->left = temp_child->left;
					temp_parent->left_thread = true;
					delete temp_child;


				}
				else if(child->left_thread== false || child->right_thread == false){
					if(child->data == parent->left->data){
						if(child->left_thread == false)parent->left= child->left;
						else parent->left = child->right;
						node* temp = parent->left;
						if(temp == child->left){
							while(temp != this->Dummy && temp->right_thread == false){
								temp= temp->right;
							}
							temp->right = child->right;
							temp->right_thread = child->right_thread;
						}
						else{
							while(temp != this->Dummy && temp->left_thread == false){
								temp= temp->left;
							}
							temp->left = child->left;
							temp->left_thread = child->left_thread;

						}
						delete child;

					}
					else{
						if(child->left_thread == false)parent->right = child->left;
						else parent->right = child->right;
						node* temp= parent->right;
						if(temp == child->left){
							while(temp != this->Dummy && temp->right_thread == false){
								temp= temp->right;
							}
							temp->right = child->right;
							temp->right_thread = child->right_thread;
						}
						else{
							while(temp != this->Dummy && temp->left_thread == false){
								temp= temp->left;
							}
							temp->left = child->left;
							temp->left_thread = child->left_thread;

						}
					}
				}
				else{
					if(child->data == parent->left->data){
						parent->left= child->left;
						parent->left_thread= true;
					}
					else{
						parent->right= child->right;
						parent->right_thread= true;
					}
				}
			}


		}
	}

};
int main(){
	Threaded_Binary_Tree obj;
	obj.Dummy->data=INT_MAX;
	int chh=1;
	while(chh>=1 && chh<=5){
		cout<<"\n1->For insertion\n2->For inorder traversal\n3->For preorder traversal\n4->Converting BST to TBST\n5->Deletion of node\n ";
		cout<< "Enter your choice: ";
		cin>> chh;
		if(chh==1){
			cout<<"ENTER THE VALUE TO BE INSERTED: ";
			int val;
			cin>> val;
			obj.insert_Threaded(val);
		}
		else if(chh==2){
			obj.inorder_traversal();
		}
		else if(chh == 3){
			obj.preorder_traversal();
		}
		else if(chh == 4){
			obj.BST_TO_TBST(obj.Head);
		}
		else if(chh == 5){
			cout<< "Enter the value you want to delete: ";
			int val;
			cin>>val;

			obj.delete_node_TBST(val);
		}

		else{
			cout<<"Exit...";
		}

	}
	return 0;
}


