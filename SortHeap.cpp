#include <iostream>
#include <ctime>
using namespace std;
#define number 10
#define maximum 20000
template <typename T>
class Heap {
public:
	Heap():count(0)
	{};
	void insert(T data) {
		tree[++count] = data;
		UpHeap();
	};
	T extract() {
		T tmp = tree[1];
		tree[1] = tree[count--];
		DownHeap();
		return tmp;
	};
	void UpHeap() {
		int i = count;
		while (i > 1) {
			if (tree[i / 2] < tree[i]) {
				T tmp = tree[i / 2];
				tree[i / 2] = tree[i];
				tree[i] = tmp;
				i /= 2;
			}
			else break;
		}
	};
	void DownHeap() {
		int i = 2;
		while (i <= count) {
			if (tree[i] < tree[i + 1]) i++;
			if (tree[i / 2] < tree[i]) {
				T tmp = tree[i / 2];
				tree[i / 2] = tree[i];
				tree[i] = tmp;
				i *= 2;
			}
			else break;
		}
	};
	void sort(int arr[], int n) {
		for (int i = 0; i < n; i++) {
			insert(arr[i]);
		}
		for (int i = 0; i < n; i++) {
			arr[i] = extract();
		}
		cout << "\nHEAP SORT";
	};
private:
	T tree[maximum];
	int count;
};
int main() {
	Heap <int> h;
	srand(time(0));
	int arr[number];
	for (int i = 0; i < number; i++) {
		arr[i] = rand() % 50;
		cout << arr[i] << " ";
	}
	clock_t a = clock();
	h.sort(arr, number);
	clock_t b = clock();
	cout << "\n";
	for (int i = 0; i < number; i++) cout << arr[i] << " ";
	cout << "\n" << b - a << "ms\n";
	return 0;
}