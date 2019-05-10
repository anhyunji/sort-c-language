#include <cstdio>
#include<iostream>
#include<iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

int arr[100010];
int n, i, j;

void quick_sort(int left,int right); // left is first index of array, 
									// right is last index of array
int main() {

	srand((unsigned)time(NULL));   
	for (i = 0; i < 100000; i++) {
		arr[i] = rand();                  //////렌덤으로 10만개 난수 생성

	}

	cout << "array Before  QuickSort" << "\n";
	//for (i = 0; i < 100000; i++)
		//cout << setw(2) << arr[i] << " ";            /////////////정렬되기 전 데이터 10만개 출력
	cout << "\n";

	quick_sort(0,99999); //do quick sort 0번째 index부터 99999까지



	cout << "array After QuickSort" << "\n";
	for (i = 0; i < 100000; i++)
		cout << setw(2) << arr[i] << " ";			/////////////정렬 후 데이터 10만개 출력
	cout << "\n";

	return 0;
}

void quick_sort(int left, int right) {
	int temp, low = left + 1, high = right; //left is index of pivot value

	while (low <= high) {
		while (low <= right && arr[low] <= arr[left])
			low++;
		while (high >= left+1 && arr[high] >= arr[left])
			high--;
		if (low <= high) {
			temp = arr[low];    //// 
			arr[low] = arr[high]; // exchange arr[low] and arr[high]
			arr[high] = temp; ////
		}
	}
	temp = arr[left];    //// 
	arr[left] = arr[high]; // exchange arr[left] and arr[high]
	arr[high] = temp; ////

	if(left<high) // if size of array is bigger than one, then divide
		quick_sort(left, high - 1); 
	if(low<right) // if size of array is bigger than one, then divide
		quick_sort(low, right); // quick_sort(high+1, right) is okay. high is now index of pivot value
}

