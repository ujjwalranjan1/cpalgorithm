#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=1e5+5;
int phi[N];

void phishieve(int n)
{
  for(int i=0;i<=n;i++)
    phi[i]=i;

  for(int i=2;i<=n;i++)
  {
    if(phi[i]==i)
    {
      for(int j=i;j<=n;j+=i)
        phi[j]-=phi[j]/i;
    }
  }
}

int totient(int n)
{
  int ans=n;
  for(int i=2;i*i<=n;i++)
  {
    if(!(n%i))
    {
      while(!(n%i))
        n/=i;
      ans-=ans/i;
    }
  }
  if(n>1)
    ans-=ans/n;
  return ans;
}

void solve()
{
  int n;
  cin>>n;
  cout<<totient(n)<<endl;
}

int32_t main()
{
  IOS
  int t=1;
  cin>>t;
  while(t--)
    solve();
}

