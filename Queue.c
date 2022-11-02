#include <stdio.h>
#define SIZE 5
#define INV 999

int Q[SIZE];
int front = -1;
int rear = -1;

void enqueue(int item)
{
    if (-1 == rear)
    {
        rear = 0;
        front = 0;
        Q[rear] = item;
    }
    else
    {
        if (rear < SIZE - 1)
        {
            rear = rear + 1;
            Q[rear] = item;
        }
        else
            printf("cannot enqueue queue full \n");
    }
}

int dequeue()
{
    int item;
    if (-1 == front)
    {
        printf("Queue empty, cannot dequeue\n");
        return INV;
    }
    else if (front <= rear)
    {
        item = Q[front];
        front = front + 1;
        return item;
    }
    else
    {
        printf("Queue underflow\n");
    }
}

void displayq()
{
    int i;
    printf("Queue is \n");
    for (i = front; i <= rear; i++)
    {
        printf("%d   ", Q[i]);
    }
}

void main()
{
    int val, item;
    char opt;
    do
    {
        printf("\n_______________________________________________\n");
        printf("Queue\n");
        printf("1. Enqueue (e)\n2. Dequeue (d) \n3. Exit (q)\n");
        printf("Enter option : ");
        scanf(" %c", &opt);
        switch (opt)
        {
        case 'e':
            printf("Enter item to enqueue : ");
            scanf("%d", &val);
            enqueue(val);
            displayq();
            break;
        case 'd':
            item = dequeue();
            if (item != INV)
            {
                printf("Dequeued item is %d\n", item);
            }
            displayq();
            break;
        default:
            break;
        }
    } while (opt != 'q');
}