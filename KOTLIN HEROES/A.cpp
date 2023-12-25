#include <bits/stdc++.h>
using namespace std;



void solve(){
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
    	if(i+1<n && s[i+1]>'0' && s[i+1]<=
    	'9'){
    		bool ok=true;
    		for(int j=i+2;j<n;j++){
    			if(s[j]<='9' && 
    			s[j]>='0'){
    				
    			}
    			else{
    				ok=false;
    				break;
    			}
    		}
    		if(ok){
    			cout<<s.substr(0,i+1)<<"\n";
    			break;
    		}
    	}
    }
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








