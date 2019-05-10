#include <cstdio>
#include<iostream>
#include<iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

int arr[100010]; 
int n, i, j;

void insertion_sort();

int main() {

	srand((unsigned)time(NULL));
	for (i = 0; i < 100000; i++) {
		arr[i] = rand();                  //////create 100,000 data randomly

	}

	cout << "array Before  InsertionSort" << "\n";
	for (i = 0; i < 100000; i++)
		cout << setw(2) << arr[i] << " ";            /////////////print 100,000 date before sorting
	cout << "\n";


	insertion_sort(); //do InsertionSort 

	cout << "array After InsertionSort" << "\n";
	for (i = 0; i < 100000; i++)
		cout << setw(2) << arr[i] << " ";             /////////////print 100,000 date after sorting
	cout << "\n";

	return 0;
}

void insertion_sort() {
	int key;

	for (i = 1; i < 100000; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && key < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
