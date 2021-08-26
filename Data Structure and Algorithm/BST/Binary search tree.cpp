/**
Binary tree and Binary search tree
**/
#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;
	node(){
		left=right=NULL;
	}
};
class BST{
public:
	node* head;
	node* head2;	///for checking whether the second tree is equal to binary search tree or not
	BST(){
		head= NULL;
		head2= NULL;
	}
	node* Insert_BST(node **HEAD, int val, int h=1){														///1
		if((*HEAD) == NULL){
			node* ptr= new node;
			ptr->data = val;
			if(h==1 && this-> head==NULL){
				this-> head= ptr;
			}
			if(h==2 && this->head2==NULL)this->head2=ptr;
			return ptr;
		}

		if(val < (*HEAD)-> data){
			(*HEAD)->left= Insert_BST( &((*HEAD)->left), val);
		}
		else{
			(*HEAD)->right= Insert_BST( &((*HEAD)->right), val);
		}
		return *HEAD;

	}
	void Insert_BST_iterative(node* HEAD, int value){   												///2
		node* temp=HEAD;
		node*
		temp2=NULL;
		node* newnode= new node;
		newnode->data= value;
		while(temp!=NULL){
			if(value > temp->data ){
				temp2= temp;
				temp= temp->right;
			}
			else{
				temp2= temp;
				temp= temp->left;
			}
		}
		if(value > temp2->data){
			temp2->right= newnode;
		}
		else temp2->left= newnode;
		return ;
	}
	void Insert_Binary_tree(node *HEAD, int v){											///3
		node* newnode= new node;
		newnode->data= v;
		if(HEAD==NULL){

			this->head= newnode;
			cout<<"The node is inserted\n";
			return;

		}
		else{
			node* traversal = HEAD;
			char ch='L';
			cout<<"You want to insert left or right(l or L for LEFT and r or R for RIGHT)\n";
			cin>>ch;
			while(ch=='L' || ch=='R'|| ch=='l' || ch=='r'){
				if(ch=='l' || ch=='L'){
					if(traversal->left !=NULL)
					traversal= traversal->left;
					else {traversal->left = newnode;
					cout<<"The NODE is inserted\n";
					return ;}
				}
				else{
					if(traversal->right != NULL)
					traversal = traversal->right;
					else {traversal->right = newnode;
					cout<<"The NODE is inserted\n";
					return ;}
				}
				cout<<"You want to insert left or right(l or L for LEFT and r or R for RIGHT)\n";
				cin>>ch;
			}

		}
	}

	void Inorder_BST( node *HEAD){															///4
		if((HEAD)==NULL){
			return;
		}
		Inorder_BST(HEAD->left);
		cout<< HEAD->data<<" ";
		Inorder_BST(HEAD->right);

	}

	void Inorder_BST_iterative(node *HEAD){													///5
		node *temp = HEAD;
		stack<node*> s;
		s.push(temp);
		temp= temp->left;
		while(s.size()!=0 || temp!=NULL){
			while(temp != NULL){
				s.push(temp);
				temp= temp->left;
			}
			if(s.size() !=0){
				temp= s.top();
				s.pop();
			}
			cout<< temp->data<< " ";
			temp= temp->right;
		}
		}
		int Height(node *HEAD){																			///6
		if(HEAD == NULL)return 0;
		else return 1 + max(Height(HEAD->left), Height(HEAD->right));
	}
	void preorder_BST(node *HEAD){																///7
		if(HEAD== NULL)return ;
		cout<< HEAD->data<<" ";
		preorder_BST(HEAD->left);
		preorder_BST(HEAD->right);

	}
	void Preorder_BST_iterative(node *HEAD){												///8
		node *temp = HEAD;
		stack<node*> s;
		s.push(temp);
		cout<< temp->data<<" ";
		temp= temp->left;
		while(s.size()!=0 || temp!=NULL){
			while(temp != NULL){
				s.push(temp);
				cout<< temp->data<<" ";
				temp= temp->left;
			}
			if(s.size() !=0){
				temp= s.top();
				s.pop();
			}
			///cout<< temp->data<< " ";
			temp= temp->right;
		}
	}


	void postorder_BST(node *HEAD){																		///9
		if(HEAD== NULL)return ;

		postorder_BST(HEAD->left);
		postorder_BST(HEAD->right);
		cout<< HEAD->data<<" ";
	}

	void post_order_Traversal_iterative(node *HEAD){																///10
		stack<node*>s1, s2;
		s1.push(HEAD);
		while(!s1.empty()){
			node* temp= s1.top();

			s1.pop();
			if(temp->left)s1.push(temp->left);
			if(temp->right)s1.push(temp->right);
			s2.push(temp);
		}
		while(!s2.empty()){
			node* temp= s2.top();
			cout<< temp->data<< " ";
			s2.pop();
		}
	}


	void Level_order_Traversal(node* HEAD){ 																/// 11
		if(HEAD==NULL){
			cout<<"The tree is Empty\n";
			return ;
		}
		queue<node*>Q;
		Q.push(HEAD);
		if(HEAD->left)Q.push(HEAD->left);
		if(HEAD->right)Q.push(HEAD->right);
		node* temp= Q.front();
		cout<<temp->data<<" ";
		Q.pop();

		while(Q.size()!=0){
			temp= Q.front();
			if(temp->left)Q.push(temp->left);
			if(temp->right)Q.push(temp->right);
			Q.pop();
			cout<<temp->data<<" ";
		}
	}
	node* copy_BST(node **HEAD){																		///12
		if(*HEAD==NULL)return NULL;
		node* newptr= new node;
		newptr->data= (*HEAD)->data;
		newptr->left= copy_BST(&(*HEAD)->left);
		delete (*HEAD)->left;
		newptr->right= copy_BST(&(*HEAD)->right);
		delete (*HEAD)->right;
		///(this->head= newptr);
		delete *HEAD;

		return newptr;

	}
	node* Mirror(node **HEAD){																						///13
		if(*HEAD==NULL)return NULL;
		node* newptr= new node;
		newptr->data= (*HEAD)->data;
//		if((*HEAD)->right)
		newptr->left= Mirror(&(*HEAD)->right);
		///delete (*HEAD)->right;
//		if((*HEAD)->left)
		newptr->right= Mirror(&(*HEAD)->left);
		///delete (*HEAD)->left;
		///this->head= newptr;

		delete (*HEAD);
		return newptr;

	}


	bool equal_BST(node* HEAD1, node* HEAD2){														///14
		if(HEAD2==NULL && HEAD1==NULL)return true;
		if(HEAD1!=NULL && HEAD2!=NULL){
			if(HEAD1->data == HEAD2->data){
				return (equal_BST(HEAD1->left, HEAD2->left) && equal_BST(HEAD1->right, HEAD2->right));
			}
			else return false;
		}
		else return false;
	}
	void delete_node(node* Parent, node* Child){
		if( Child->left==NULL && Child->right== NULL){
			if(Parent->data > Child->data){
				Parent->left=NULL;
			}
			else  Parent->right= NULL;
			cout<<"The node deleted is "<< Child->data<<"\n";
			delete Child;
			return ;
		}
		else if(Child->left!= NULL && Child->right==NULL){
			if(Parent->data > Child->data){
				Parent->left=Child->left;

			}
			else  {
				Parent->right= Child->left;
			}
			cout<< "The deleted node is "<< Child->data<<"\n";
			delete Child;
			return ;
		}
		else if(Child->right!= NULL && Child->left==NULL){
			if(Parent->data > Child->data){
				Parent->left=Child->right;

			}
			else  {
				Parent->right= Child->right;
			}
			cout<< "The deleted node is "<< Child->data<<"\n";
			delete Child;
			return ;
		}
		else{
			node* temp_parent= Child;
			node* temp_child= Child->right;
			while(temp_child->left !=NULL ){
				temp_parent= temp_child;
				temp_child= temp_child->left;
			}
			cout<<"The deleted node is "<<Child->data<<"\n";
			Child->data = temp_child->data;
//			if(temp_child->right!=NULL){
			if(temp_parent->data<=temp_child->data)
				temp_parent->right= temp_child->right;
//			}
			else temp_parent->left= temp_child->right;
//			cout<<"TEMP->CHILD= "<<temp_child->data<<" \n";
//			cout<<"TEMP->PARENT= "<<temp_parent->data<<" \n";
			delete temp_child;
//			if(temp_parent->left != NULL)
//			cout<<"TEMP_PARENT->LEFT= "<<  temp_parent->left <<" \n";

//			temp_parent
			return ;
		}
	}
	void search_delete_BST_node(node *HEAD,  int val){													///15
		if(HEAD->data == val){
			if(HEAD->left == NULL){
				if(HEAD->right != NULL)
					this->head=HEAD->right;
				else this->head= NULL;
				cout<< "The deleted node is : "<<HEAD->data<<"\n";
				delete HEAD;
				return ;
			}
			if(HEAD->right == NULL){
				if(HEAD->left != NULL)
					this->head = HEAD->left;
				else this->head= NULL;
				cout<< "The deleted node is : "<<HEAD->data<<"\n";
				delete HEAD;
				return ;
			}
			node* temp= HEAD->right;
			node* parent= HEAD;
			while(temp->left!=NULL){
				parent=temp;
				temp=temp->left;
			}
			parent->left=temp->right;

			cout<< "The node deleted is "<<HEAD->data<<"\n";
			HEAD->data= temp->data;
			delete temp;
			return ;
		}
		else{
			node* parent= HEAD;node* child;
			if(val >parent->data){
				child= parent->right;
			}
			else child= parent->left;
			while(child!=NULL && child->data != val){
				parent= child;
				if(val >parent->data){
					child= parent->right;
				}
				else child= parent->left;
			}
			if(child==NULL){
				cout<< "There is no such element in the tree\n";
				return;
			}
			/// Calling delete function to delete the node
			delete_node(parent, child);
		}

	}
	node* Constructing_BST_inorder_preorder(vector<int> inorder,vector<int>preorder, int left, int right){   						/// 16

		static int index=0;
		if(left >right || left < 0 || right >= inorder.size())return NULL;
		node* newnode= new node;

		int temp_find;
		for(int i = left; i<= right; i++){
			if(preorder[index] == inorder[i]){
				temp_find= i;
				///cout<< i<<" ";
				break;
			}
		}
		newnode->data= preorder[index];
		index++;
		newnode->left= Constructing_BST_inorder_preorder( inorder, preorder, left, temp_find-1 );
		newnode->right= Constructing_BST_inorder_preorder(inorder, preorder, temp_find+1, right);
		return newnode;
	}
};
int choice(){
    cout<< "\t\tBinary tree and Binary search tree\n\n";
	cout<< "\tEnter 1 for RECURSIVE Insertion into binary search tree\n";
	cout<< "\tEnter 2 for ITERRATIVE Insertion into binary search tree\n";
	cout<< "\tEnter 3 for Insertion into Binary Tree\n";
	cout<<"\tEnter 4 for RECURSIVE In-order traversal\n";
	cout<<"\tEnter 5 for ITERRATIVE In-order traversal\n";
	cout<<"\tEnter 6 to find the Height of the TREE\n";
	cout<<"\tEnter 7 for RECURSIVE Pre-order Traversal\n";
	cout<<"\tEnter 8 for ITERRATIVE Pre-order Traversal\n";
	cout<<"\tEnter 9 for RECURSIVE Post-order Traversal\n";
	cout<<"\tEnter 10 for ITERRATIVE Post-order Traversal\n";
	cout<<"\tEnter 11 for Level Order Traversal of the tree\n";
	cout<<"\tEnter 12 for copying the tree\n";
	cout<<"\tEnter 13 for Mirroring the tree\n";
	cout<<"\tEnter 14 for Checking whether two Trees are equal or not\n";
	cout<< "\tEnter 15 for Searching and Deleting an element from the Binary Search Tree\n";
	cout<< "\tEnter 16 for Construction of a binary search tree from In-order and Pre-order traversal \n\n";
	cout<<"\tEnter any other number to exit\n";
	cout<< "Enter your choice: ";
	int ch;
	cin>> ch;
	return ch;

}
int main(){

	BST obj;
	int chh= choice();
	while(chh>=1 && chh<=16){
		if(chh==1){		///1 RECURSIVE Insertion into binary search tree
			int data;
			cout<< "Enter the data: ";
			cin>>data;
			obj.Insert_BST(&obj.head, data);
		}
		else if(chh==2){	///2 ITERRATIVE Insertion into binary search tree
			int data;
			cout<< "Enter the data: ";
			cin>>data;
			obj.Insert_BST_iterative(obj.head, data);
		}
		else if(chh==3){	///3 Insertion into Binary Tree
			int data;
			cout<<"Enter the data: ";
			cin>>data;
			obj.Insert_Binary_tree(obj.head, data);
		}
		else if(chh==4){	///4 RECURSIVE In-order traversal
			if(obj.head!=NULL)
			obj.Inorder_BST(obj.head);
			else cout<<"The tree is empty ";
			cout<< "\n";
		}
		else if(chh==5){	///5 ITERRATIVE In-order traversal
			if(obj.head!=NULL)
			obj.Inorder_BST_iterative(obj.head);else cout<<"The tree is empty ";
			cout<< "\n";
		}
		else if(chh== 6) {		///6 to find the Height of the TREE
			cout<<"The Height of Binary Tree is : "<< obj.Height(obj.head);
			cout<<"\n";
		}
		else if(chh== 7){		///7 for RECURSIVE Pre-order Traversal
			if(obj.head!=NULL)
			obj.preorder_BST(obj.head);else cout<<"The tree is empty";
			cout<< "\n";
		}
		else if(chh==8){		///8 for ITERRATIVE Pre-order Traversal
			if(obj.head!=NULL)
			obj.Preorder_BST_iterative(obj.head);
			else cout<<"The tree is empty";
			cout<< "\n";
		}
		else if(chh==9){		///9 for RECURSIVE Post-order Traversal
			if(obj.head!=NULL)
			obj.postorder_BST(obj.head);
			else cout<<"The tree is empty";
			cout<<"\n";
		}
		else if(chh==10){		///10 for ITERRATIVE Post-order Traversal
			if(obj.head!=NULL)
			obj.post_order_Traversal_iterative(obj.head);
			else cout<<"The tree is empty";
			cout<<"\n";
		}
		else if (chh==11){		///11 for Level Order Traversal of the tree
			if(obj.head!=NULL)
			obj.Level_order_Traversal(obj.head);
			else cout<<"The tree is empty";
			cout<<"\n";
		}
		else if(chh==12){		///12 for copying the tree
			if(obj.head!=NULL){
				obj.head= obj.copy_BST(&obj.head);
				obj.Inorder_BST(obj.head);
			}
			else cout<<"The tree is empty";
			cout<<"\n";
		}
		else if(chh==13){		///13 for Mirroring the tree
			if(obj.head!=NULL){
				obj.head=obj.Mirror(&obj.head);
				obj.Inorder_BST(obj.head);
			}
			else cout<<"The tree is empty";
			cout<<"\n";
		}
		else if(chh==14){		///14 for checking whether two trees are equal or not
			char choose= 'Y';
			while(choose=='Y'|| choose=='y'){
				int vall;
				cout<<"Enter the value of the node\n\t";
				cin>>vall;
				obj.Insert_BST(&obj.head2, vall, 2);
				cout<< "Do you want to enter more nodes in the tree(Y/y or N/n): ";
				cin>>choose;
			}
			bool isequal= obj.equal_BST(obj.head, obj.head2);
			if(isequal)cout<< "\t\tBOTH THE TREES ARE EQUAL \n";
			else cout<< "\t\tBOTH THE TREE ARE NOT EQUAL \n";

		}
		else if(chh==15){		///15 for Searching and Deleting an element from the Binary Search Tree
			cout<<"Enter the value you want to delete :\n";
			int val;
			cin>>val;
			obj.search_delete_BST_node(obj.head, val);
		}
		else if(chh == 16){		/// 16 for Building a BST from given In-order and Pre-order Traversal
			vector<int> inorder;
			vector<int> preorder;
			cout<< "Enter the size of the list: ";
			int siz; cin>> siz;
			cout<<"Enter the elements in the In-order array; ";
			for(int k=0; k< siz; k++){
				int x;
				cin>> x;
				inorder.push_back(x);
			}
			cout<<"Enter the elements in the Pre-order array; ";
			for(int k=0; k< siz; k++){
				int x;
				cin>> x;
				preorder.push_back(x);
			}
			obj.head=obj.Constructing_BST_inorder_preorder(inorder, preorder,  0, siz-1);
			obj.Inorder_BST(obj.head);

			cout<<"\n";
			///cout<< obj.Height(obj.head)<<endl;
		}
		else{
			cout<< "\n\n\t\tEXITING.....";
		}
		chh= choice();
	}

}


