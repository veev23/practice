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
		if (this->root==NULL) {	//�θ�Ŭ������ ���� ����� ������ this�����͸� ��� 
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
	Node<T>* Search(T key) {
		Node<T>* tmp = this->root;
		while (tmp) {
			if (key == tmp->data)
				return tmp;
			else if (key > tmp->data) {
				tmp = tmp->right;
			}
			else tmp = tmp->left;
		}
		return NULL;
	}
	bool Remove(T key) {
		Node<T>* delNode = this->root;
		Node<T>* delP=NULL;//delParent
		Node<T>* replace, *replaceP=NULL;//delParent
		
		while (delNode->data != key) {
			if (delNode == NULL) return false;
			if (delNode->data < key) {
				delP = delNode;
				delNode = delNode->right;
			}
			else {
				delP = delNode;
				delNode = delNode->left;
			}
		}

		//��� 1 : delNode�� ������ �ڽ��� ������
		if (delNode->right == NULL) {
			replace = delNode->left;
		}
		//��� 2 : delNode�� ������ �ڽ��� ���� �ڽ��� ������
		else if (delNode->right->left == NULL) {
			replace = delNode->right;
			replace->left = delNode->left;
		}
		//��� 3 : �̿�, delNode�� ������ �ڽ��� ���� ���� ���� replace�� ���Ѵ�.
		else {
			replace = delNode->right;
			while (replace->left != NULL) {
				replaceP = replace;
				replace = replace->left;
			}
			replaceP->left = replace->right;
			replace->left = delNode->left;
			replace->right = delNode->right;
		}
		if(delP!=NULL){
			if (delP->data < key) delP->right = replace;
			else delP->left = replace;
		}
		else this->root = replace;
		cout << "del:" << delNode->data << "\n";
		delete delNode;
		return true;
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
	B.Remove(4);
	B.PreorderPrint();
	return 0;
}