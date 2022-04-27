/*
Permutation Sequence

The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
 

Constraints:

1 <= n <= 9
1 <= k <= n!

link : https://takeuforward.org/data-structure/find-k-th-permutation-sequence/

*/

// Time Complexity: O(N) * O(N) = O(N^2)
// Space Complexity: O(N) 

string getPermutation(int n, int k) 
    {
        vector<int>num;
        int fact=1;
        string ans;
        for(int i=1;i<n;i++)
        {
            fact*=i;
            num.push_back(i);
        }
        num.push_back(n);
        k--;
        while(true)
        {
            ans+=to_string(num[k/fact]);
            num.erase(num.begin()+k/fact);
            if(num.size()==0)
                break;
            k=k%fact;
            fact/=num.size();
        }
        return ans;
    }