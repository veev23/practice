
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	string fileName;
	cout << "������ ������ �̸��� �����ּ���." << endl;
	cin >> fileName;
	ofstream out(fileName, ios::app);
	int num;
	cout << "���ڸ� �Է��ϼ���. -1 �Է½� ����" << endl;
	try {
		cin >> num;
		if (num != -1)
			out << num;
		else cout << "�Է� ����" << endl;
		while (num != -1) {
			cin >> num;
			if (num == -1)
				break;
			out << " " << num;
		}
	}
	catch (char* e) { cout << e << endl; }
	out.close();
	cout << "�Է� �Ϸ�" << endl;
	cout << "�ҷ��� ������ �̸��� �Է��ϼ���." << endl;
	cin >> fileName;
	ifstream inf;
	while (1) {
		inf.open(fileName);
		try {
			if (!inf.is_open()) throw fileName;

			while (!inf.eof()) {
				inf >> num;
				cout << num << " ";
			}
			break;
		}
		catch (string fn) {
			cout << fn << "�� ������ �ʾҽ��ϴ�.\n";
			cout << "�ٽ� �Է��ϼ���. -1�Է½� ����\n";
			cin >> fileName;
			if (fileName == "-1") break;
		}
	}
	inf.close();
	cout << endl;

	system("pause");
	return 0;
}