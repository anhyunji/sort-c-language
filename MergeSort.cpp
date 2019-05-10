#include <cstdio>
#include<iostream>
#include<iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

int arr[100010];
int n, i, j, k, l;

void merge_sort(int left, int right); // left is first index of array, 
									  // right is last index of array
void merge(int left, int mid, int right);

int main() {
	srand((unsigned)time(NULL));
	for (i = 0; i < 100000; i++) {
		arr[i] = rand();                  //////create 100,000 data randomly

	}

	cout << "array Before MergeSort" << "\n";
	//for (i = 0; i < 100000; i++)
		//cout << setw(2) << arr[i] << " ";            /////////////print 100,000 date before sorting
	cout << "\n";


	merge_sort(0, 99999); //do quick sort 0번째 index부터 99999까지


	cout << "array After MergeSort" << "\n";
	for (i = 0; i < 100000; i++)
		cout << setw(2) << arr[i] << " ";			/////////////print 100,000 date after sorting
	cout << "\n";

	return 0;
}

void merge_sort(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid+1, right);
		merge(left, mid, right);
	}
}

void merge(int left, int mid, int right) {
	int sorted[100010];
	i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) 
			sorted[k++] = arr[i++];
		else 
			sorted[k++] = arr[j++];
	}
	while (i <= mid)
		sorted[k++] = arr[i++];
	while (j <= right)
		sorted[k++] = arr[j++];
	for (l = left; l <= right; l++)
		arr[l] = sorted[l];
}

