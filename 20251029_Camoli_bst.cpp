#include <iostream>

using namespace std;

//qui viene creata la struct Node

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

Node* insertion_ricorsiva (Node* r, int val);

Node* insertion_non_ricorsiva (Node* r, int val);

void preorder(Node* root);

void inorder(Node* root);

void postorder(Node* root);

Node* search_ricorsiva(Node* root, int key);

Node* cancella_un_figlio_ricorsiva(Node* root, int key);

// qui c'è' il main

int main() {
    int valore_radice {10};
    Node* root = new Node(valore_radice);

//inserimento di un nodo in maniera non ricorsiva

    cout << "Dai in input un valore per un nuovo nodo: ";
    int valore_input;
    cin >> valore_input;

    insertion_non_ricorsiva(root, valore_input);

//inserimento di un nodo in maniera ricorsiva	

    cout << "Dai in input un valore per un nuovo nodo: ";
    cin >> valore_input;
    insertion_ricorsiva(root, valore_input);

// cercare un valore all'interno dell'albero

    cout << "Inserisci un valore da cercare: ";
    int valore_cercato;
    cin >> valore_cercato;

    Node* risultato = search_ricorsiva(root, valore_cercato);

    if (risultato != nullptr){
        cout << "Nodo trovato! Valore: " << risultato->value << endl;
	}
    else {
        cout << "Valore non presente nell'albero." << endl;
	}

// cancellazione nodo in foglia

    int valore_delete;
    cout << "Inserisci un nodo foglia da cancellare: ";
    cin >> valore_delete;

    root = cancella_foglia_ricorsiva(root, valore_delete);

// cancellazione nodo con un figlio

    cout << "Inserisci un nodo con un solo figlio da cancellare: ";
    cin >> valore_delete;

    root = cancella_un_figlio_ricorsiva(root, valore_delete);

// i 3 metodi per scorrere un albero binario

    cout << endl << "Preorder: ";
    preorder(root); cout << endl;

    cout << "Inorder: ";
    inorder(root); cout << endl;

    cout << "Postorder: ";
    postorder(root); cout << endl;

    return 0;
}

// fuzioni per gli alberi binari da qui in poi

	Node* insertion_non_ricorsiva (Node* r, int val){
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

	Node* insertion_ricorsiva(Node* r, int val) {
		if (r == NULL) return new Node(val);
		if (r->value == val) return r;
		if (val > r->value) {
			r->right = insertion_ricorsiva(r->right,val);
		} else if (val < r->value) {
			r->left = insertion_ricorsiva(r->left,val);
		}
		return r;
	}

	void preorder(Node* root) {
    	if (root == nullptr) return;
    		cout << root->value << " ";   // Visita il nodo
    		preorder(root->left);         // Visita il sottoalbero sinistro
    		preorder(root->right);        // Visita il sottoalbero destro
	}

	void inorder(Node* root) {
    	if (root == nullptr) return;
    		inorder(root->left);          // Visita il sottoalbero sinistro
    		cout << root->value << " ";   // Visita il nodo
    		inorder(root->right);         // Visita il sottoalbero destro
	}

	void postorder(Node* root) {
    	if (root == nullptr) return;
    		postorder(root->left);        // Visita il sottoalbero sinistro
    		postorder(root->right);       // Visita il sottoalbero destro
    		cout << root->value << " ";   // Visita il nodo
	}

	Node* search_ricorsiva(Node* root, int key) {
    	if (root == nullptr || root->value == key) return root;
    	if (key < root->value) return search_ricorsiva(root->left, key);
    	return search_ricorsiva(root->right, key);
	}

	Node* cancella_foglia_ricorsiva(Node* root, int key) {
    	if (root == nullptr) return root;
    	if (key < root->value) {
        	root->left = cancella_foglia_ricorsiva(root->left, key);
    	} else if (key > root->value) {
        	root->right = cancella_foglia_ricorsiva(root->right, key);
    	} else { // nodo trovato
        	if (root->left == nullptr && root->right == nullptr) {
            	delete root;
            	return nullptr;
        	} else {
            	cout << "Il nodo non è una foglia, non può essere cancellato con questa funzione" << endl;
            	return root;
        	}
    	}
    	return root;
	}

	Node* cancella_un_figlio_ricorsiva(Node* root, int key) {
    	if (root == nullptr) {
        	return root;
    	}

    	if (key < root->value) {
        	root->left = cancella_un_figlio_ricorsiva(root->left, key);
    	} else if (key > root->value) {
        	root->right = cancella_un_figlio_ricorsiva(root->right, key);
    	} else { // nodo trovato
        	if (root->left != nullptr && root->right == nullptr) {
            	Node* child = root->left;
            	delete root;
            	return child;
        	} else if (root->left == nullptr && root->right != nullptr) {
            	Node* child = root->right;
            	delete root;
            	return child;
        	} else {
            	cout << "Il nodo non ha un solo figlio o è una foglia, usa un'altra funzione." << endl;
            	return root;
        	}
    	}
		return root;
	}