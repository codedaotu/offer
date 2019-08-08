#include<iostream>
#include<cstdlib>
using namespace std;
void merge(int a[], int *left, int leftcount, int *right,int rightcount) 
{
	int i, j, k;
	i = 0, j =0, k = 0;
	while (i < leftcount&&j < rightcount)
	{
		if (left[i] < right[j])
			a[k++] = left[i++];

		else a[k++] = right[j++];

	}

	while (i < leftcount)a[k++] = left[i++];

	while (j < rightcount)a[k++] = right[j++];

}
 
void mergeSort(int a[], int n) 

{

	int mid=n/2;

	if (n < 2) return;

	int *left = new int[mid];

	int *right = new int[n - mid ];

	for (int i = 0; i < mid; i++)

		left[i] = a[i];

	for (int j = mid ; j < n; j++)

		right[j-mid] = a[j];

 

	mergeSort(left, mid);

	mergeSort(right, n - mid);

	merge(a,left,mid,right,n-mid);

 

	delete[] left;

	delete[] right;

 

}

 

int main() 

{

	int a[] = { 2, 4, 6, 7, 0, 5, 88, 9, };

	int length = 8; 

	mergeSort(a, length);

	for (int i = 0; i < length; i++)

		cout << a[i] << " ";

	system("pause");

	return 0;

}
