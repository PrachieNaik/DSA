/*

You have a linked list and you have to implement the functionalities push and pop of stack using this given linked list.

*/

/*
The structure of the node of the stack is
struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

// And this is structure of MyStack
class MyStack {
private:
StackNode *top;
public :
    void push(int);
    int pop();
    MyStack()
    {
        top = NULL;
    }
};

/* The method push to push element
   into the stack */
void MyStack ::push(int x) {
    StackNode *node = (StackNode*)malloc(sizeof(StackNode));
    node->data = x;
    node->next = top;
    top = node;
}

/* The method pop which return the element
  poped out of the stack*/
int MyStack ::pop() {
    // Your Code
    if(!top){return -1;}
    int res = top->data;
    StackNode *temp = top;
    top = top->next;
    free(temp);
    return res;
}
