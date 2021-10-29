#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// Author : koushal Bhat

int main() {
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a[n]={0};
    for(ll i=0;i<n;i++)
    {
    	cin>>a[i];
    }
    ll lis[n]={1};
    ll count=0;
    ll ans=0;
    for(ll i=1;i<n;i++)
    {
    	ll max=0;
    	for(ll j=i-1;j>=0;j--)
    	{
    		if(a[j]<=a[i])
    		{
    			if(lis[j]>max)
    			{
    				max=lis[j];
    			}
    		}
    	}
    	lis[i]=1+max;
    }
    ans=*max_element(lis,lis+n);
    cout<<ans<<'\n';
	return 0;
}
