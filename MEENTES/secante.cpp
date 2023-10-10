#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p,q,r,s,t,u;
double f(double x){
    return 1.0*p*exp(-x)+1.0*q*sin(x)+1.0*r*cos(x)+1.0*s*tan(x)
    +1.0*t*x*x+u;
}
int main()
{
    while(cin>>p>>q>>r>>s>>t>>u){
        float x0=0, x1=1, x2, f0, f1, f2, e=0.000005;
        int step = 1, N=100;

        /* Setting precision and writing floating point values in fixed-point notation. */
       cout<< setprecision(6)<< fixed;


         do
         {
              f0 = f(x0);
              f1 = f(x1);
              if(f0 == f1)
              {
                   break;
                   //assert(false);
              }

              x2 = x1 - (x1 - x0) * f1/(f1-f0);
              f2 = f(x2);

              //cout<<"Iteration-"<< step<<":\t x2 = "<< setw(10)<< x2<<" and f(x2) = "<< setw(10)<< f(x2)<< endl;

              x0 = x1;
              f0 = f1;
              x1 = x2;
              f1 = f2;

              step = step + 1;

              if(step > N)
              {
                   break;
              }
         }while(fabs(f2)>e);
            if(x2<0 || x2>1){
                cout<<"No solution\n";
            }
            else{
                cout<<fixed<<setprecision(7)<<x2<<"\n";
            }

    }


	 return 0;
}
