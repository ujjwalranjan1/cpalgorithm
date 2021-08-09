#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=1e6+6;
vector<int>isprime(N,1);
vector<int>sprime;

void sieve(int n)
{
  isprime[0]=isprime[1]=0;
  // sprime.push_back(0);
  for(int i=2;i<=n;i++)
  {
    if(isprime[i])
    {
      sprime.push_back(i);
      for(int j=i*i;j<=n;j+=i)
        isprime[j]=0;
    }
  }
}

void segmented_sieve(int l,int r)
{
  sieve(r);
  vector<bool>is_prime(r-l+1,1);
  for(auto it:sprime)
    for(int j=max(it*it,(l+it-1)/it*it);j<=r;j+=it)
      is_prime[j-l]=0;
  if(l==1)
    is_prime[0]=0;
  vector<int>primes;
  for(int i=0;i<r-l+1;i++)
    if(is_prime[i])
      primes.push_back(l+i);
  for(auto it:primes)
    cout<<it<<" ";
  cout<<endl;
}





void solve()
{
  int l,r;
  cin>>l>>r;
  segmented_sieve(l,r);

}

int32_t main()
{
  IOS
  int t=1;
  cin>>t;
  while(t--)
    solve();
}

