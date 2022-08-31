#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <math.h>
#include <iomanip>

using namespace std;
int main() {
    int n,s;
    cin>>n>>s;
    double coorx[n];
    double coory[n];
    double cant[n];
    double var=0;
    int dist[n];
    for(int i=0;i<n;i++){
        cin>>coorx[i]>>coory[i]>>cant[i];
        dist[i]=(coorx[i]*coorx[i]+coory[i]*coory[i]);
    }
    int lo=0,hi=200000005;
	while(lo<hi){
		int mid=(lo+hi)/2;
		int cont =0;
		for(int  i=0;i<n;i++){
            if(dist[i] <=   mid ){
                cont+=cant[i];
            }
		}
		if(cont+s>=1000000)
			hi=mid;
		else
			lo=mid+1;
	}
    if(hi==200000005)
		cout<<"-1\n";
	else
		cout<<fixed<<setprecision(6)<<sqrt(hi)<<"\n";
    return 0;
}
