#include <iostream>
#include <cmath>
#include <ctime>
#define number 20
using namespace std;
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void sort1(int arr[]){ //bubble
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number - i-1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void sort2(int arr[]) {//selection
	for (int i = 0; i < number; i++) {
		int min = i;
		for (int j = i; j < number; j++) {
			if (arr[j] < arr[min])
				min = j;
		}
		swap(arr[i], arr[min]);
	}
}
void sort3(int arr[]) {//insertion
	for (int i = 0; i < number-1; i++) {
		int j = i+1;
		while (arr[j] < arr[j - 1]) {
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	srand(time(0));
	int arr[number];
	for (int i = 0; i < number; i++) {
		arr[i] = rand() % 50;
		cout << arr[i] << " ";
	}

	clock_t a = clock();
	sort3(arr);
	clock_t b = clock();
	cout << "\n";
	for (int i = 0; i < number; i++) cout << arr[i] << " ";
	cout << "\n" << b-a << "ms\n";
	return 0;
}