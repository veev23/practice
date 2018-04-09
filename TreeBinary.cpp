#include <iostream>
using namespace std;
template <typename T>
class Node {
public:
	Node() {
		left = 0;
		right = 0;
	}
	Node(T _data) :data(_data) {};
	template <typename T> friend class TreeBinary;
	T data;
	Node* left;
	Node* right;
};
template <typename T>
class TreeBinary {
protected:
	Node<T>* root;
	int m_numNode;
public:
	TreeBinary()
		:m_numNode(0)
	{
		cout << "BT constructor" << endl;
	}
	TreeBinary(T _data)
		:m_numNode(1)
	{
		root = new Node<T>(_data);
		cout << "BT constructor, data : " << root->data << endl;
	}
	~TreeBinary() {
		RemoveAll(root);
		cout << "BT destructor" << endl;
	}
	void RemoveAll(Node<T>* delNode) {
		if (delNode) {
			RemoveAll(delNode->left);
			RemoveAll(delNode->right);
			cout << delNode->data << " delete\n";
			delete delNode;
		}
	}
	void PreorderPrint() {
		Preorder(root);
	}
	void Preorder(Node<T>* travel) {
		if (travel) {
			cout << "visit " << travel->data << endl;
			Preorder(travel->left);
			Preorder(travel->right);
		}
	}
	void InorderPrint() {
		Inorder(root);
	}
	void Inorder(Node<T>* travel) {
		if (travel) {
			Inorder(travel->left);
			cout << "visit " << travel->data << endl;
			Inorder(travel->right);
		}
	}
	void PostorderPrint() {
		Postorder(root);
	}
	void Postorder(Node<T>* travel) {
		if (travel) {
			Postorder(travel->left);
			Postorder(travel->right);
			cout << "visit " << travel->data << endl;
		}
	}
	int GetNodeNumber() {
		return m_numNode;
	}
};
