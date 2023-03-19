// Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
void random(int arr[100000], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 18;
	}
}
void sort(int arr[100000], int n) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[j] > arr[j + 1]) {
				int b = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = b;
			}
		}
	}
}
void out(int arr[100000], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}
void pack(int arrp[18], int arr[100000], int n) {
	for (int i = 0; i < n; i++) {
		int x = arr[i];
		arrp[x] += 1;
	}
}
void unpack(int arr2[100000], int arrp[18], int n) {
	int i = 0;
	int j = 0;
	while (j != n) {
		if (arrp[i] != 0) {
			arr2[j] = i;
			arrp[i] -= 1;
			j++;
		}
		else i++;
	};
}

int main()
{
	int n;
	cin >> n;
	int arr1[100000];
	int arrp[18];
	int arr2[100000];
	for (int i = 0; i < n; i++) {
		arr2[i] = 0;
	}
	for (int i = 0; i < 18; i++) {
		arrp[i] = 0;
	}
	int* p = arrp;
	random(arr1, n);
	sort(arr1, n);
	out(arr1, n);
	cout << endl;
	cout << endl;
	pack(p, arr1, n);
	out(arrp, 18);
	cout << endl;
	cout << endl;
	unpack(arr2, arrp, n);
	out(arr2, n);
}



