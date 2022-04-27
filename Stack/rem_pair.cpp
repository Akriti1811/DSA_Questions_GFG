/*
 Removing consecutive duplicates - 2 
Easy Accuracy: 59.28% Submissions: 9922 Points: 2
You are given string str. You need to remove the pair of duplicates.
Note: The pair should be of adjacent elements and after removing a pair the remaining string is joined together. 

Example 1:

Input:
aaabbaaccd

Output: 
ad

Explanation: 
Remove (aa)abbaaccd =>abbaaccd
Remove a(bb)aaccd => aaaccd
Remove (aa)accd => accd
Remove a(cc)d => ad
Example 2:

Input: 
aaaa

Output: 
Empty String

Explanation: 
Remove (aa)aa => aa
Again removing pair of duplicates then (aa) 
will be removed and we will get 'Empty String'.

Your Task:
This is a function problem. You only need to complete the function removePair() that takes a string as a parameter and returns the modified string. Return an empty string if the whole string is deleted.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
N = length of the string.

Constraints:
1 <= |str| <= 103

*/


string removePair(string s)
    {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(!st.empty() && s[i]==st.top())
            st.pop();
            else
            st.push(s[i]);
        }
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }