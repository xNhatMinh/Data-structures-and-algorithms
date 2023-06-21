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

int sum(int* arr, int size) {
	int res = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i + 1] > arr[i]) {
			res += arr[i + 1];
		}
	}
	return res;
}

int main() {
	int t;
	int n;
	cin >> t;
	while (t--) {
		cin >> n;
		int* numbers = new int[n];
		readData(numbers, n);
		cout << sum(numbers, n) << endl;
		delete[] numbers;
	}

	return 0;
}