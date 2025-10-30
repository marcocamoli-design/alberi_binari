#include <iostream>

using namespace std;

struct Node{
	int value, counter;
	Node *left, *right;
	
		Node (int key){
			counter=0;
			value=key;
			left=nullptr;
			right=nullptr;
		}
		
		Node (Node &other){
			counter=other.counter;
			value=other.value;
			left=other.left;
			right=other.right;
		}
		
		Node (Node *other){
			counter=other->counter;
			value=other->value;
			left=other->left;
			right=other->right;
		}
			
};

bool insertion (int, Node*);

int main (){
	int valore_radice {10};
	Node* root(valore_radice);
	cout << "dai in input un valore per un nuovo nodo:";
	int valore_input;
	cin >> valore_input;
	insertion(valore_input, root);
	return 0;
	}
	Node* insert(Node* r, int val){
		Node* precedente{nullptr};
		Node* current{r};
		bool is_left;
		while(current != nullptr){
				if(val < r->value){
					precedente = current;
						current = current->left;
					is_left = true;
				}
				else if(val > current->value){
					precedente = current;
					current = current->right;
					is_left = false;
				}
		}
		if(is_left){
		precedente->left = new Node(val);
		}else if(!is_left){
		precedente->right = new Node(val);
		}
		return r;
	}