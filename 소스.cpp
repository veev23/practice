
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	string fileName;
	cout << "저장할 파일의 이름을 정해주세요." << endl;
	cin >> fileName;
	ofstream out(fileName, ios::app);
	int num;
	cout << "숫자를 입력하세요. -1 입력시 종료" << endl;
	try {
		cin >> num;
		if (num != -1)
			out << num;
		else cout << "입력 실패" << endl;
		while (num != -1) {
			cin >> num;
			if (num == -1)
				break;
			out << " " << num;
		}
	}
	catch (char* e) { cout << e << endl; }
	out.close();
	cout << "입력 완료" << endl;
	cout << "불러올 파일의 이름을 입력하세요." << endl;
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
			cout << fn << "은 열리지 않았습니다.\n";
			cout << "다시 입력하세요. -1입력시 종료\n";
			cin >> fileName;
			if (fileName == "-1") break;
		}
	}
	inf.close();
	cout << endl;

	system("pause");
	return 0;
}