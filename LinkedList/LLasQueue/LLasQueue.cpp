/*

Implement a Queue using Linked List. 
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop an element from the queue and print the poped element)

*/

/* 
The structure of the node of the queue is
struct QueueNode
{
    int data;
    QueueNode *next;
};
and the structure of the class is
class Queue {
private:
    QueueNode *front;
    QueueNode *rear;
public :
    void push(int);
    int pop();
};
 */
/* The method push to push element into the queue*/
QueueNode *getNode(int data)
{
    QueueNode *tmp = new QueueNode;
    tmp->data = data;
    tmp->next = NULL;
}
void Queue:: push(int x)
{
        // Your Code
       QueueNode *tmp = getNode(x);
        if(front==NULL)
        {
            rear = tmp;
            front = tmp;
        }
        else
        {
            QueueNode *tmp = getNode(x);
            rear->next = tmp;
            rear = rear->next;
        }
        
}
/*The method pop which return the element poped out of the queue*/
int Queue :: pop()
{
        // Your Code 
       int x=0;
        if(front==NULL)
        {
            //front = NULL;
            rear = NULL;
            return -1;
        }
        if(front->next==NULL)
        {
            x = front->data;
            delete front;
            front = NULL;
            rear = NULL;
            return x;
            
        }
        else
        {
            QueueNode *tmp = front;
            front = front->next;
            x = tmp->data;
            delete tmp;
            tmp = NULL;
            return x;
        }
}
