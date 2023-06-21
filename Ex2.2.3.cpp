#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

void showResult(string* words, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << words[i] << " ";
	}
	cout << endl;
}

void splitWord(string* words, string input, int& size) {
	string str;
	stringstream ss(input);
	while (ss >> str) {
		words[size++] = str;
	}
}

int main() {
	int n;
	cin >> n;
	cin.ignore();
	while (n--) {
		string input;
		getline(cin, input);
		string* words = new string[input.length()];
		int numOfWords = 0;
		splitWord(words, input, numOfWords);
		sort(words, words + numOfWords);
		showResult(words, numOfWords);
		delete[] words;
	}

	return 0;
}