#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define SIZE 10001

bool symmetryCheck(int* a, int size) {
	int l = 0, r = size - 1;
	while (l <= r) {
		if (a[l] != a[r]) {
			return false;
		}
		++l;
		--r;
	} 
	return true;
}

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
		if (symmetryCheck(a,size)){
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}