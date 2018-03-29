#include <iostream>
#include <string>
using namespace std;
void newStrcopy(char *dest, char *sour) {
	while (*dest++ = *sour++) {
	};
}
int main() {
	char c[] = "123456789";
	char b[10] = { 0 };
	newStrcopy(b, c);
	cout << (int)b[9] << endl;
	cout << b << endl;
	system("pause");
	return 0;
}