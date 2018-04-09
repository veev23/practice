#include "TreeBinary.cpp"
template <typename T>
class TreeBinarySearch
	:public TreeBinary<T>
{
public:
	TreeBinarySearch() {
		cout << "BST constructor" << endl;
	}
	TreeBinarySearch(T _data)
		:TreeBinary<T>(_data)
	{
		cout << "BST constructor, data : " << _data << endl;
	}
	~TreeBinarySearch() {
		cout << "BST destructor" << endl;
	}
	void insert(T _data) {
		Node<T>*tmp= root;
		if (root) {
			root = new Node<T>(_data);
			m_numNode++;
			return;
		}
		while (true) {
			if (tmp->data > _data) {
				if (tmp->right) tmp = tmp->right;
				else {
					tmp->right->data = _data;		
					m_numNode++;
					return;
				}
			}
			else {
				if (tmp->left) tmp = tmp->left;
				else { 
					tmp->left->data = _data;
					m_numNode++;
					return;
				}
			}
		}
	}
};
int main() {
	TreeBinarySearch<int> B(1);
	B.PreorderPrint();
//	B.insert(2);
	return 0;
}