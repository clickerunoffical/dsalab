
/* Program: Insertion Sort */

#include <stdio.h>

void printArray(int arr[], int n)
{
int i;
for (i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
}

void insertionSort(int arr[], int n)
{
int i, j, key;

for (i = 1; i < n; i++)
{
key = arr[i];
j = i - 1;

while (j >= 0 && arr[j] > key)
{
arr[j + 1] = arr[j];
j--;
}

arr[j + 1] = key;
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

insertionSort(arr, n);

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

Result: The given array is sorted in ascending order using Insertion Sort.

*/

// Algorithm: Insertion Sort

// 1. Start.
// 2. Read the number of elements n.
// 3. Read the array elements.
// 4. Display the original array.
// 5. Set i = 1.
// 6. Repeat until i < n:
//    a. Set key = arr[i].
//    b. Set j = i - 1.
//    c. Repeat while j >= 0 and arr[j] > key:
//       i. Set arr[j + 1] = arr[j].
//       ii. Decrement j.
//    d. Set arr[j + 1] = key.
//    e. Increment i.
// 7. Display the sorted array.
// 8. Stop.
