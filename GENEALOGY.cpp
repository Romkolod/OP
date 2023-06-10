#include <iostream>
#include <fstream>

using namespace std;

const int MAXN = 1000;

int parent[MAXN];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    parent[find(y)] = find(x);
}

int main() {
    ifstream fin("input.txt");
    int n = 0, m = 0;
    fin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        fin >> x >> y;
        merge(x, y);
    }
    fin.close();

    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) {
            root++;
        }
    }

    ofstream fout("output.txt");
    fout << root << endl;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) {
            fout << i << " ";
            for (int j = 1; j <= n; j++) {
                if (find(j) == i) {
                    fout << j << " ";
                }
            }
            fout << endl;
        }
    }
    fout.close();

    return 0;
}