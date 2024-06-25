#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s){
    int n=s.size();
    int i=0,j=n-1;
    bool ok=true;
    while(i<j){
        if(s[i]!=s[j]){
            ok=false;
            break;
        }
        i++;
        j--;
    }
    return ok;
}
void print(){
    for(int i=1;i<=41;i++){
        cout<<i<<"\n";
    }
    for(int i=1;i<=40;i++){
        cout<<i<<" "<<i+1<<"\n";
    }
}

string solve(string s) {
    //1
    if(isPalindrome(s)) return s;
    //2
    int n=s.size();
    int i=0,j=n-1;
    bool retrocedio=false;
    //3
    while(j-i>1){
        //4
        if(s[j]>s[i]) retrocedio=true;
        //5
        else if(s[j]<s[i]) retrocedio=false;
        //6
        s[j]=s[i];
        i++;
        j--;
    }
    //7
    if(i==j){
        //8
        if(!retrocedio){
            //no hacer nada,el numero tiene longitud impar y ya es palindromo
        }
        
        else{
            //9
            int ptrI=i,ptrD=j;
            //10
            while(ptrI>=0){
                //11
                if(ptrD>=n)break;
                //12
                if(s[ptrI]!=s[ptrD])break;
                //13
                if(s[ptrI]!='9') break;
                //14
                ptrI--;
                ptrD++;
            }
            //15
            if(ptrI==ptrD){
                //16
                s[ptrI]=s[ptrI]+1;
            }
            else{
                
                for(int k=ptrI+1;;k++){
                    //17
                    if(k>=ptrD)break;
                    //18
                    s[k]='0';
                }
                //19
                s[ptrI]=s[ptrI]+1;
                s[ptrD]=s[ptrD]+1;
            }
        }
        
    }
    else{
        //20
        if(!retrocedio){
            //21
            int ptrI=i,ptrD=j;
            //22
            if(s[ptrI] == s[ptrD]){
                //no hacer nada
            }
            //23
            else if(s[ptrI] < s[ptrD]){
                //24
                char poner=s[ptrI]+1;
                s[ptrI]=poner;
                s[ptrD]=poner;
            }
            else{
                //25
                s[ptrD]=s[ptrI];
            }
        }
        else{
            //26
            int ptrI=i,ptrD=j;
            //27
            while(ptrI>=0){
                //28
                if(ptrD>=n) break;
                //29
                if(s[ptrI]!=s[ptrD])break;
                //30
                if(s[ptrI]!='9')break;
                //31
                ptrI--;
                ptrD++;
            }
            //32
            if(ptrI == i){
                //33
                if(ptrD==j){
                    //34
                    if(s[ptrI] <= s[ptrD]){
                        //35
                        char poner=s[ptrI]+1;
                        s[ptrI]=poner;
                        s[ptrD]=poner;
                    }
                    else{
                        //36
                        s[ptrD]=s[ptrI];
                    }
                }
                
            }
            else{
                //37
                for(int k=ptrI+1;;k++){
                    //38
                    if(k>=ptrD)break;
                    //39
                    s[k]='0';
                }
                //40
                s[ptrI]=s[ptrI]+1;
                s[ptrD]=s[ptrD]+1;
            } 
        }  
    }
    //41
    return s;
}

string resolverRefactorizado(string s){
    //1
    while(!isPalindrome(s)){
        //2
        int n=s.size();
        int idx=n-1;
        //3
        while(idx>=0){
            //4
            if(s[idx]-'0'!=9)break;
            //5
            idx--;
        }
        //6
        if(idx==-1){  
            //7 
            string nuevo="1"; 
            string ceros(n, '0');
            s=nuevo+ceros;
        }
        else{    
            //8   
            s[idx]=s[idx]+1; 
            //9 
            for(int j=idx+1;;j++){
                //10
                if(j>=n) break;
                //11
                s[j]='0';
            }     
        }  
    }
    //12
    return s;
}
int main(){
    string s;
    cin>>s;
    cout<<resolverRefactorizado(s)<<"\n";
    return 0;   
}