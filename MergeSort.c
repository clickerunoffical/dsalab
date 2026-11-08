
/* Program: Merge Sort */

#include <stdio.h>

void printArray(int arr[], int n)
{
int i;
for (i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
}

void merge(int arr[], int left, int mid, int right)
{
int L[50], R[50];
int n1, n2;
int i, j, k;

n1 = mid - left + 1;
n2 = right - mid;

for (i = 0; i < n1; i++)
L[i] = arr[left + i];

for (j = 0; j < n2; j++)
R[j] = arr[mid + 1 + j];

i = 0;
j = 0;
k = left;

while (i < n1 && j < n2)
{
if (L[i] <= R[j])
{
arr[k] = L[i];
i++;
}
else
{
arr[k] = R[j];
j++;
}
k++;
}

while (i < n1)
{
arr[k] = L[i];
i++;
k++;
}

while (j < n2)
{
arr[k] = R[j];
j++;
k++;
}
}

void mergeSort(int arr[], int left, int right)
{
int mid;

if (left < right)
{
mid = (left + right) / 2;

mergeSort(arr, left, mid);
mergeSort(arr, mid + 1, right);

merge(arr, left, mid, right);
}
}

int main()
{
int arr[50], n, i;

printf("Enter the number of elements: ");
scanf("%d", &n);

printf("Enter the array elements:\n");
for (i = 0; i < n; i++)
scanf("%d", &arr[i]);

printf("\nOriginal Array: ");
printArray(arr, n);

mergeSort(arr, 0, n - 1);

printf("Sorted Array: ");
printArray(arr, n);

return 0;
}

/* Sample Output:

Enter the number of elements: 7
Enter the array elements:
8 3 1 7 0 10 2

Original Array: 8 3 1 7 0 10 2
Sorted Array: 0 1 2 3 7 8 10

Result: The given array is sorted in ascending order using Merge Sort.

*/

// Algorithm: Merge Sort

// 1. Start.
// 2. Read the number of elements n.
// 3. Read the array elements.
// 4. Display the original array.
// 5. Call mergeSort(arr, 0, n-1).
// 6. Check whether left < right.
// 7. Find the middle position:
//    mid = (left + right) / 2.
// 8. Divide the array into two halves.
// 9. Recursively sort the left half.
// 10. Recursively sort the right half.
// 11. Merge the two sorted halves:
//     a. Copy elements into temporary arrays L and R.
//     b. Compare elements of both arrays.
//     c. Insert the smaller element into the original array.
//     d. Copy remaining elements from L.
//     e. Copy remaining elements from R.
// 12. Display the sorted array.
// 13. Stop.
