****************************************************************************  Question  ********************************************************************************************************************

Given two integers N and K, the task is to find the string S of minimum length such that it contains all possible strings of size N as a substring. The characters of the string should be from integers ranging from 0 to K-1.  

Example 1:

Input:
N = 2, K = 2
Output: 
00110
Explanation: 
Allowed characters are from 0 to k-1 (i.e., 0 and 1).
There are 4 string possible of size N=2 
(i.e "00", "01","10","11")
"00110" contains all possible string as a 
substring. It also has the minimum length.
Example 2:

Input:
N = 2, K = 3
Output: 
0010211220
Explanation: 
Allowed characters are from 0 to k-1 (i.e., 0, 1 and 2).
There are total 9 strings possible
of size N, given output string has the minimum
length that contains all those strings as substring.
Your Task: 
You don't need to read input or print anything. Complete the function findString( ) which takes the integer N and the integer K as input parameters and returns the string.
Note: In case of multiple answers, return any string of minimum length which satisfies above condition. The driver will print the length of the string. In case of wrong answer it will print -1.

Expected Time Complexity: O(KNlogK)
Expected Space Complexity: O(KNN)

Constraints:
1 ≤ N ≤ 4
1 < K < 10
1 < KNN < 106





*****************************************************************************  Solution  *******************************************************************************************************************

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    string findString(int n, int k) {
        // code here
             string ans="";

       unordered_set<string>st;

       for(int i=0;i<n;i++)ans+='0';

       st.insert(ans);

       string temp;

       for(int i=k-1;i>=0;i--){

           temp=ans.substr(ans.size()-n+1,n-1);

           temp+=to_string(i);

           if(st.find(temp)==st.end()){

               ans+=to_string(i);

               i=k;

               st.insert(temp);

           }

       }

       return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
} 
// } Driver Code Ends

