#include <bits/stdc++.h>

using namespace std;
/* Binary Search is a method to find the required element in a sorted array by
   repeatedly halving the array and searching in the half
 */
int binarySearch(vector<int> arr, int left, int right, int x)
{
    // Base Case
    if (left > right)
        return -1;
    // Shrinking the problem
    int mid = (left + right) / 2;

    if (x == arr[mid])
        return mid;

    if (x < arr[mid])
        return binarySearch(arr, left, mid-1, x);

    return binarySearch(arr, mid+1, right, x);
}

int main()
{
    vector<int> arr{1, 3, 7, 15, 18, 20, 25, 33, 36, 40};
    int x;
    cout << "Enter the element to be searched: ";
    cin >> x;

    int res = binarySearch(arr, 0, arr.size()-1, x);
    if (res == -1)
        cout << "Number not found!!";
    else
        cout << "Number found at index: " << res;

    return 0;
}
