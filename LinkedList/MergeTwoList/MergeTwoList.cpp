/*

Given two sorted lists, merge them so as to produce a combined sorted list (without using extra space).

Constraints: 0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 10^3

Approaches:

Method 1:
    The recursive solution can be formed, given the linked lists are sorted.
    
    Compare the head of both linked lists.
    Find the smaller node among the two head nodes. The current element will be the smaller node among two head nodes.
    The rest elements of both lists will appear after that.
    Now run a recursive function with parameters, the next node of the smaller element and the other head.
    The recursive function will return the next smaller element linked with rest of the sorted element. Now point the next of current element to that, 
        i.e curr_ele->next=recursivefunction()
    Handle some corner cases.
    If both the heads are NULL return null.
    If one head is null return the other.

    Time complexity:O(n).
    Only one traversal of the linked lists are needed.
    Auxiliary Space:O(n).
    If the recursive stack space is taken into consideration.

Method 2:
    
    This approach is very similar to the above recursive approach.

    Traverse the list from start to end.
    If the head node of second list lies in between two node of the first list, insert it there and make the next node of second list as the head. Continue this 
        until there is no node left in both lists, i.e. both the lists are traversed.
    If the first list has reached end while traversing, point the next node to the head of second list.
    Note: Compare both the lists where the list with smaller head value is the first list.
    
    Time complexity:O(n).
    As only one traversal of the linked lists is needed.
    Auxiliary Space:O(1).
    As there is no space required.

*/

// Merges two lists with headers as h1 and h2. 
// It assumes that h1's data is smaller than 
// or equal to h2's data. 
struct Node* mergeUtil(struct Node* h1, struct Node* h2) 
{ 
    // if only one node in first list 
    // simply point its head to second list 
    if (!h1->next) { 
        h1->next = h2; 
        return h1; 
    } 
  
    // Initialize current and next pointers of 
    // both lists 
    struct Node *curr1 = h1, *next1 = h1->next; 
    struct Node *curr2 = h2, *next2 = h2->next; 
  
    while (next1 && curr2) { 
        // if curr2 lies in between curr1 and next1 
        // then do curr1->curr2->next1 
        if ((curr2->data) >= (curr1->data) && (curr2->data) <= (next1->data)) { 
            next2 = curr2->next; 
            curr1->next = curr2; 
            curr2->next = next1; 
  
            // now let curr1 and curr2 to point 
            // to their immediate next pointers 
            curr1 = curr2; 
            curr2 = next2; 
        } 
        else { 
            // if more nodes in first list 
            if (next1->next) { 
                next1 = next1->next; 
                curr1 = curr1->next; 
            } 
  
            // else point the last node of first list 
            // to the remaining nodes of second list 
            else { 
                next1->next = curr2; 
                return h1; 
            } 
        } 
    } 
    return h1; 
} 
  
// Merges two given lists in-place. This function 
// mainly compares head nodes and calls mergeUtil() 
struct Node* merge(struct Node* h1, struct Node* h2) 
{ 
    if (!h1) 
        return h2; 
    if (!h2) 
        return h1; 
  
    // start with the linked list 
    // whose head data is the least 
    if (h1->data < h2->data) 
        return mergeUtil(h1, h2); 
    else
        return mergeUtil(h2, h1); 
} 
