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
	cout << sizeof(p); //20이 나온다
	//http://pangate.com/19 여기를 참고

	system("pause");
	return 0;
}