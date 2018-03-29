#include <iostream>
using namespace std;
void hanoi(int, char, char, char);
int main() {
	
	hanoi(3, 'A', 'B', 'C');
	system("pause");
	return 0;
}
void hanoi(int n, char from, char temp, char destination) {//���� n���� from���κ��� destination���� �ű�
	if (n == 1) cout << "���� 1�� " << from << "���� " << destination << "�� �ű�." << endl; //�� �� ������ 1�̶�� ����
	else {
		hanoi(n - 1, from, destination, temp);//�� �Ʒ� ������ �����ؼ� n-1���� �ٷ� ������ �ű� 
		cout << "���� "<< n <<"�� " << from << "���� " << destination << "�� �ű�." << endl;
		hanoi(n - 1, temp, from, destination);//���� ��� �ðܵ״� ���� �������� �ű�
	};
	return;
}