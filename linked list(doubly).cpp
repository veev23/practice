#include <iostream>
using namespace std;
//더블 링크드 리스트
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
	node* preNode; //이전 노드를 가리키는 포인터
	node* nextNode; //다음 노드를 가리키는 포인터
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
	void insert(int _data, int index) {//n번째 칸에 삽입하는 함수 ex:insert(10, 1), 10을 맨 첫번째칸에 넣음  
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
	void rprint() {//역순으로 print
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
