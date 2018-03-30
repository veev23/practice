#include <iostream>
using namespace std;
//단일 링크드 리스트
template <class T>
class LinkedList;
template <class T>
class node {
	T data;
	node<T>* pNext;
public:
	template <class U> friend class LinkedList;
	node(T _data) :data(_data){
		pNext = NULL;
	}
	T getData() const{
		return data;
	};
	void setData(T _data) {
		data = _data;
	}
};
template <class T>
class LinkedList {
public:
	LinkedList()
		:count(0){
	head = NULL;
	tail = NULL;
	}
	~LinkedList() {
		node<T>* temp;
		for (int i = 0; i < count; i++) {
			temp = head;
			head = temp->pNext;
			delete temp;
		}
		delete head, tail;
	}
	node<T>* push_back(T _data) {
		node<T>* temp = new node<T>(_data);
		temp->data = _data;
		if (!head) {
			head = temp;
			tail = temp;
		}
		else{
			tail->pNext = temp; //꼬리 잇기, 여기서의 tail은 (구)node, temp는 (신)node
			tail = temp;//맨 마지막을 (신)node로 갱신 
		}
		count++;
		return temp;
	}
	node<T>* insert(T _data, int index=count) {//n번째 원소로 넣는 함수. if index==1, 맨 첫번째 원소로 들어감
		if (index < 1 || index > count) {
			cout << "현재 가진 원소의 개수 밖입니다." << endl;
			return NULL;
		}
		node<T>* temp = new node<T>(_data);
		temp->data = _data;
		if (index == 1) {
			temp->pNext = head;
			head = temp;
		}
		else {//index > 1
			node<T>* reposit = head;//head == 첫번째 원소
			for (int i = 2; i < index; i++) {
				reposit = reposit->pNext;
			}
			temp->pNext = reposit->pNext;
			reposit->pNext = temp;
		}
		return temp;
	}
	void deleteNode(int index) {
		if (index < 1 || index > count) {
			cout << "현재 가진 원소의 개수 밖입니다." << endl;
			return;
		}
		node<T>* deleteTemp;
		if (index == 1) {
			deleteTemp = head;
			head = head->pNext;
		}
		else {//index > 1
			node<T>* reposit = head;
			for (int i = 2; i < index; i++) {
				reposit = reposit->pNext;
			}
			deleteTemp = reposit->pNext;
			reposit->pNext=reposit->pNext->pNext;
		}
		delete deleteTemp;
		count--;
		return;
//		return returnReposit;
	}
	void print() {
		if (head) {
			node<T>* temp = new node<T>(0);
			temp = head;
			while (temp) {
				cout << temp->data << " ";
				temp=temp->pNext;
			}
			cout << endl;
		}
	}
private:
	int count;
	node<T>* head;
	node<T>* tail;
};
int main()
{
	LinkedList<int> link;
	link.push_back(1);
	link.push_back(2);
	link.push_back(3);
	link.push_back(4);
	link.push_back(5);
	link.print();
	link.insert(6, 3);
	link.print();
	link.deleteNode(2);
	link.print(); 
	link.insert(7, 1);
	link.print();
	link.deleteNode(1);
	link.print();
	link.deleteNode(3);
	link.print();
	system("pause");
	return 0;
}
