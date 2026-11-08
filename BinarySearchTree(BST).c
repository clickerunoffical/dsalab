
/* Program: Dictionary Using Binary Search Tree (BST) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
char word[50];
char meaning[100];
struct Node *left, *right;
};

struct Node *createNode(char word[], char meaning[])
{
struct Node *newNode;
newNode = (struct Node *)malloc(sizeof(struct Node));
strcpy(newNode->word, word);
strcpy(newNode->meaning, meaning);
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}

struct Node *insert(struct Node *root, char word[], char meaning[])
{
if(root == NULL)
return createNode(word, meaning);

if(strcmp(word, root->word) < 0)
root->left = insert(root->left, word, meaning);
else if(strcmp(word, root->word) > 0)
root->right = insert(root->right, word, meaning);

return root;
}

void search(struct Node *root, char word[])
{
if(root == NULL)
{
printf("Word not found.\n");
return;
}

if(strcmp(word, root->word) == 0)
printf("Meaning: %s\n", root->meaning);
else if(strcmp(word, root->word) < 0)
search(root->left, word);
else
search(root->right, word);
}

void inorder(struct Node *root)
{
if(root != NULL)
{
inorder(root->left);
printf("%s : %s\n", root->word, root->meaning);
inorder(root->right);
}
}

int main()
{
struct Node *root = NULL;
int choice;
char word[50], meaning[100];

while(1)
{
printf("\n1. Insert Word");
printf("\n2. Search Word");
printf("\n3. Display Dictionary");
printf("\n4. Exit");

printf("\nEnter choice: ");
scanf("%d", &choice);

if(choice == 1)
{
printf("Enter word: ");
scanf("%s", word);

printf("Enter meaning: ");
scanf(" %[^\n]", meaning);

root = insert(root, word, meaning);
}
else if(choice == 2)
{
printf("Enter word to search: ");
scanf("%s", word);

search(root, word);
}
else if(choice == 3)
{
printf("\nDictionary:\n");
inorder(root);
}
else if(choice == 4)
{
break;
}
else
{
printf("Invalid choice.\n");
}
}

return 0;
}

/* Sample Input and Output:

1. Insert Word
2. Search Word
3. Display Dictionary
4. Exit

Enter choice: 1
Enter word: Apple
Enter meaning: A fruit

Enter choice: 1
Enter word: Computer
Enter meaning: An electronic device

Enter choice: 1
Enter word: Ball
Enter meaning: A round object

Enter choice: 3

Dictionary:
Apple : A fruit
Ball : A round object
Computer : An electronic device

Enter choice: 2
Enter word to search: Ball
Meaning: A round object

Enter choice: 4

*/

// Algorithm: Dictionary Using Binary Search Tree (BST)

// 1. Start.
// 2. Initialize root = NULL.
// 3. Display the menu:
//    a. Insert Word.
//    b. Search Word.
//    c. Display Dictionary.
//    d. Exit.
// 4. Read the user's choice.

// 5. If choice is 1 (Insert Word):
//    a. Read the word and its meaning.
//    b. Create a new node.
//    c. If the root is NULL, make the new node the root.
//    d. If the word is smaller than the root word, insert it into the left subtree.
//    e. If the word is greater than the root word, insert it into the right subtree.

// 6. If choice is 2 (Search Word):
//    a. Read the word to search.
//    b. Compare it with the root word.
//    c. If both words are equal, display the meaning.
//    d. If the word is smaller, search the left subtree.
//    e. Otherwise, search the right subtree.
//    f. If the word is not found, display Word not found.

// 7. If choice is 3 (Display Dictionary):
//    a. Perform inorder traversal.
//    b. Visit the left subtree.
//    c. Display the word and its meaning.
//    d. Visit the right subtree.
//    e. Display words in alphabetical order.

// 8. If choice is 4, exit the program.
// 9. Otherwise, display Invalid choice.
// 10. Repeat the menu until Exit is selected.
// 11. Stop.
