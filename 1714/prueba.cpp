#include <bits/stdc++.h>
using namespace std;


uint32_t jenkins_one_at_a_time_hash(char *key, size_t len)
{
    uint32_t hash, i;
    for(hash = i = 0; i < len; ++i)
    {
        hash += key[i];
        //hash += (hash << 10);
        //hash ^= (hash >> 6);
    }
    //hash += (hash << 3);
    //hash ^= (hash >> 11);
    //hash += (hash << 15);
    return hash;
}
int main(){
    char a[]={'1','2','3','4'};
    uint32_t a0=jenkins_one_at_a_time_hash("123456789",9);
    cout<<"este es el a0 : "<<a0<<"\n";
    return 0;
}
