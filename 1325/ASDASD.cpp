#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int ans[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(i);
        v[b].push_back(i);
        ans[i]=-1;
    }
    pair<int,int> mx(0,0);
    for (int i=1;i<=n;i++)
    mx=max(mx,make_pair((int)v[i].size(),i));
    int cur=0;
    cout<<"ESTE ES MX .SECOND:"<<mx.second<<"\n";
    for (int i:v[mx.second])
        ans[i]=cur++;
    for (int i=1;i<n;i++)
    {
        cout<<"ESTE ES I Y ANS[I]"<<i<<" "<<ans[i]<<"\n";
        if (ans[i]==-1)
        ans[i]=cur++;
        printf("%d\n",ans[i]);
    }
}
