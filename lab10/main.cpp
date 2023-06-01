#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class myString {
private:
	string m_str;
public:
	myString(string s) {
		m_str = s;
	}
};

class ReadClass {
public:
	void showClass() {
		int count = 0;
		int i = 0;
		string a[3];
		string c;
		ifstream in;
		in.open("main.cpp");
		while (!in.eof()) {
			in >> c;
			if (c == "class") {
				a[i] = c;
				in >> c;
				if (c == "in") {
					a[i].erase();
					continue;
				}
				a[i] = a[i] + " " + c;
				count++;
				i++;
			}
		}
		cout << count << " class in main.cpp" << endl;
		for (i = 0; i < 3; i++) {
			cout << a[i] << endl;
		}
	}
};

int main() {
	ReadClass rfile;
	rfile.showClass();
	return 0;
}