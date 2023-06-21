#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

void readData(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cin >> *(arr + i);
	}
}

void solve(int* arr, int size, int k) {
	for (int i = 0; i <= size - k; i++)
	{
		int max = arr[i];
		for (int j = i; j < i + k; j++)
		{
			if (arr[j] > max) {
				max = arr[j];
			}
		}
		cout << max << " ";
	}
	cout << endl;
}

int main() {
	int t;
	int n;
	int k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		int* numbers = new int[n];
		readData(numbers, n);
		solve(numbers, n, k);
		delete[] numbers;
	}

	return 0;
}