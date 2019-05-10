#include <cstdio>
#include<iostream>
#include<iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

int arr[100010];
int n, i, j,left_child,right_child,largest,temp,heapsize;

void Max_Heapify(int i);
void Build_Max_Heap(); ///맨 처음 맥스 힙 만듬
void HeapSort();  ///힙정렬

void Max_Heapify(int i) {
	left_child = 2*i;
	right_child = 2 * i + 1;
	largest = i;
	if (left_child <= heapsize && arr[left_child] > arr[i])
		largest = left_child;
	if (right_child <= heapsize && arr[right_child] > arr[largest])
		largest = right_child;
	if (largest != i) { ///자식노드가 더 큰 경우
		temp = arr[i];           ///
		arr[i] = arr[largest];  /////
		arr[largest] = temp;   ///////arr[i] 와 arr[largest] swap
		Max_Heapify(largest);
	}

}
void Build_Max_Heap() {
	heapsize = 100000;
	for (j = heapsize/2; j >= 1; j--) 
		Max_Heapify(j);
}
void HeapSort() {
	Build_Max_Heap();///맨처음에 맥스 힙 만듬


	for (j = 100000; j >= 2; j--) { ///루트 a[1] 은 자동정렬되서 2까지만 함
		temp = arr[j];           ///
		arr[j] = arr[1];  
		arr[1] = temp;
		heapsize = heapsize - 1;
		Max_Heapify(1);
	}
}
int main() {

	srand((unsigned)time(NULL));
	for (i = 1; i <= 100000; i++) {       /////heapSort는 인덱스 편하기 하기위해 arr[1]부터 값 집어넣음
		arr[i] = rand();                  //////렌덤으로 10만개 난수 생성

	}

	cout << "array Before  HeapSort" << "\n";
	//for (i = 1; i <= 100000; i++)
		//cout << setw(2) << arr[i] << " ";            /////////////정렬되기 전 데이터 10만개 출력
	cout << "\n";


	HeapSort();				//do HeapSort



	cout << "array After HeapSort" << "\n";
	for (i = 1; i <= 100000; i++)
		cout << setw(2) << arr[i] << " ";			/////////////정렬 후 데이터 10만개 출력
	cout << "\n";

	return 0;
}

