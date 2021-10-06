#include<bits/stdc++.h>
using namespace std;
int main(){
   cout<<"squareroot is "<<endl;
   double lo =1;

   double e=0.000001;
   double mid;
   double x=6;
    double hi=x;
   while(hi-lo>e){
       mid=(hi+lo)/2;
       if(mid*mid<x){
           lo=mid;
       }
       else{
           hi=mid;
       }
   }
   cout<<lo;
}
