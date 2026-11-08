
/* Program: Browser Navigation Using Doubly Linked List */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
char url[100];
struct Node *prev;
struct Node *next;
};

struct Node *current = NULL;

/* Visit a new page */
void visit(char url[])
{
struct Node *newNode;

newNode = (struct Node *)malloc(sizeof(struct Node));

strcpy(newNode->url, url);

newNode->prev = current;
newNode->next = NULL;

if (current != NULL)
{
current->next = newNode;
}

current = newNode;

printf("Visited: %s\n", current->url);
}

/* Go back */
void back()
{
if (current == NULL || current->prev == NULL)
printf("Cannot go back.\n");
else
{
current = current->prev;
printf("Moved back to: %s\n", current->url);
}
}

/* Go forward */
void forward()
{
if (current == NULL || current->next == NULL)
printf("Cannot go forward.\n");
else
{
current = current->next;
printf("Moved forward to: %s\n", current->url);
}
}

/* Display current page */
void display()
{
if (current == NULL)
printf("No page visited.\n");
else
printf("Current Page: %s\n", current->url);
}

int main()
{
int choice;
char url[100];

do
{
printf("\n--- Browser Navigation ---\n");
printf("1. Visit New Page\n");
printf("2. Go Back\n");
printf("3. Go Forward\n");
printf("4. Display Current Page\n");
printf("5. Exit\n");

printf("Enter choice: ");
scanf("%d", &choice);
getchar();

switch(choice)
{
case 1:
printf("Enter URL: ");
fgets(url, 100, stdin);
url[strlen(url) - 1] = '\0';
visit(url);
break;

case 2:
back();
break;

case 3:
forward();
break;

case 4:
display();
break;

case 5:
printf("Exiting...\n");
break;

default:
printf("Invalid choice!\n");
}

} while(choice != 5);

return 0;
}

/* Sample Output:

--- Browser Navigation ---
1. Visit New Page
2. Go Back
3. Go Forward
4. Display Current Page
5. Exit
Enter choice: 1
Enter URL: https://google.com
Visited: https://google.com

Enter choice: 1
Enter URL: https://youtube.com
Visited: https://youtube.com

Enter choice: 1
Enter URL: https://facebook.com
Visited: https://facebook.com

Enter choice: 2
Moved back to: https://youtube.com

Enter choice: 3
Moved forward to: https://facebook.com

Enter choice: 4
Current Page: https://facebook.com

Enter choice: 5
Exiting...

*/

// Algorithm: Browser Navigation Using Doubly Linked List

// 1. Start.
// 2. Initialize current = NULL.
// 3. Display the menu:
//    1. Visit New Page.
//    2. Go Back.
//    3. Go Forward.
//    4. Display Current Page.
//    5. Exit.
// 4. Read the user's choice.

// 5. If choice is 1 (Visit New Page):
//    a. Read the URL.
//    b. Create a new node.
//    c. Copy the URL into the node.
//    d. Set newNode->prev = current.
//    e. Set newNode->next = NULL.
//    f. If current is not NULL, set current->next = newNode.
//    g. Set current = newNode.

// 6. If choice is 2 (Go Back):
//    a. Check whether current is NULL or current->prev is NULL.
//    b. If true, display Cannot go back.
//    c. Otherwise, move current to current->prev.
//    d. Display the previous page.

// 7. If choice is 3 (Go Forward):
//    a. Check whether current is NULL or current->next is NULL.
//    b. If true, display Cannot go forward.
//    c. Otherwise, move current to current->next.
//    d. Display the next page.

// 8. If choice is 4 (Display Current Page):
//    a. Check whether current is NULL.
//    b. If true, display No page visited.
//    c. Otherwise, display the current URL.

// 9. If choice is 5, display Exiting and terminate.
// 10. Otherwise, display Invalid choice.
// 11. Repeat the menu until Exit is selected.
// 12. Stop.
