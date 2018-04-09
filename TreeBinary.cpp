#include <iostream>
using namespace std;
template <typename T>
class Node{
public:
	Node() {
		left = 0;
		right = 0;
	}
	Node(T _data)data(_data) {};
private:
	T data;
	Node* left;
	Node* right;
};
template <typename T>
class TreeBinary {
public:
	TreeBinary()
		:m_numNode(0)
	{
		root = 0;
		root->left = 0;
		root->right = 0;
	}
	~TreeBinary() {
		RemoveAll(root);
	}
	RemoveAll(Node* delNode) {
		if (delNode) {
			RemoveAll(delNode->left);
			RemoveAll(delNode->right);
			delete delNode;
		}
	}
	Preorder(Node* travel) {
		cout << travel->data << " ";
		Preorder(travel->left);
		Preorder(travel->right);
	}
	Inorder(Node* travel) {
		Preorder(travel->left);
		cout << travel->data << " ";
		Preorder(travel->right);
	}
	Postorder(Node* travel) {
		Preorder(travel->left);
		Preorder(travel->right);
		cout << travel->data << " ";
	}

private:
	Node<T>* root;
	int m_numNode;
};