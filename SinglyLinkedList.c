
/* Program: Singly Linked List (Insertion, Deletion and Traversal) */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
int info;
struct Node *link;
};

struct Node *head = NULL;

/* Insert at End */
void insertAtEnd(int value)
{
struct Node *newNode;
newNode = (struct Node *)malloc(sizeof(struct Node));
newNode->info = value;
newNode->link = NULL;

if (head == NULL)
{
head = newNode;
}
else
{
struct Node *temp = head;
while (temp->link != NULL)
{
temp = temp->link;
}
temp->link = newNode;
}
}

/* Insert at Beginning */
void insertAtBeginning(int value)
{
struct Node *newNode;
newNode = (struct Node *)malloc(sizeof(struct Node));
newNode->info = value;
newNode->link = head;
head = newNode;
}

/* Insert after a Key */
void insertAfterKey(int value, int key)
{
struct Node *temp = head;

while (temp != NULL && temp->info != key)
{
temp = temp->link;
}

if (temp == NULL)
{
printf("Key not found!\n");
return;
}

struct Node *newNode;
newNode = (struct Node *)malloc(sizeof(struct Node));
newNode->info = value;
newNode->link = temp->link;
temp->link = newNode;
}

/* Delete at Beginning */
void deleteAtBeginning()
{
if (head == NULL)
{
printf("List is empty!\n");
return;
}

struct Node *temp = head;
head = head->link;
free(temp);
}

/* Delete by Key */
void deleteByKey(int key)
{
if (head == NULL)
{
printf("List is empty!\n");
return;
}

/* If first node contains the key */
if (head->info == key)
{
struct Node *temp = head;
head = head->link;
free(temp);
return;
}

struct Node *prev = NULL;
struct Node *temp = head;

while (temp != NULL && temp->info != key)
{
prev = temp;
temp = temp->link;
}

if (temp == NULL)
{
printf("Key not found!\n");
return;
}

prev->link = temp->link;
free(temp);
}

/* Delete at End using prev pointer */
void deleteAtEnd()
{
if (head == NULL)
{
printf("List is empty!\n");
return;
}

if (head->link == NULL)
{
free(head);
head = NULL;
return;
}

struct Node *prev = NULL;
struct Node *temp = head;

while (temp->link != NULL)
{
prev = temp;
temp = temp->link;
}

free(temp);
prev->link = NULL;
}

/* Display / Traversal */
void display()
{
if (head == NULL)
{
printf("List is empty!\n");
return;
}

struct Node *temp = head;
printf("Linked List: ");

while (temp != NULL)
{
printf("%d -> ", temp->info);
temp = temp->link;
}

printf("NULL\n");
}

/* Main Function */
int main()
{
int choice, value, key;

while (1)
{
printf("\n--- Singly Linked List Operations ---\n");
printf("1. Insert at End\n");
printf("2. Insert at Beginning\n");
printf("3. Insert after Key\n");
printf("4. Delete at Beginning\n");
printf("5. Delete at End\n");
printf("6. Delete by Key\n");
printf("7. Display List\n");
printf("8. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice)
{
case 1:
printf("Enter value: ");
scanf("%d", &value);
insertAtEnd(value);
break;

case 2:
printf("Enter value: ");
scanf("%d", &value);
insertAtBeginning(value);
break;

case 3:
printf("Enter value to insert: ");
scanf("%d", &value);
printf("Enter key: ");
scanf("%d", &key);
insertAfterKey(value, key);
break;

case 4:
deleteAtBeginning();
break;

case 5:
deleteAtEnd();
break;

case 6:
printf("Enter key to delete: ");
scanf("%d", &key);
deleteByKey(key);
break;

case 7:
display();
break;

case 8:
exit(0);

default:
printf("Invalid choice!\n");
}
}

return 0;
}

/* Sample Output:

--- Singly Linked List Operations ---
1. Insert at End
2. Insert at Beginning
3. Insert after Key
4. Delete at Beginning
5. Delete at End
6. Delete by Key
7. Display List
8. Exit

Enter your choice: 1
Enter value: 10

Enter your choice: 1
Enter value: 20

Enter your choice: 1
Enter value: 30

Enter your choice: 1
Enter value: 40

Enter your choice: 7
Linked List: 10 -> 20 -> 30 -> 40 -> NULL

Enter your choice: 2
Enter value: 5

Enter your choice: 7
Linked List: 5 -> 10 -> 20 -> 30 -> 40 -> NULL

Enter your choice: 3
Enter value to insert: 25
Enter key: 20

Enter your choice: 7
Linked List: 5 -> 10 -> 20 -> 25 -> 30 -> 40 -> NULL

Enter your choice: 6
Enter key to delete: 30

Enter your choice: 7
Linked List: 5 -> 10 -> 20 -> 25 -> 40 -> NULL

Enter your choice: 4

Enter your choice: 7
Linked List: 10 -> 20 -> 25 -> 40 -> NULL

Enter your choice: 5

Enter your choice: 7
Linked List: 10 -> 20 -> 25 -> NULL

Enter your choice: 8

*/

// Algorithm: Singly Linked List (Insertion, Deletion and Traversal)

// 1. Start.
// 2. Initialize head = NULL.

// 3. Display the menu:
//    1. Insert at End.
//    2. Insert at Beginning.
//    3. Insert after Key.
//    4. Delete at Beginning.
//    5. Delete at End.
//    6. Delete by Key.
//    7. Display List.
//    8. Exit.

// 4. Read the user's choice.

// 5. If choice is 1 (Insert at End):
//    a. Create a new node.
//    b. Store the value in the node.
//    c. Set link = NULL.
//    d. If head == NULL, set head = newNode.
//    e. Otherwise, traverse to the last node.
//    f. Link the last node to the new node.

// 6. If choice is 2 (Insert at Beginning):
//    a. Create a new node.
//    b. Store the value.
//    c. Set newNode->link = head.
//    d. Set head = newNode.

// 7. If choice is 3 (Insert after Key):
//    a. Read the value and key.
//    b. Search for the key.
//    c. If key is not found, display Key not found.
//    d. Otherwise, create a new node.
//    e. Set newNode->link = temp->link.
//    f. Set temp->link = newNode.

// 8. If choice is 4 (Delete at Beginning):
//    a. Check whether the list is empty.
//    b. If empty, display List is empty.
//    c. Otherwise, store head in temp.
//    d. Move head to head->link.
//    e. Free the old first node.

// 9. If choice is 5 (Delete at End):
//    a. Check whether the list is empty.
//    b. If empty, display List is empty.
//    c. If only one node exists, free it and set head = NULL.
//    d. Otherwise, traverse to the last node using temp and prev.
//    e. Free the last node.
//    f. Set prev->link = NULL.

// 10. If choice is 6 (Delete by Key):
//     a. Check whether the list is empty.
//     b. If the first node contains the key, delete it.
//     c. Otherwise, search for the key using temp and prev.
//     d. If key is not found, display Key not found.
//     e. Otherwise, link the previous node to the next node.
//     f. Free the node.

// 11. If choice is 7 (Display List):
//     a. Check whether the list is empty.
//     b. If empty, display List is empty.
//     c. Otherwise, start from head.
//     d. Display each node's value.
//     e. Move to the next node until NULL.
//     f. Display NULL.

// 12. If choice is 8, exit the program.
// 13. Otherwise, display Invalid choice.
// 14. Repeat the menu until Exit is selected.
// 15. Stop.
