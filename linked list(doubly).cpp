#include <iostream>
using namespace std;
//���� ��ũ�� ����Ʈ
class node {
public:
	friend class linkedList;
	node() {
		preNode = NULL;
		nextNode = NULL;
	}
	int getData() {
		return data;
	}
private:
	int data;
	node* preNode; //���� ��带 ����Ű�� ������
	node* nextNode; //���� ��带 ����Ű�� ������
};
class linkedList {
public:
	linkedList() {
		head = NULL;
		tail = NULL;
	}
	~linkedList() {}
	void push_back(int _data) {
		node* newNode = new node;
		newNode->data = _data;
		if (!head) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->nextNode = newNode;
			newNode->preNode = tail;
			tail = newNode;
		}
		count++;
	}
	void insert(int _data, int index) {//n��° ĭ�� �����ϴ� �Լ� ex:insert(10, 1), 10�� �� ù��°ĭ�� ����  
		if (count == 0 || index > count) {
			push_back(_data);
		}
		else {
			node* newNode = new node;
			node* temp = head;
			newNode->data = _data;
			for (int i = 1; i < index; i++) {
				temp = temp->nextNode;
			}
			if (temp->preNode) {
				newNode->preNode = temp->preNode;
				temp->preNode->nextNode = newNode;
			}
			newNode->nextNode = temp;
			temp->preNode = newNode;
		}
	}
	void delNode(int index) {

	}
	void print() {
		node* temp = head;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->nextNode;
		}
		cout << endl;
	}
	void rprint() {//�������� print
		node* temp = tail;
		while (temp!=head) {
			cout << temp->data << " ";
			temp = temp->preNode;
		}
		cout << head->data;
		cout << endl;
	}
private:
	node* head;
	node* tail;
	int count;
};
int main()
{
	linkedList d;
	d.insert(10,3);
	d.push_back(20);
	d.insert(30,3);
	d.print();
	d.push_back(40);
	d.print();
	d.insert(15, 2);
	d.print();
	d.rprint();
	system("pause");
	return 0;
}
