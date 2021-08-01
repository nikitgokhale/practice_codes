#include<bits/stdc++.h>

using namespace std;

/* FUNCTION DECLARATIONS */
void merge(int* arr, int low, int mid, const int high);
void mergeSort(int* arr, int low, int high);

/* FUNCTION DEFINITIONS */
void merge(int* arr, int low, int mid, const int high)
{
	int* tmp = new int[high - low + 1];
	int i = low;
	int j = mid+1;
	int k = 0;
    // Traverse throught both the list and compare which one in smaller
    // the smaller one gets added in the tmp list first/
	while ((i <= mid) && (j <= high)) {
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
  // Add the rest of the elements left in array1
	while (i <= mid)
		tmp[k++] = arr[i++];
    // Add the rest of the elements left in array2
	while (j < high)
		tmp[k++] = arr[j++];
	k--;
	while (k >= 0) {
		arr[k + low] = tmp[k];
		k--;
	}
}

void mergeSort(int* arr, int low, int high)
{
	int mid = 0;
    // Base Condition
	if (low < high) {
		mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

int main()
{
	int array[] = { 95, 45, 48, 98, 5, 485, 65, 478, 1, 2325 };
	const int n = sizeof(array) / sizeof(array[0]);

	cout << "Array before sorting: ";
	for (auto itr: array) {
        cout << itr << " ";
	}
	cout << endl;

	mergeSort(array, 0, n - 1);
	cout << "Array after sorting: ";
	for (auto itr: array) {
        cout << itr << " ";
	}
	cout << endl;

	return 0;
}
