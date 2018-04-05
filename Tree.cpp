#include <iostream>
using namespace std;
template <typename T>
class Node{
public:
	Node() {
		next = 0;
	}
	Node(T _data)data(_data) {};
private:
	T data;
	Node* next;
};
template <typename T>
class Tree {
public:
	Tree() {}

private:
	Node<T> root;
	int m_numNode;
};
int main() {
}