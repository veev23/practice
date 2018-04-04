#include <iostream>
#include <ctime>
using namespace std;
#define number 20
template <typename T>
void MergeSort(T arr[], int left, int right) {
	if (right - left <= 1) return;
	int mid = (right + left) / 2;
	MergeSort(arr, left, mid);
	MergeSort(arr, mid, right);
	int a = left, b = mid, c = 0;
	int *temp = new int[right - left + 1];
	while (c < right - left) {
		if (b < right)
			if (*(arr + a) >= *(arr + b)) {
				temp[c++] = *(arr + (b++));
			}
		if (a < mid)
			if (*(arr + a) < *(arr + b)) {
				temp[c++] = *(arr + (a++));
			}
		if (a == mid) {
			temp[c++] = *(arr + (b++));
		}
		if (b == right) {
			temp[c++] = *(arr + (a++));
		}
	}
	for (int i = left; i < right; i++) {
		arr[i] = temp[i - left];
	}
	delete[] temp;
}
int main() {
	srand(time(0));
	int arr[number];// = { 36, 30, 31, 49, 36, 9, 19, 23, 46, 29 };
	for (int i = 0; i < number; i++) {
		arr[i] = rand() % 50;
		cout << arr[i] << " ";
	}
	clock_t a = clock();
	MergeSort(arr, 0, number);
	clock_t b = clock();
	cout << "\n";
	for (int i = 0; i < number; i++) cout << arr[i] << " ";
	cout << "\n" << b - a << "ms\n";
	return 0;
}

