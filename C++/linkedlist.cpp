#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
///*Singly Linked List
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void Insert(int);
void Insert(int, int);
void Print();
void Print(struct Node *);
void Traverse(int);
void Search(int);
void Deletion(int);
void Reverse();
void Reverse(struct Node *);
int main()
{
    int n, i, k;
    printf("Enter the no. of numbers: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number: ");
        scanf("%d", &k);
        Insert(k);
    }
    Print();
    printf("Enter the node whose data you need: ");
    scanf("%d", &k);
    Traverse(k);
    printf("Enter the data you need to search: ");
    scanf("%d", &k);
    Search(k);
    printf("Enter the data: ");
    scanf("%d", &k);
    printf("Enter the node: ");
    scanf("%d", &i);
    Insert(k, i);
    Print();
    printf("Enter the node: ");
    scanf("%d", &i);
    Deletion(i);
    Print();
    Reverse(head);
    Print(head);
    return 0;
}
void Insert(int x)
{
    struct Node *temp = (Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}
void Insert(int x, int y)
{
    int i;
    struct Node *temp1 = (Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    if (y == 1)
    {
        temp1->data = x;
        temp1->next = head;
        head = temp1;
    }
    else
    {
        for (i = 1; i < (y - 1); i++)
        {
            temp = temp->next;
        }
        temp1->data = x;
        temp1->next = temp->next;
        temp->next = temp1;
    }
}
void Deletion(int y)
{
    int i;
    struct Node *temp = head;
    if (y == 1)
    {
        head = temp->next;
        free(temp);
    }
    else
    {
        for (i = 1; i < (y - 1); i++)
        {
            temp = temp->next;
        }
        struct Node *temp1;
        temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }
}
void Print()
{
    struct Node *temp = head;
    printf("List is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// Reverse Print using Recursion
void Print(struct Node *x)
{
    if (x != NULL)
    {
        Print(x->next);
        printf("%d ", x->data);
        return;
    }
    else
    {
        return;
    }
}
void Traverse(int x)
{
    struct Node *temp = head;
    int i;
    for (i = 0; i < (x - 1); i++)
    {
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}
void Search(int x)
{
    struct Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        i++;
        if (temp->data == x)
        {
            printf("%d exists at node %d\n", x, i);
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("%d doesnt exist in linked list\n", x);
    }
}
void Reverse()
{
    struct Node *temp = head;
    struct Node *temp1 = temp->next;
    struct Node *temp2 = temp->next;
    temp->next = NULL;
    while (temp1 != NULL)
    {
        temp2 = temp2->next;
        temp1->next = temp;
        temp = temp1;
        temp1 = temp2;
    }
    head = temp;
}
void Reverse(struct Node *x)
{
    if (x->next == NULL)
    {
        head = x;
        return;
    }
    struct Node *prev = x->next;
    Reverse(prev);
    prev = x;
    x = x->next;
    // if head wouldnt be global variable we would have had to update the next of head
    // if (x == head)
    //{
    //     head->next = prev;
    // }
    x->next = prev;
    prev->next = NULL;
}
//*/

// Doubly linked list
/*
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head = NULL;
struct Node *tail = NULL;
struct Node* NewNode(int);
void InsertHead(int);
void InsertTail(int);
void Insert(int, int);
void Deletion(int);
void Print();
void Traverse(int);
void Search(int);
int main()
{
    int n, i, k;
    printf("Enter the no. of numbers: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number: ");
        scanf("%d", &k);
        InsertHead(k);
    }
    Print();
    printf("Enter the node whose data you need: ");

    scanf("%d", &k);
    Traverse(k);
    printf("Enter the data you need to search: ");
    scanf("%d", &k);
    Search(k);
    printf("Enter the data: ");
    scanf("%d", &k);
    printf("Enter the node: ");
    scanf("%d", &i);
    Insert(k, i);
    Print();
    printf("Enter the node: ");
    scanf("%d", &i);
    Deletion(i);
    Print();

    return 0;
}
struct Node* NewNode(int x){
    struct Node *NewNode = (Node *)malloc(sizeof(struct Node));
    NewNode->data=x;
    NewNode->next=NULL;
    NewNode->prev=NULL;
    return NewNode
}
void InsertHead(int x)
{
    struct Node *temp = NewNode(x);
    if (head == NULL)
    {
        head = temp;
        tail = head;
    }
    else if (head == tail)
    {
        temp->next = head;
        tail->prev = temp;
        head = temp;
    }
    else
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}
void Insert(int x, int y)
{
    int i;
    struct Node *temp1 = (Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    if (y == 1)
    {
        temp1->data = x;
        temp1->next = head;
        head = temp1;
    }
    else
    {
        for (i = 1; i < (y - 1); i++)
        {
            temp = temp->next;
        }
        temp1->data = x;
        temp1->next = temp->next;
        temp->next = temp1;
    }
}
void Print()
{
    struct Node *temp = head;
    printf("List is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void Traverse(int x)
{
    struct Node *temp = head;
    int i;
    for (i = 0; i < (x - 1); i++)
    {
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}
void Search(int x)
{
    struct Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        i++;
        if (temp->data == x)
        {
            printf("%d exists at node %d\n", x, i);
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("%d doesnt exist in linked list\n", x);
    }
}
void Deletion(int x) {}
//*/