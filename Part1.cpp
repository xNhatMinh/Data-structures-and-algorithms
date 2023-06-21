#include <iostream>
#include <string>

using namespace std;

class Student {
public:
	string id;
	string fullName;
	int age;
};

int main() {

	Student* sPtr = new Student();
	sPtr->id = "SV001";
	sPtr->fullName = "Tran Van A";
	sPtr->age = 21;

	cout << "Student ID: " << sPtr->id << endl;
	cout << "Fullname: " << sPtr->fullName << endl;
	cout << "Age: " << sPtr->age << endl;
	char s1[] = "123";
	char s2[] = "2331";
	strcpy(s1, s2);
	cout << s1;


	return 0;
}

