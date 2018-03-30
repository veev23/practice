#include <iostream>
#include <cmath>
#include <ctime>
#define number 10 //worst case의 경우 16000개정도만 넘어가도 stack overflow
using namespace std;
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int partition(int arr[], int n) {
	int i = -1;
	int j = n - 1;
	int pivot = arr[n - 1];
	while (true) {
		while (arr[++i] < pivot);
		while (arr[--j] > pivot);
		if (i >= j) break;
		swap(arr[i], arr[j]);
	}
	swap(arr[i], arr[n - 1]);
	return i;
}
void quick_sort(int arr[], int n) {
	if (n > 1){
		int i = partition(arr, n);
		quick_sort(arr, i);
		quick_sort(arr+i+1, n-i-1);
	}
}
int main() {

	srand(time(0));
	int arr[number];
	for (int i = 0; i < number; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}

	clock_t a = clock();
	quick_sort(arr, number);
	clock_t b = clock();
	cout << "\n";
	for (int i = 0; i < number; i++) cout << arr[i] << " ";
	cout << "\n" << b - a << "ms\n";
	return 0;
}