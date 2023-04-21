#include <iostream>
using namespace std;

int main()
{
	int a;
	int b;
	char s[30];
	cin >> a;
	cout << a << endl;
	cout << endl;
	scanf_s("%d", &b); // enter the values of the variable b
	printf_s("b=%d", b); // print the value of the b variable
	cout << endl;
	FILE* f;
	fopen_s(&f, "test.txt", "w+");
	fputs("Test5\n", f); // write the string to the file
	fprintf(f, "%s %s %s %d", "We", "are", "in", 2023);
	fclose(f);

}
