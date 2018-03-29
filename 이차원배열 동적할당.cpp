#include <iostream>
using namespace std;
void foo(int **a, int row, int col){
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			a[i][j] = col * i + j;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int main(){
	int **arr;
	int row, col;//컬러열쇠(컬럼열, 세로)
	cin >> row >> col;
	arr = new int*[row];
	for (int i = 0; i < row; i++) {
		arr[i] = new int[col]; 
	}
	foo(arr,row,col);
	cout << "2";
	for (int i = 0; i < row; i++) {
		delete [] arr[i];
		cout << "1";
	}
	cout << "2";
	delete [] arr;
	system("pause");
	return 0;

}