
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	FILE* f;
	char ch;
	int n, k, mxk, k2;
	string str, mxstr, mxl, start, start2;
	string word[50];
	ifstream file;
	file.open("test1.txt");
	n = 0;
	k = 0;
	mxk = 0;
	while (getline(file, start)) {
		start2 += start;
		start2 += " ";
	}
	cout << start2 << endl;
	for (int i = 0; i < start2.length(); i++) {
		if (start2[i] != ' ') {
			word[n] += start2[i];
		}
		else {
			while (start2[i] == ' ') {
				i++;
			}
			n++;
			word[n] += start2[i];
		}
	}
	for (int i = 0; i <= n; i++) {
		str = word[i];
		int l = str.length();
		for (int j = 0; j <= n; j++) {
			if ((i != j) && (str == word[j].substr(0, l))) {
				k++;
			}

		}
		if (mxk < k) {
			mxk = k;
			mxstr = str;
		}
		if ((k > 0) && (str.length() > mxl.length())) {
			mxl = str;
		}
		k = 0;
	}
	cout << mxl;
	ofstream res1;
	res1.open("res1.txt");
	if (mxl.empty()) {
		res1 << "NO";
	}
	else {
		res1 << mxl << ' ';
		for (int i = 0; i <= n; i++) {
			int l = mxl.length();
			if ((word[i] != mxl) && (mxl == word[i].substr(0, l))) {
				res1 << word[i] << ' ';
			}
		}
	}
	res1.close();
	ofstream res2;
	res2.open("res2.txt");
	if (mxstr.empty()) {
		res2 << "NO";
	}
	else {
		res2 << mxstr << ' ' << mxk;
	}
	res2.close();
}