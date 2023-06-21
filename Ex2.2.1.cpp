#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

bool primeCheck(int n) {
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) {
			return false;
		}
	}
	return n > 1;
}

#define SIZE 100001

int main() {
	int n;
	cin >> n;
	while (n--) {
		int size;
		cin >> size;
		int a[SIZE];
		for (int i = 0; i < size; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < size; i++)
		{
			if (primeCheck(a[i])) {
				cout << a[i];
				if (i != size - 1) {
					cout << " ";
				}
				else {
					cout << endl;
				}
			}
		}
	}
	return 0;
}