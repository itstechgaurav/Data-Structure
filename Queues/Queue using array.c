#include <stdio.h>
#include <stdlib.h>

typedef struct Queue_DT
{
    int size, front, rear;
    int *storage;
} Queue;

Queue initalize()
{
    Queue queue;
    printf("Enter the size of queue: ");
    scanf("%d", &queue.size);

    queue.front = queue.rear = -1;
    queue.storage = (int *)malloc(sizeof(int) * queue.size);

    return queue;
}

int isEmpty(Queue queue)
{
    return queue.front > queue.rear;
}

int isFull(Queue queue)
{
    return queue.rear == queue.size - 1;
}

void enqueue(Queue *queue)
{
    if (isFull(*queue))
    {
        printf("Queue is Full!!!\n");
    }
    else
    {
        queue->rear++;
        printf("Enter a element: ");
        scanf("%d", &queue->storage[queue->rear]);

        if (queue->front == -1)
            queue->front = queue->rear;
    }
}

void dequeue(Queue *queue)
{
    if (isEmpty(*queue))
    {
        printf("Queue is Empty");
    }
    else
    {
        queue->front++;
        if (isFull(*queue) && isEmpty(*queue))
            queue->front = queue->rear = -1;
    }
}

void display(Queue queue)
{
    while (queue.front <= queue.rear)
    {
        printf("%d ", queue.storage[queue.front]);
        queue.front++;
    }
}

int main()
{
    Queue queue = initalize();
    int ch = 1;

    while (ch >= 1 && ch <= 3)
    {
        printf("\n\n");
        printf("1: Enqueue\n");
        printf("2: Dequeue\n");
        printf("3: Display\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if (ch == 1)
            enqueue(&queue);
        else if (ch == 2)
            dequeue(&queue);
        else if (ch == 3)
            display(queue);
    }
}
