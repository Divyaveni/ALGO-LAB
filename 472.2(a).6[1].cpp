
#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};


void findParent(struct Node* node,
				int val, int parent)
{
	if (node == NULL)
		return;


	if (node->data == val) {

		// Print its parent
		cout << parent;
	}
	else {

		// Recursive calls for the children
		// of the current node
		// Current node is now the new parent
		findParent(node->left, val, node->data);
		findParent(node->right, val, node->data);
	}
}

// Driver code
int main()
{
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	int node = 3;

	findParent(root, node, -1);

	return 0;
}
