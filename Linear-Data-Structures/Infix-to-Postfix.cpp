/*
You are given an infix expression S of length N. You need to convert the given expression S to its postfix equivalent using stack.
Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the length of S.
The second line contains a string S, the infix expression.
Output
For each test case print a single line containing the postfix equivalent for the given infix expression.

Constraints
1≤T≤10
1≤N≤102
S contains only uppercase English letters (A...Z), and these characters - (,),+,−,∗,/,^. S is a valid infix expression.
Example Input
2
15
((A+B)*D)^(E-F)
19
A+(B*C-(D/E^F)*G)*H
Example Output
AB+D*EF-^
ABC*DEF^/G*-H*+
Explanation
Example case 1: The postfix equivalent for ((A+B)∗D)^(E−F) is AB+D∗EF−^.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    stack<char> st;
	    unordered_map<char,int> precedence;
	    precedence['*']=precedence['/']=2;
	    precedence['+']=precedence['-']=1;
	    precedence['^']=3;
	    for(int i=0;i<n;i++){
	        if(s[i]=='(') st.push(s[i]);
	        else if(s[i]>='A' && s[i]<='Z') cout<<s[i];
	        else if(s[i]==')'){
	            while(st.size()!=0 && st.top()!='('){
	                cout<<st.top();
	                st.pop();
	            }
	            if(st.size()!=0) st.pop();
	        }else{
	            if(st.size()==0 || st.top()=='(') st.push(s[i]);
	            else{
	                while(st.size()!=0 && precedence[st.top()]>=precedence[s[i]]){
	                    cout<<st.top();
	                    st.pop();
	                }
	                st.push(s[i]);
	            }
	        }
	    }
	    while(st.size()!=0){
	        cout<<st.top();
	        st.pop();
	    }
	    cout<<"\n";
	}
	return 0;
}
