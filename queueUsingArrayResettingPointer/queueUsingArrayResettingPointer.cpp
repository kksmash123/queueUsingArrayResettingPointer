//QueueUsingArrayResettingPointer - front ,rear two pointer are resetted to -1 
//whenever the front ==rear condition  satisfies ...queue empty
//but this won't helpful ...when the queue will not empty at all ...rear reached end of space
//still some space exist before front but can't be reused.



#include <iostream>

using namespace std;

struct queue
{
    int size;
    int front;
    int rear;
    int* arr;

};

bool IsEmpty(struct queue* );
bool IsFull(struct queue* );
void enqueue(struct queue*, int);
void dequeue(struct queue* );





void dequeue(struct queue *q)
{
    if (IsEmpty(q))
    {
        cout << "Queue is empty ...deletion not possible ." << endl;
        return;
    }


    cout << "The value -> " << q->arr[++q->front] << " deleted from the queue . " << endl;

}

void enqueue(struct queue* q, int x)
{
    if (IsEmpty(q))
    {
        q->front = q->rear = -1;
    }

    if (IsFull(q))
    {
        cout << "Insertion of the value -> " << x << " Not possible in the queue ..Queue is full." << endl;
        return;
    }

    cout << "Inserted the value -> " << x << " into the queue . " << endl;
    q->arr[++q->rear] = x;

}


bool IsEmpty(struct queue* q)
{
    return (q->front ==q->rear) ? 1 : 0;
}

bool IsFull(struct queue* q)
{
    return (q->rear==q->size-1) ? 1 : 0;
}



int main()
{
    struct queue q;
    q.size = 5;
    q.arr = new int[q.size];
    q.front = q.rear = -1;


    enqueue(&q, 10);
    enqueue(&q, 11);
    enqueue(&q, 12);
    enqueue(&q, 13);
    enqueue(&q, 14);
    enqueue(&q, 15);
    enqueue(&q, 16);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q, 14);
    enqueue(&q, 15);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    dequeue(&q);
    enqueue(&q, 60);
    dequeue(&q);
    //after deleting some elements there is some space left but can't be reused 
    //in this resetting pointer...this problem is overcome by circular queue.
   



}
