/*

Problem statement: Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

Edge cases: '{{{{', '}', '{{}}{'

Approach:
    Declare a character stack S.
    Now traverse the expression string exp. 
    If the current character is a starting bracket (‘(‘ or ‘{‘ or ‘[‘) then push it to stack.
    If the current character is a closing bracket (‘)’ or ‘}’ or ‘]’) then pop from stack and if the popped character is the matching starting bracket then fine 
    else brackets are not balanced.
    After complete traversal, if there is some starting bracket left in stack then “not balanced”

Time Complexity: O(n) 
Auxiliary Space: O(n) for stack. 

*/


// Function to return if the paranthesis are balanced or not
bool ispar(string x)
{
    stack<char> st;
    for(int i = 0; i<x.length();i++) {
        if(x[i] == '{' || x[i] == '[' || x[i] == '(')
        {
            st.push(x[i]);
        } else if(!st.empty()) {
            if(x[i] == '}' && st.top() == '{')
            {    
                st.pop();
            } else if(x[i] == ']' && st.top() == '[') {
                st.pop();
            } else if(x[i] == ')' && st.top() == '(') {
                st.pop();
            } else {
                return 0;
            }
                
        } else {
            return 0;
        }
    }
    if(st.empty())
    return 1;
    else 
    return 0;
}
