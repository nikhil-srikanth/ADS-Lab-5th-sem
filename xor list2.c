#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} node;

node *head, *tail;

node *xor(node *a, node *b)
{
    return (node *) ((unsigned int) a ^ (unsigned int) b);
}

void insert()
{   int item;

    printf("Enter the elements: ");
    scanf("%d",&item);
    node *ptr = (node*) malloc(sizeof(node));
    ptr->data = item;

    if (NULL == head) {
        ptr->link = NULL;
        head = tail = ptr;
    } else if (ptr == tail) {
        ptr->link = xor(tail, NULL);
        tail->link = xor(ptr, xor(tail->link, NULL));
        tail = ptr;
    } else {
        ptr->link = xor(NULL, head);
        head->link = xor(ptr, xor(NULL, head->link));
        head = ptr;
    }
}

int delete()
{
    int item;
    node *ptr;
    if (NULL == head) {
        printf("Empty list.\n");
        exit(1);
    } else if (ptr->link==NULL) {
        ptr = tail;
        item = ptr->data;
        node *prev = xor(ptr->link, NULL);
        if (NULL == prev) head = NULL;
        else prev->link= xor(ptr, xor(prev->link, NULL));
        tail = prev;

    } else {
        ptr = head;
        item = ptr->data;
        node *next = xor(NULL, ptr->link);
        if (NULL == next) tail = NULL;
        else next->link = xor(ptr, xor(NULL, next->link));
        head = next;
    }
    free(ptr);
    ptr = NULL;
    return item;
}

void display()
{
    node *curr = head;
    node *prev = NULL, *next;

    printf("\nList elements are : ");
    while (NULL != curr) {
        printf("%d ", curr->data);
        next = xor(prev, curr->link);
        prev = curr;
        curr = next;
    }

    printf("\n");
}

int main()
{int i,item,n;
 int ch;
 printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
 while (1)
 {
 printf("Enter your choice:\n");
 scanf("%d",&ch);
 switch(ch)
 { case 1: printf("enter the number of elements: ");
           scanf("%d", &n);
           for(i=0;i<n;i++)
            {
               insert();
            }
           break;

   case 2: for (int i = 1; i <= 4; i++){
           {item=delete();}
           break;

   case 3: display();
           break;
   case 4: exit (0);
   default: printf("Invalid choice");
 }
}
}
}
