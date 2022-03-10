/*
Swap Kth nodes from ends 
Given a singly linked list of size N, and an integer K. You need to swap the Kth node from the beginning and Kth node from the end of the linked list. Swap the nodes through the links. Do not change the content of the nodes.

Example 1:

Input:
N = 4,  K = 1
value[] = {1,2,3,4}
Output: 1
Explanation: Here K = 1, hence after
swapping the 1st node from the beginning
and end thenew list will be 4 2 3 1.
 

Example 2:

Input:
N = 5,  K = 7
value[] = {1,2,3,4,5}
Output: 1
Explanation: K > N. Swapping is invalid. 
Return the head node as it is.
Your Task: 
You do not need to read input or print anything. The task is to complete the function swapkthnode(), which has takes head of link list, N and K as input parameters and returns the new head.
The generated output will be 1 if you are able to complete your task. 

Expected Time Complexity: O(n)
Expected Auxillary space Complexity: O(1)

Constraints:
1 <= N <= 103
1 <= K <= 103
*/

Node *swapkthnode(Node* head, int n, int k)
{
    if(n<k || (2*k-1==n))
    return head;
    
    int first=k-1,last=n-k;
    Node *x=head,*x_prev=NULL;
    Node *y=head,*y_prev=NULL;
    
    while(first--)
    {
        x_prev=x;
        x=x->next;
    }
    while(last--)
    {
        y_prev=y;
        y=y->next;
    }
    if(x_prev)
        x_prev->next=y;
    if(y_prev)
        y_prev->next=x;
    
    Node *temp= x->next;
    x->next=y->next;
    y->next=temp;
    
    if(k==1)
        return y;
    if(k==n)
        return x;
    return head;
}
