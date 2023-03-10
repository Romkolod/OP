

#include <iostream>


using namespace std;
int main()
{
	char string[] = "hochuapnut4000elo";
	char string1[] = "yaklountuda";
	cout << strlen(string) << endl; // cout a lengt of string without 0-symbol
	strcpy_s(string, string1); // copy symbols from string1 to string
	cout << "string - " << string << endl;
	char string2[] = "kudaidem";
	char string3[] = "vinstitute";
	cout << strcmp(string2, string3)<< endl; //compare  string2 with string3 and return result: 0 - if string are equivalent, >0 if string2 < string3, < 0 if string2 > string3






    const int max_size = 20;
    const int max_length = 11;
    char words[max_size][max_length];

    int n;
    cout << "Enter the number of words: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter word #" << i + 1 << ": ";
        cin >> words[i];
    }

    cout << "Words with even indices: ";
    for (int i = 0; i < n; i++) {
        if (i % 2 != 0) {
            cout << words[i] << " ";
        }
    }

    return 0;
}

