/*
Rearrange Array Alternately 
Medium Accuracy: 50.0% Submissions: 59799 Points: 4
Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.
Example 1:
Input:
N = 6
arr[] = {1,2,3,4,5,6}
Output: 6 1 5 2 4 3
Explanation: Max element = 6, min = 1, 
second max = 5, second min = 2, and 
so on... Modified array is : 6 1 5 2 4 3.
Your Task:
The task is to complete the function rearrange() which rearranges elements as explained above. Printing of the modified array will be handled by driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 107
1 <= arr[i] <= 107
*/

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // a: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *a, int n) 
    { 	
    	int max=n-1,min=0;
    	int max_ele=a[n-1]+1;
    	for(int i=0;i<n;i++)
    	{
    	    if(i%2==0)
    	    {
    	       a[i]+=a[max]%max_ele*max_ele;
    	       max--;
    	    }
    	    else
    	    {
    	       a[i]+=a[min]%max_ele*max_ele;
    	       min++;
    	    }
    	}
    	 for(int i=0;i<n;i++)
    	 a[i]=a[i]/max_ele;
    }
};
int main() 
{
    int t;
    cin >> t;  
    while(t--){
        int n;
        cin >> n;       
        long long arr[n];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";	
		cout << endl;
    }
	return 0; 
} 