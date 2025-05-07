#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

class Node {
public:
    char value;
    Node* left;
    Node* right;

    Node(char v) {
        value = v;
        left = right = nullptr;
    }
};

class ExpressionTree {
public:
    Node* constructTree(const string& prefix) {
        stack<Node*> s;
        for (int i = prefix.length() - 1; i >= 0; i--) {
            char ch = prefix[i];

            Node* newNode = new Node(ch);
            if (isOperator(ch)) {
                Node* left = s.top(); s.pop();
                Node* right = s.top(); s.pop();
                newNode->left = left;
                newNode->right = right;
            }
            s.push(newNode);
        }
        return s.top();
    }

    void postorderNonRecursive(Node* root) {
        if (!root) return;

        stack<Node*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            Node* node = s1.top(); s1.pop();
            s2.push(node);

            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }

        cout << "Postorder Traversal: ";
        while (!s2.empty()) {
            cout << s2.top()->value << " ";
            s2.pop();
        }
        cout << endl;
    }

    void deleteTree(Node* root) {
        if (!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

private:
    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
    }
};

int main() {
    string prefix = "+--a*bc/def"; 
    ExpressionTree tree;

    Node* root = tree.constructTree(prefix);
    tree.postorderNonRecursive(root);
    tree.deleteTree(root);

    cout << "Tree deleted successfully.\n";
    return 0;
}
