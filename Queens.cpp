// Queens.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void place(int k, vector<int>& columns, vector<vector<int>>& results) {
    int n = columns.size();
    if (k == n) {
        results.push_back(columns);
        return;
    }
    for (int i = 0; i < n; i++) {
        bool isSafe = true;
        for (int j = 0; j < k; j++) {
            if (columns[j] == i || abs(columns[j] - i) == abs(j - k)) {
                isSafe = false;
                break;
            }
        }
        if (isSafe) {
            columns[k] = i;
            place(k + 1, columns, results);
        }
    }
}


int main()
{
    int k;
    cout << "Enter the number of queens: ";
    cin >> k;
    vector<vector<int>> results;
    vector<int> columns(k);
    place(0, columns, results);
    int Solutions = results.size();
    cout << "Number of solutions: " << Solutions << endl;
    cout << "Solutions:\n";
    for (int i = 0; i < Solutions; i++) {
        cout << "Solution " << i + 1 << ": ";
        for (int j = 0; j < k; j++) {
            cout << "(" << j << "," << results[i][j] << ")";
        }
        cout << endl;
    }
}
