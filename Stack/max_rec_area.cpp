/*

Maximum Rectangular Area in a Histogram 
Medium Accuracy: 47.42% Submissions: 57736 Points: 4
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
Explanation: 


Example 2:

Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram 
will be 8  and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.
Your Task:
The task is to complete the function getMaxArea() which takes the array arr[] and its size N as inputs and finds the largest rectangular area possible and returns the answer.

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 ≤ N ≤ 106
1 ≤ arr[i] ≤ 1012

*/

	long long getMaxArea(long long a[], int n)
    {
        long long area=0,curr;
        stack<long long>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && a[st.top()]>=a[i])
            {
                int t=st.top();
                st.pop();
                curr=a[t]*( (st.empty()) ? i : (i-st.top()-1) );
                area=max(area,curr);
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int t=st.top();
            st.pop();
            curr=a[t]*( (st.empty()) ? n : (n-st.top()-1) );
            area=max(area,curr);
        }
        return area;
    }
