//INPUT
/*
10
1 2 3 4 5 6 7 0 9 8
*/

//OUTPUT
/*
6 1 8 5 0 2 9 4 7 3 
0 1 2 3 4 5 6 7 8 9 
*/

//CODE
#include <iostream>
using namespace std;
void randomShuffle(int arr[], int n)
{
    // function to shuffle the array elements into random positions
    int i, j;
    for (i = n - 1; i > 0; i--)
    {
        j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
// Partitioning the array on the basis of values at high as pivot value.
int Partition(int a[], int low, int high)
{
    int i, index = low, pivot = high;
    for (i = low; i < high; i++)
        // finding index of pivot.
        if (a[i] < a[pivot])
        {
            swap(a[i], a[index]);
            index++;
        }
    swap(a[pivot], a[index]);
    return index;
}
int randomPivotPartition(int a[], int low, int high)
{
    // Random selection of pivot.
    int n = rand(), pivot = low + n % (high - low + 1); // Randomizing the pivot value from sub-array.
    swap(a[high], a[pivot]);
    return Partition(a, low, high);
}
void quickSort(int arr[], int p, int q)
{
    // recursively sort the list
    int pIndex;
    if (p < q)
    {
        pIndex = randomPivotPartition(arr, p, q); // randomly choose pivot
        // Recursively implementing QuickSort.
        quickSort(arr, p, pIndex - 1);
        quickSort(arr, pIndex + 1, q);
    }
}
int main()
{
    int i, n;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];
    randomShuffle(arr, n);         // To randomize the array
    quickSort(arr, 0, n - 1); // sort the elements of array
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}