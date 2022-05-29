/*

 Generate Binary Numbers 

Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.

Example 1:

Input:
N = 2
Output: 
1 10
Explanation: 
Binary numbers from
1 to 2 are 1 and 10.

Example 2:

Input:
N = 5
Output: 
1 10 11 100 101
Explanation: 
Binary numbers from
1 to 5 are 1 , 10 , 11 , 100 and 101.
 

Your Task:
You only need to complete the function generate() that takes N as parameter and returns vector of strings denoting binary numbers.

Expected Time Complexity : O(N log2N)
Expected Auxilliary Space : O(N log2N)

Constraints:
1 ≤ N ≤ 106


*/

vector<string> generate(int n )
{
	vector<string>ans;
	queue<string>q;
	q.push("1");
	ans.push_back(q.front());
	int size=1;
	while(n>1)
	{
	    string t=q.front();
	    q.pop();
	    
	    string a=t+"0";
	    string b=t+"1";
	    q.push(a);
	    q.push(b);
	    if(n>1)
	    {
	        ans.push_back(a);
	        n--;
	    }
	    if(n>1)
	    {
	        ans.push_back(b);
	        n--;
	    }
	}
	return ans;
}