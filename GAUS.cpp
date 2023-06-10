// GAUS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
string path1 = "C: / Users / dom - 2 / source / repos / GAUS / input.txt";
string path2 = "C:/Users/dom-2/source/repos/GAUS/output.txt";

ifstream fin;
ofstream fout;
using namespace std;
double eps = 0.000001;
double E[6];

int r = 0;
int f(int n, int m, float** A, float* X, int* L)
{

    for (int i = 0; i < n; i++) L[i] = i;


    int i = 0, j, k, p;
    float z, c;
    if (n < m) r = n; else r = m;
    while (i < r)
    {
        int v = i, u = i;
        for (j = i; j < m; j++)
            for (k = i; k < n; k++)
                if (abs(A[j][k]) > abs(A[v][u])) { v = j; u = k; }


        if (abs(A[v][u]) < eps) r = i;
        else
        {
            if (v != i)
                for (j = i; j <= n; j++)
                {
                    z = A[i][j]; A[i][j] = A[v][j]; A[v][j] = z;
                }

            if (u != i)
            {
                for (k = 0; k < m; k++)
                {
                    z = A[k][i]; A[k][i] = A[k][u]; A[k][u] = z;
                }
                p = L[i]; L[i] = L[u]; L[u] = p;
            }

            c = A[i][i];
            for (j = i; j <= n + 1; j++) A[i][j] /= c;

            for (k = 0; k < m; k++)
                if (k != i)
                {
                    c = A[k][i];
                    for (j = i; j <= n; j++) A[k][j] -= c * A[i][j];
                }

            i++;
        }

    }
    return 0;
}
int main()
{
    fin.open(path1);
    fout.open(path2);


    if (!fin.is_open() and !fout.is_open())
    {
        printf("Error");
    }
    else
    {
        int i, j, g, n, m; float** A, * X; int* L;
        fin >> m >> n;
        //fin >> n;

        fout << m << ' ' << n << endl;
        X = new float[n]; A = new  float* [n]; L = new int[n];
        for (i = 0; i < m; i++)
        {
            A[i] = new float[n + 1];
            for (j = 0; j <= n; j++) fin >> A[i][j];
        }
        f(n, m, A, X, L);
    }
    fin.close();
    fout.close();
    return 0;
}