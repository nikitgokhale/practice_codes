#include <bits/stdc++>

using namespace str;

int partition(int arr[], int start, int end)
{
	int pivot = arr[end];
	int partitionIndex = start; // set the partition index at the start initially

	for (int i=0; i<=end-1; i++){
		if (arr[i] <= pivot){
			swap(arr[i], arr[partitionIndex]);  // swap if the element is lesser than the pivot
			partitionIndex += 1;
		}
	}
	swap(arr[partitionIndex], arr[end]);  // swap the pivot with the elemenat the partition index
	return partitionIndex;
}

void QuickSort(int arr[], int start, int end)
{
	if (start >= end)
		return;
	// Divide and Conquer
	int partitionIndex = partition(arr, start, end);
	// Recursive calls to the divided array
	QuickSort(arr, start, partitionIndex-1); // To the left side of the pivot
	QuickSort(arr, partitionIndex+1, end);   // To the right side of the pivot
}

int main()
{
	int arr[] = {7, 2, 1, 4, 8, 5, 3, 6};
	int start = 0;
	int end = sizeof(arr)/sizeof(arr[0]);
	QuickSort(arr, start, end);

	// Printing the sorted array
	for (int i = 0; i < end; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}