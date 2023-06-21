#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 10001

void insert(int* arr, int x, int k, int& size) {
	if (k >= size) {
		arr[size] = x;
		++size;
	}
	else {
		for (int i = 0; i < size; i++)
		{
			if (i == k) {
				for (int j = size; j >= i; j--) {
					arr[j] = arr[j - 1];
				}
				arr[k] = x;
				++size;
			}
		}
	}
}

void showResult(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int* arr = new int[SIZE];
		int size;
		cin >> size;
		int x, k;
		cin >> k >> x;
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
		insert(arr, x, k, size);
		showResult(arr, size);
		delete[] arr;
	}

	return 0;
}