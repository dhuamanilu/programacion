#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define vi vector<int>
#define vp vector<pair<int,int>>
#define SET(a) memset(a,-1,sizeof(a))
#define ff first
#define ss second
#define unmp unordered_map<int,int>
#define F(i,a,b) for(int i=a;i<=b;i++)
#define MOD 1000000007
#define pi 3.141592653589793238
#define inf 1e18
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int h,w,t,sx,sy,ex,ey;
char a[310][310];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ans=0;
bool vis[310][310];

bool isvalid(int x,int y){
    return (x>=1&&y>=1&&x<=h&&y<=w&&a[x][y]!='#');
}

void dfs(int x,int y,int cnt,int c){
    if(cnt>t)return;
    if(a[x][y]=='G'){
        ans=max(ans,c);
        return;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(isvalid(nx,ny)&&!vis[nx][ny]){
            vis[nx][ny]=1;
            if(a[nx][ny]=='o')dfs(nx,ny,cnt+1,c+1);
            else dfs(nx,ny,cnt+1,c);
            vis[nx][ny]=0;
        }
    }
}

signed main(){
    cin>>h>>w>>t;
    F(i,1,h){
        F(j,1,w){
            cin>>a[i][j];
            if(a[i][j]=='S'){
                sx=i;
                sy=j;
            }
            if(a[i][j]=='G'){
                ex=i;
                ey=j;
            }
        }
    }
    int l=1,r=inf,anss=0;
    while(l<=r){
        int mid=(l+r)/2;
        memset(vis,0,sizeof(vis));
        ans=0;
        vis[sx][sy]=1;
        dfs(sx,sy,0,0);
        if(ans>=1)anss=mid;
        if(ans>t) r=mid-1;
        else l=mid+1;
    }
    cout<<anss<<endl;
}
