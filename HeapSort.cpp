#include <cstdio>
#include<iostream>
#include<iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

int arr[100010];
int n, i, j,left_child,right_child,largest,temp,heapsize;

void Max_Heapify(int i);
void Build_Max_Heap(); ///�� ó�� �ƽ� �� ����
void HeapSort();  ///������

void Max_Heapify(int i) {
	left_child = 2*i;
	right_child = 2 * i + 1;
	largest = i;
	if (left_child <= heapsize && arr[left_child] > arr[i])
		largest = left_child;
	if (right_child <= heapsize && arr[right_child] > arr[largest])
		largest = right_child;
	if (largest != i) { ///�ڽĳ�尡 �� ū ���
		temp = arr[i];           ///
		arr[i] = arr[largest];  /////
		arr[largest] = temp;   ///////arr[i] �� arr[largest] swap
		Max_Heapify(largest);
	}

}
void Build_Max_Heap() {
	heapsize = 100000;
	for (j = heapsize/2; j >= 1; j--) 
		Max_Heapify(j);
}
void HeapSort() {
	Build_Max_Heap();///��ó���� �ƽ� �� ����


	for (j = 100000; j >= 2; j--) { ///��Ʈ a[1] �� �ڵ����ĵǼ� 2������ ��
		temp = arr[j];           ///
		arr[j] = arr[1];  
		arr[1] = temp;
		heapsize = heapsize - 1;
		Max_Heapify(1);
	}
}
int main() {

	srand((unsigned)time(NULL));
	for (i = 1; i <= 100000; i++) {       /////heapSort�� �ε��� ���ϱ� �ϱ����� arr[1]���� �� �������
		arr[i] = rand();                  //////�������� 10���� ���� ����

	}

	cout << "array Before  HeapSort" << "\n";
	//for (i = 1; i <= 100000; i++)
		//cout << setw(2) << arr[i] << " ";            /////////////���ĵǱ� �� ������ 10���� ���
	cout << "\n";


	HeapSort();				//do HeapSort



	cout << "array After HeapSort" << "\n";
	for (i = 1; i <= 100000; i++)
		cout << setw(2) << arr[i] << " ";			/////////////���� �� ������ 10���� ���
	cout << "\n";

	return 0;
}

