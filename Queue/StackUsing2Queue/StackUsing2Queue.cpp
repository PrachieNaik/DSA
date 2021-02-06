/*

Problem statement: Implement a Stack using two queues q1 and q2.

Approaches:

Method 1: (By making push operation costly)
This method makes sure that newly entered element is always at the front of ‘q1’, so that pop operation just dequeues from ‘q1’. ‘q2’ is used to put every new element at front of ‘q1’.

    push(s, x) operation’s step are described below:
    Enqueue x to q2
    One by one dequeue everything from q1 and enqueue to q2.
    Swap the names of q1 and q2
    pop(s) operation’s function are described below:
    Dequeue an item from q1 and return it.

Method 2: (By making pop operation costly)
In push operation, the new element is always enqueued to q1. In pop() operation, if q2 is empty then all the elements except the last, are moved to q2. Finally the last element is dequeued from q1 and returned.

    push(s, x) operation:
    Enqueue x to q1 (assuming size of q1 is unlimited).
    pop(s) operation:
    One by one dequeue everything except the last element from q1 and enqueue to q2.
    Dequeue the last item of q1, the dequeued item is result, store it.
    Swap the names of q1 and q2
    Return the item stored in step 2.

Method 3: (By making pop operation costly - if we want to avoid swapping names of two queues)
In push operation, the new element is enqueued to q1 if both of the queues or q2 is empty, else it is pushed to q2. In pop() operation, if q2 is empty then all the elements except the last, are moved to q2 ans vice versa. Finally the last element is dequeued from q1 or vice versa and returned.

*/

void QueueStack :: push(int x)
{
        // Your Code
        if(q1.empty() && q2.empty())
        q1.push(x); 
        else if(q1.empty()) 
        q2.push(x);
        else
        q1.push(x);
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
        // Your Code
        int ans = -1;
        if(q1.empty() && !q2.empty()) {
            while(q2.size()!=1) {
               q1.push(q2.front());
               q2.pop();
            }
            ans = q2.front();
            q2.pop();
         } else if(!q1.empty() && q2.empty()) {
             while(q1.size()!=1) {
                q2.push(q1.front());
                q1.pop();
            }
            ans = q1.front();
            q1.pop();
         } 
         return ans;
}
