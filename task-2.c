#include<stdio.h>
#include<stdlib.h>

//structure of the node.
struct Node{
int data;
struct Node*next;
};

//Head pointer
struct Node* head = NULL;
// function to insert at end 
void insert(int value) {
    struct Node *newNode = malloc(sizeof *newNode);  // pointer type, memory allocated
    if (!newNode) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("inserted %d\n", value);
}
//function to delete a node 
void delete_node(int value){
    struct Node* temp=head;
    struct Node* prev=NULL;
    if(temp!=NULL && temp -> data==value){
    head = temp-> next;
    free(temp);
    printf("deleted %d\n",value);
    return;
}
while(temp!=NULL && temp ->data != value){
    prev=temp;
    temp=temp->next;
}

if(temp == NULL){
    printf("value %d not found \n",value);
    return;
}
prev->next = temp-> next;
free(temp);
printf("deleted %d\n",value);
}
// function to traverse a list 
void traverse(){
struct Node* temp = head;
if(temp == NULL){
    printf("list is empty\n");
    return;
}
printf("linkedlist:");
while(temp!=NULL){
    printf("%d->",temp->data);
    temp = temp->next;
}
printf("NULL\n");
}

   // Main function
int main() {
    int choice, value;

    do {
        printf("\n---- Linked List Menu ----\n");
        printf("1. Insert\n2. Delete\n3. Traverse\n4. Exit\n");
        printf("Enter your choice: ");

        // Check for valid integer input for menu
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                insert(value);
                break;

            case 2:
                printf("Enter the value to delete: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                delete_node(value);
                 break;

            case 3:
                traverse();
                break;

            case 4:
                printf("Exiting... This program implements a singly linked list in C.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
 }