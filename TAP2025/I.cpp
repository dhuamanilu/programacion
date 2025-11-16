#include <bits/stdc++.h>
using namespace std;
string to_string (string s){
    return '"' + s + '"';
}
string to_string(const char*s){
    return to_string((string) s);
}
string to_string(char c){
    return string(1,c);
}
string to_string(bool b){
    return b ? "true" : "false";
}
template <typename A>
string to_string(A v);
template <typename A , typename B>
string to_string(pair<A,B> p){
    return "(" + to_string(p.first) + " , " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v){
    bool first=true;
    string res="[";
    for(const auto & x : v){
        if(!first) res +=", ";
        first=false;
        res+=to_string(x);
    }
    res+="]";
    return res;
}
void debug_out(){
    cerr<<endl;
}
template <typename Head,typename...Tail>
void debug_out(Head H,Tail... T){
    cerr<<" "<<to_string(H);
    debug_out(T...);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        int cant=0;
        vector<int> opt(n);
        for(int j=0;j<n;j++){
            cin>>opt[j];
            if(opt[j]==1) cant++;
        }
        int one = x / (cant + 1);
        if(one < y){
            for(int j=0;j<n;j++){
                if(opt[j]==1){
                    a[j]+=(x)/cant;
                }
                else a[j]+=y;
            }
            a[n]+=y;
        }
        else{
            for(int j=0;j<n;j++){
                if(opt[j]==1){
                    a[j]+=one;
                }
                else a[j]+=y;
            }
            a[n]+=one;
        }
    }
    for(int i=0;i<(n+1);i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    return 0;
}