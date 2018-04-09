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
		Node<T>*tmp= this->root;
		if (this->root==NULL) {	//부모클래스의 변수 사용할 때에는 this포인터를 사용 
			this->root = new Node<T>(_data);	//https://stackoverflow.com/questions/194492/accessing-protected-members-from-subclasses-gcc-vs-msvc
			this->m_numNode++;
			return;
		}
		while (true) {
			if (tmp->data < _data) {
				if (tmp->right) tmp = tmp->right;
				else {
					tmp->right = new Node<T>(_data);
					this->m_numNode++;
					return;
				}
			}
			else {
				if (tmp->left) tmp = tmp->left;
				else {
					tmp->left = new Node<T>(_data);
					this->m_numNode++;
					return;
				}
			}
		}
	}
};
int main() {
	TreeBinarySearch<int> B(4);
	B.insert(2);
	B.insert(1);
	B.insert(3);
	B.insert(6);
	B.insert(5);
	B.insert(7);
	B.PreorderPrint();
	return 0;
}