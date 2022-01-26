// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    string curr;
		    vector<string> ans;
		    
		    Permute(ans,curr,s,0);

            sort(ans.begin(),ans.end());
		    return ans;
		}
		
		void Permute(vector<string> &ans,string curr,string s,int pos){
		    if(curr.size() > 0)
		        ans.push_back(curr);
		        
		    for(int i = pos;i<s.size();i++){
		        curr.push_back(s[i]);
		        Permute(ans,curr,s,i+1);
		        curr.pop_back();
		    }
		}
		
		
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends