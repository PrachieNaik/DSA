/*

Problem statement: You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

Approaches:

Method 1: Use auxillary array, push only when the incoming element of the main stack is smaller than or equal to the top of the auxiliary stack. Similarly during pop, if the pop-off element equal to the top of the auxiliary stack, remove the top element of the auxiliary stack.

    Complexity Analysis:  

    Time Complexity: 
    For Insert operation: O(1) (As insertion ‘push’ in a stack takes constant time)
    For Delete operation: O(1) (As deletion ‘pop’ in a stack takes constant time)
    For ‘Get Min’ operation: O(1) (As we have used an auxiliary which has it’s top as the minimum element)
    Auxiliary Space: O(n). 
    The complexity in the worst case is the same as above but in other cases, it will take slightly less space than the above approach as repetition is neglected. 
    
Method 2: We define a variable minEle that stores the current minimum element in the stack. Now the interesting part is, how to handle the case when minimum element is removed. To handle this, we push “2x – minEle” into the stack instead of x so that previous minimum element can be retrieved using current minEle and its value stored in stack.

    Algorithm: 

    Push(x) : Inserts x at the top of stack.
    If stack is empty, insert x into the stack and make minEle equal to x.
    If stack is not empty, compare x with minEle. Two cases arise:
    If x is greater than or equal to minEle, simply insert x.
    If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x. For example, let previous minEle was 3. Now we want to insert 2. We update minEle as 2 and insert 2*2 – 3 = 1 into the stack.
    
    Pop() : Removes an element from top of stack.

    Remove element from top. Let the removed element be y. Two cases arise:
    If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
    If y is less than minEle, the minimum element now becomes (2*minEle – y), so update (minEle = 2*minEle – y). This is where we retrieve previous minimum from current minimum and its value in stack. For example, let the element to be removed be 1 and minEle be 2. We remove 1 and update minEle as 2*2 – 1 = 3.
    
    Important Points:
    
    Stack doesn’t hold actual value of an element if it is minimum so far.
    Actual minimum element is always stored in minEle
    
    How does this approach work?
    When element to be inserted is less than minEle, we insert “2x – minEle”. The important thing to notes is, 2x – minEle will always be less than x (proved below), i.e., new minEle and while popping out this element we will see that something unusual has happened as the popped element is less than the minEle. So we will be updating minEle.

    How 2*x - minEle is less than x in push()? 
    x < minEle which means x - minEle < 0
    
    // Adding x on both sides
    x - minEle + x < 0 + x 
    
    2*x - minEle < x 
    
    We can conclude 2*x - minEle < new minEle 
    
    While popping out, if we find the element(y) less than the current minEle, we find the new minEle = 2*minEle – y.
    
    How previous minimum element, prevMinEle is, 2*minEle - y
    in pop() is y the popped element?
    
     // We pushed y as 2x - prevMinEle. Here 
     // prevMinEle is minEle before y was inserted
     y = 2*x - prevMinEle  
    
     // Value of minEle was made equal to x
     minEle = x .
        
     new minEle = 2 * minEle - y 
                = 2*x - (2*x - prevMinEle)
                = prevMinEle // This is what we wanted
     
    
*/

// C++ program to implement a stack that supports 
// getMinimum() in O(1) time and O(1) extra space. 
#include <bits/stdc++.h> 
using namespace std; 

// A user defined stack that supports getMin() in 
// addition to push() and pop() 
struct MyStack 
{ 
	stack<int> s; 
	int minEle; 

	// Prints minimum element of MyStack 
	void getMin() 
	{ 
		if (s.empty()) 
			cout << "Stack is empty\n"; 

		// variable minEle stores the minimum element 
		// in the stack. 
		else
			cout <<"Minimum Element in the stack is: "
				<< minEle << "\n"; 
	} 

	// Prints top element of MyStack 
	void peek() 
	{ 
		if (s.empty()) 
		{ 
			cout << "Stack is empty "; 
			return; 
		} 

		int t = s.top(); // Top element. 

		cout << "Top Most Element is: "; 

		// If t < minEle means minEle stores 
		// value of t. 
		(t < minEle)? cout << minEle: cout << t; 
	} 

	// Remove the top element from MyStack 
	void pop() 
	{ 
		if (s.empty()) 
		{ 
			cout << "Stack is empty\n"; 
			return; 
		} 

		cout << "Top Most Element Removed: "; 
		int t = s.top(); 
		s.pop(); 

		// Minimum will change as the minimum element 
		// of the stack is being removed. 
		if (t < minEle) 
		{ 
			cout << minEle << "\n"; 
			minEle = 2*minEle - t; 
		} 

		else
			cout << t << "\n"; 
	} 

	// Removes top element from MyStack 
	void push(int x) 
	{ 
		// Insert new number into the stack 
		if (s.empty()) 
		{ 
			minEle = x; 
			s.push(x); 
			cout << "Number Inserted: " << x << "\n"; 
			return; 
		} 

		// If new number is less than minEle 
		if (x < minEle) 
		{ 
			s.push(2*x - minEle); 
			minEle = x; 
		} 

		else
		s.push(x); 

		cout << "Number Inserted: " << x << "\n"; 
	} 
}; 

// Driver Code 
int main() 
{ 
	MyStack s; 
	s.push(3); 
	s.push(5); 
	s.getMin(); 
	s.push(2); 
	s.push(1); 
	s.getMin(); 
	s.pop(); 
	s.getMin(); 
	s.pop(); 
	s.peek(); 

	return 0; 
} 
