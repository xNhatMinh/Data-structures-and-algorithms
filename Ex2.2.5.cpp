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
void showResult(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << * (arr + i) << " ";
	}
	cout << endl;
}

void removeX(int* arr, int& size, int x) {
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == x) {
			for (int j = i; j < size - 1; j++) {
				arr[j] = arr[j + 1];
			}
			size--;
			i--; // xét lại phần tử mới tại vị trí i
		}
	}
}

int main() {
	int t; 
	int n; 
	int x; 
	cin >> t;
	while (t--) {
		cin >> n >> x;
		int* numbers = new int[n];
		readData(numbers, n);
		removeX(numbers, n, x);
		showResult(numbers, n);
		delete[] numbers;
	}

	return 0;
}