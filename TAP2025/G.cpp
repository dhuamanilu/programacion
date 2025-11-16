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

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a,b,c;
    cin>>a>>b>>c;
    if((b-a)%c==0){
        cout<<"S\n";
    }
    else cout<<"N\n";
    return 0;
}