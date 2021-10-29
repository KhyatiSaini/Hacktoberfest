#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// Author : Koushal Bhat
map < ll, ll > factorize(ll n) 
{
	ll count = 0;
	map < ll, ll > mp;
	while(!(n % 2))
	{
		n /= 2;
		count++;
	}
	if(count>0)
		mp[2] = count;
	for(ll i = 3; i <= sqrt(n); i += 2)
	{
		count = 0;
		while(!(n % i))
		{
			count++;
			n /= i;
		}
		if(count)
			mp[i] = count;
	}
	if(n > 2)
		mp[n] = 1;
	return mp;
}
signed main()
{
	ll n;
	cin >> n;
	map < ll , ll > mp = factorize(n);
	for(auto z : mp)
	{
		cout << z.first << " " << z.second << endl;
 	}
}
