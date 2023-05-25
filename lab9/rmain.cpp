#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class ReplaceMyString {
	/*private:
		string str1, str2;*/
public:
	/*ReplaceMyString(string a, string b) {
		str1 = a;
		str2 = b;
	}*/
	void replaceString(string a, string b) {
		string c;
		ifstream in;
		ofstream out;
		in.open("main.cpp");
		out.open("rmain.cpp");
		while (!in.eof()) {
			getline(in, c);
			if (c.find(a) == true) {
				c.replace(c.find(a), b.length(), b);
			}
			out << c << endl;
		}
		in.close();
		out.close();
	}
};

int main() {
	ReplaceMyString my;
	my.replaceString("IU", "IU is best");
	return 0;
}
