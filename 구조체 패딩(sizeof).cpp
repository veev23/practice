#include <iostream>
using namespace std;
typedef struct pad {
	char c;
	int a;
	char b;
	int bb;
	char ccc;
}PAD;
int main() {
	pad p;
	cout << sizeof(p); //20�� ���´�
	//http://pangate.com/19 ���⸦ ����

	system("pause");
	return 0;
}