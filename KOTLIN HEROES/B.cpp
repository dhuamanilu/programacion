#include <bits/stdc++.h>
using namespace std;
//#ifdef LOCAL
    #include "helpers/debug.h"
/*#else
    #define dbg(...)     0
    #define chk(...)     0

    #define DBG(x)        0
    #define DBGY(x)       0
    #define DBG2(x,y)     0
    #define DBG3(x,y,z)   0
    #define DBG4(x,y,z,w) 0
    #define RAYA          0
#endif*/

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    int pos=0,neg=0;
    int posNegL=-1,posNegR=-1;
    vector<int> posi;
    for(int i=0;i<n;i++){
        if(s[i]=='+'){
        	pos++;
        }
        else neg++;

        if(pos-neg>=0){
        	posi.push_back(i);
        }
        if(pos-neg<0){

        	if(posNegL==-1){
        		posNegL=i;
        	}
        	posNegR=i;
        }
    }
    DBG(posi);
    if(posNegL==posNegR && posNegL==-1){
    	cout<<"1 1\n";
    }
    else{
    	/*cout<<"asdas: ";
    	for(auto & e : posi){
    		cout<<e<<" ";
    	}
    	cout<<"-----\n";*/

    	if(posi.size()>0){
    		swap(s[posi.back()],s[posNegR]);
    		int contar1=0,contar2=0;
    		for(int i=0;i<n;i++){
    			if(s[i]=='+') contar1++;
    			else contar2++;
    			if(contar1-contar2<0){
    				cout<<"-1\n";
    				return;
    			}
    		}
    		cout<<posi.back()+1<<" "<<posNegR+1<<"\n";
    	}
    	else{
    		cout<<"-1\n";
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








