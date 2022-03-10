/*
Add two numbers represented by linked lists 
Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.

The sum list is a linked list representation of the addition of two input numbers from the last.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M)) for the resultant list.

Constraints:
1 <= N, M <= 5000
*/

	struct Node* reverse(struct Node *head)
    {
        Node *curr=head,*prev=NULL;
        while(curr)
        {
            Node *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node *fir=reverse(first);
        Node *sec=reverse(second);
        Node *ans=new Node(0);
        Node *curr=ans;
        int carry=0;
        while(fir && sec)
        {
            int sum=fir->data +sec->data +carry;
            carry=sum/10;
            Node * temp=new Node(sum%10);
            fir=fir->next;
            sec=sec->next;
            curr->next=temp;
            curr=curr->next;
        }
        while(fir)
        {
            int sum=fir->data +carry;
            carry=sum/10;
            Node * temp=new Node(sum%10);
            fir=fir->next;
            curr->next=temp;
            curr=curr->next;
        }
        while(sec)
        {
            int sum=sec->data +carry;
            carry=sum/10;
            Node * temp=new Node(sum%10);
            sec=sec->next;
            curr->next=temp;
            curr=curr->next;
        }
        while(carry)
        {
            Node * temp=new Node(carry%10);
            curr->next=temp;
            curr=curr->next;
            carry/=10;
        }
        return reverse(ans->next);
    }