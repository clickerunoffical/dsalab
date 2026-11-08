
/* Program: Circular Queue Using Array */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int cqueue[MAX];
int front = -1;
int rear = -1;
int count = 0;

int isEmpty()
{
return count == 0;
}

int isFull()
{
return count == MAX;
}

void insert()
{
int item;
if (isFull())
printf("Queue Overflow\n");
else
{
printf("Enter element: ");
scanf("%d", &item);
if (isEmpty())
front = rear = 0;
else
rear = (rear + 1) % MAX;
cqueue[rear] = item;
count++;
}
}

void delete()
{
if (isEmpty())
printf("Queue Underflow\n");
else
{
printf("Deleted: %d\n", cqueue[front]);
if (front == rear)
{
front = rear = -1;
}
else
{
front = (front + 1) % MAX;
}
count--;
}
}

void display()
{
int i;
if (isEmpty())
printf("Queue is empty\n");
else
{
printf("Queue: ");
i = front;
while (1)
{
printf("%d ", cqueue[i]);
if (i == rear)
break;
i = (i + 1) % MAX;
}
printf("\n");
}
}

void peek()
{
if (isEmpty())
printf("Queue is empty\n");
else
printf("Front element: %d\n", cqueue[front]);
}

void size()
{
printf("Size: %d\n", count);
}

int main()
{
int choice;
while (1)
{
printf("\n1. Insert");
printf("\n2. Delete");
printf("\n3. Display");
printf("\n4. Peek");
printf("\n5. Size");
printf("\n6. Exit");
printf("\nEnter choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
insert();
break;
case 2:
delete();
break;
case 3:
display();
break;
case 4:
peek();
break;
case 5:
size();
break;
case 6:
exit(0);
default:
printf("Invalid choice\n");
}
}
return 0;
}

/* Sample Output:

1. Insert
2. Delete
3. Display
4. Peek
5. Size
6. Exit

Enter choice: 1
Enter element: 10
Enter choice: 1
Enter element: 20
Enter choice: 1
Enter element: 30
Enter choice: 3
Queue: 10 20 30
Enter choice: 4
Front element: 10
Enter choice: 5
Size: 3
Enter choice: 2
Deleted: 10
Enter choice: 3
Queue: 20 30
Enter choice: 5
Size: 2
Enter choice: 6

*/

// Algorithm: Circular Queue Using Array
// 1. Start.
// 2. Initialize front = -1, rear = -1 and count = 0.
// 3. Display the menu with Insert, Delete, Display, Peek, Size and Exit options.
// 4. Read the user's choice.
// 5. If choice is 1, perform Insert:
//    a. Check whether the queue is full.
//    b. If full, display Queue Overflow.
//    c. Otherwise, read the element.
//    d. If the queue is empty, set front = rear = 0.
//    e. Otherwise, update rear = (rear + 1) % MAX.
//    f. Insert the element and increment count.
// 6. If choice is 2, perform Delete:
//    a. Check whether the queue is empty.
//    b. If empty, display Queue Underflow.
//    c. Otherwise, display the deleted element.
//    d. If front == rear, set front = rear = -1.
//    e. Otherwise, update front = (front + 1) % MAX.
//    f. Decrement count.
// 7. If choice is 3, display all queue elements from front to rear.
// 8. If choice is 4, display the front element.
// 9. If choice is 5, display the size of the queue.
// 10. If choice is 6, terminate the program.
// 11. Otherwise, display Invalid choice.
// 12. Repeat the menu until Exit is selected.
// 13. Stop.
