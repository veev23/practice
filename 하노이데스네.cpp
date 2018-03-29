#include <iostream>
using namespace std;
void hanoi(int, char, char, char);
int main() {
	
	hanoi(3, 'A', 'B', 'C');
	system("pause");
	return 0;
}
void hanoi(int n, char from, char temp, char destination) {//원판 n개를 from으로부터 destination까지 옮김
	if (n == 1) cout << "원판 1을 " << from << "에서 " << destination << "로 옮김." << endl; //맨 위 원판을 1이라고 생각
	else {
		hanoi(n - 1, from, destination, temp);//맨 아래 원판을 제외해서 n-1개를 바로 옆으로 옮김 
		cout << "원판 "<< n <<"을 " << from << "에서 " << destination << "로 옮김." << endl;
		hanoi(n - 1, temp, from, destination);//옆에 잠깐 맡겨뒀던 것을 목적지로 옮김
	};
	return;
}