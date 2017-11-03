#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

//struct Node *head;

//void Insert(struct Node **head_ptr , int x);
void InsertN(struct Node **head_ptr, int x, int n);
void Delete(struct Node **head_ptr, int n);
void Print(struct Node *head);

void InsertN(struct Node **head_ptr, int x, int n) {
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = x;
    temp1->next = NULL;
    
    if (n == 1) {
        temp1->next = *head_ptr;
        *head_ptr = temp1;
        return;
    }
    struct Node *temp2 = *head_ptr;

    for (int i=0; i < n-2; i++) {
        temp2 = temp2->next;
    }

    temp1->next = temp2-> next;
    temp2->next = temp1;
}

void Delete(struct Node **head_ptr, int n){

    struct Node *temp1 = *head_ptr;

    for (int i=0; i < n-2; i++) { // Go to the (n-1)th node.
        temp1 = temp1->next;
    }
    
    struct Node *temp2 = temp1->next; // (n)th node.

    temp1->next = temp2->next; //(n+1)th node.

    free(temp2);
}

#if 0
void Insert(struct Node **head_ptr, int x, int n) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(*head_ptr != NULL) temp->next = *head_ptr;
    *head_ptr = temp;
}
#endif

void Print(struct Node *head) {
    //struct Node *temp = head;

    printf("List is: ");
    while(head != NULL) {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {

    struct Node *head;
    int i, n, x, num;

    head = NULL;

    printf("How many Numbers?: ");
    scanf("%d", &num);

    for (i=0; i < num; i++) {
        printf("Enter Number: ");
        scanf("%d", &x);

        printf("Enter Position: ");
        scanf("%d", &n);

        if ( (n < i+1) & (n > 0) ){
            //Insert(&head, x);
            InsertN(&head, x, n);
            Print(head);
        }
        else printf("OUT of RANGE...Skipping\n");
    }
    
    printf("Enter Position to Delete: ");
    scanf("%d", &n);

    Delete(&head, n);
    Print(head);

    return 0;
}