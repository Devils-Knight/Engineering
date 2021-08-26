#include<bits/stdc++.h>
using namespace std;

class node{
	char ch;
	node* left;
	node* right;
	string code;
	int freq;
public:
	node(char c, int f){
		this->ch =c;
		this->freq= f;
		this->left = NULL;
		this->right = NULL;
		this->code = "";
	}
	char get_char(){
		return this->ch;
	}
	void set_left_ptr(node* n1){
		this->left = n1;
	}

	void set_right_ptr(node* n2){
		this->right = n2;
	}
	node* get_left_ptr(){
		return this->left;
	}

	node* get_right_ptr(){
		return this->right;
	}
	void set_ch_code(string s){
		this->code= s;
	}
	string get_ch_code(){
		return this->code;
	}
	int get_freq(){
		return this->freq;
	}

};

bool comp(node* n1, node* n2){
	return n1->get_freq() <= n2->get_freq();
}

class Hoffmann_Tree{

public:
	deque<node*>dq;
	map<char, string> mp;
///  as sorting has to be done in decreasing order
	void insert_tree(){
		char choice = 'y';
		while(choice == 'y' || choice == 'Y'){
			cout<<" Enter the letter and its corresponding frequency: ";
			char letter;
			int frequency;
			cin>> letter >> frequency;
			node* newnode = new node(letter, frequency);
			dq.push_back(newnode);
			cout<< "\n Do you want to insert more elements (y/Y) ";
			cin>> choice;
		}
	}
	void build_tree(){
		sort(dq.begin(), dq.end(), comp);
		while(dq.size() > 1 ){
			node *first = dq.front();
			dq.pop_front();
			node *second = dq.front();
			dq.pop_front();
			node* newnode =new node('~', first->get_freq() + second->get_freq());
			newnode->set_left_ptr(first);
			newnode->set_right_ptr(second);
			dq.push_back(newnode);
			sort(dq.begin(), dq.end(), comp);
		}
	}
	void assign_code(node* var , string s){
		if(var->get_left_ptr() == NULL && var->get_right_ptr() == NULL){
			var->set_ch_code(s);
			mp[var->get_char()]= s;
			return ;
		}
		assign_code(var->get_left_ptr(), s+"0");
		assign_code(var->get_right_ptr(), s+"1");
		return ;
	}
	string encode_given_string(string given){
		int len= given.length();
		string encoded="" ;
		for(int i=0; i< len ; i++){
			encoded += mp[given[i]];
		}
		cout<< "\n\tEncoded String is: "<<encoded;
		return encoded;
	}
	string decode_given_sequence(string given){
		int len= given.length();
		string decode="";
		int i=0;
		while(i< len){
			node* temp= dq.front();
			while(i<len && temp->get_left_ptr()!= NULL && temp->get_right_ptr()!= NULL){
				if(given[i] == '0')temp= temp->get_left_ptr();
				else temp= temp->get_right_ptr();
				i++;
			}
			decode+= temp->get_char();
		}
		cout<< "\n\tThe Decoded String is: "<<decode;
		return decode;
	}
};

int choice(){
	cout<< "\n1-> Assigning code to each character: ";
	cout<< "\n2-> Encoding a Given String: ";
	cout<< "\n3-> Decoding a given String: ";
	cout<< "\nPress any other key to exit:\n ";
	cout<<"\t Enter your choice: ";
	int chh;
	cin>> chh;
	return chh;
}

int main(){
	Hoffmann_Tree obj;
	cout<<"\n Kindly insert element into the Hoffmann Tree\n ";
	obj.insert_tree();
	obj.build_tree();
	int choose=1 ;

	while(choose >=1 && choose<= 3){
		choose= choice();
		if(choose == 1){
			obj.assign_code(obj.dq.front(), "");
			cout<< "\nAfter encoding the code for each character looks like: \n";
			for(auto x : obj.mp){
				cout<< x.first<< " "<< x.second<<endl;
			}

		}
		else if(choose == 2){
			bool flag =true;
			cout<<" Enter the string to be Encoded: ";
			string s;
			cin>>s;
			for(int i=0; i< s.length(); i++){
				if(obj.mp.find(s[i]) == obj.mp.end()){
					cout<< "\nAll the characters of the string are not present in the Huffmann tree: \n";
					flag = false;
					break;
				}
			}
			if(flag)obj.encode_given_string(s);
		}

		else{
			cout<<" Enter the string to be Decoded: ";
			string s;
			cin>>s;
			obj.decode_given_sequence(s);
		}
	}


}


