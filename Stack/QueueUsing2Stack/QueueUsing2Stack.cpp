/*

Problem statement: We are given a stack data structure with push and pop operations, the task is to implement a queue using instances of stack data structure and 
operations on them.

Approaches:

Method 1: (By making enQueue operation costly) This method makes sure that oldest entered element is always at the top of stack 1, so that deQueue operation just 
pops from stack1. To put the element at top of stack1, stack2 is used.

    enQueue(q, x):
    While stack1 is not empty, push everything from stack1 to stack2.
    Push x to stack1 (assuming size of stacks is unlimited).
    Push everything back to stack1.
    Here time complexity will be O(n)
    
    deQueue(q):
    
    If stack1 is empty then error
    Pop an item from stack1 and return it
    Here time complexity will be O(1)
    
    Time Complexity:
    Push operation: O(N).
    In the worst case we have empty whole of stack 1 into stack 2.
    Pop operation: O(1).
    Same as pop operation in stack.
    Auxiliary Space: O(N).
    Use of stack for storing values.

Method 2 (By making deQueue operation costly)In this method, in en-queue operation, the new element is entered at the top of stack1. In de-queue operation, 
if stack2 is empty then all the elements are moved to stack2 and finally top of stack2 is returned.

    enQueue(q,  x)
      1) Push x to stack1 (assuming size of stacks is unlimited).
    Here time complexity will be O(1)
    
    deQueue(q)
      1) If both stacks are empty then error.
      2) If stack2 is empty
           While stack1 is not empty, push everything from stack1 to stack2.
      3) Pop the element from stack2 and return it.
      4) Pop all the elements from stack to stack 1.

    Note: Step 4 is important because in case user request top element from stack, we will have stack 1 empty if there are no more elements added after the pop.
    Here time complexity will be O(n)
*/


/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

/* The method push to push element into the queue */
void StackQueue :: push(int x)
 {
        s1.push(x);
 }

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{ 
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        
        if(s2.empty()) 
            return -1;
            
        int ans = s2.top();
        s2.pop();
        
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        
        return ans;
}
