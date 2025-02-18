#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class Btree {
public:
    Node* root;

    Btree() {
        root = nullptr;
    }

    Node* insert(Node* temp, int Indata) {
        if (temp == nullptr) {
            return new Node(Indata);
        } 
        if (Indata < temp->data) {
            temp->left = insert(temp->left, Indata);
        } else {
            temp->right = insert(temp->right, Indata);
        }
        return temp;
    }

    void insert(int Indata) {
        root = insert(root, Indata);
    }

     void display(Node* temp) {
        if (temp == nullptr) return;

        cout << temp->data << " - ";   
        display(temp->left);         
        display(temp->right);       
    }

    void display() {
        cout << "Tree Structure (Preorder Traversal): ";
        display(root);
        cout << endl;
    }
    
    void inorder(Node* temp) {
        if (temp != nullptr) {
            inorder(temp->left);
            cout << temp->data << " ";
            inorder(temp->right);
        }
    }

    void inorderTraversal() {
        inorder(root);
    }
    
    void i_pData(int entries) {
        int d1;
        for(int i=1;i<=entries;i++) {
            cout<<"enter data "<<i<<" :";
            cin>>d1;
            insert(d1);
        }
    }
    
    void longestNode(Node* temp) {
        if(temp == nullptr) return;
        
    }
};

int main() {
    Btree bt;
    int entries;
    cout<<"enter total entries : ";
    cin>>entries;
    
    bt.i_pData(entries);

    bt.display();
    
    cout << "Inorder Traversal: ";
    bt.inorderTraversal();
    cout << endl;
    
    return 0;
}
