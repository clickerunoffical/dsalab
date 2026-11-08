
/* Program: Quick Sort */

#include <stdio.h>

void quickSort(int a[], int low, int high)
{
int i, j, pivot, temp;

if (low < high)
{
pivot = a[low];
i = low + 1;
j = high;

while (i <= j)
{
while (i <= high && a[i] <= pivot)
i++;

while (j >= low && a[j] > pivot)
j--;

if (i < j)
{
temp = a[i];
a[i] = a[j];
a[j] = temp;
}
}

temp = a[low];
a[low] = a[j];
a[j] = temp;

quickSort(a, low, j - 1);
quickSort(a, j + 1, high);
}
}

int main()
{
int a[50], n, i;

printf("Enter number of elements: ");
scanf("%d", &n);

printf("Enter array elements:\n");
for (i = 0; i < n; i++)
scanf("%d", &a[i]);

quickSort(a, 0, n - 1);

printf("Sorted array:\n");
for (i = 0; i < n; i++)
printf("%d ", a[i]);

return 0;
}

/* Sample Output:

Enter number of elements: 7
Enter array elements:
8 3 1 7 0 10 2

Sorted array:
0 1 2 3 7 8 10

*/

// Algorithm: Quick Sort

// 1. Start.
// 2. Read the number of elements n.
// 3. Read the array elements.
// 4. Call quickSort(a, 0, n-1).
// 5. Check whether low < high.
// 6. Select the first element as pivot.
// 7. Initialize i = low + 1 and j = high.
// 8. Repeat while i <= j:
//    a. Move i forward while a[i] <= pivot.
//    b. Move j backward while a[j] > pivot.
//    c. If i < j, swap a[i] and a[j].
// 9. Swap the pivot element with a[j].
// 10. Recursively apply Quick Sort to the left subarray.
// 11. Recursively apply Quick Sort to the right subarray.
// 12. Display the sorted array.
// 13. Stop.
