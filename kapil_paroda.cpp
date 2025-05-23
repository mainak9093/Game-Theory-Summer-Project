#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
void solve() {
    ll n; 
    cin >> n;
    vector<ll> A(n+1,0);
    for(int i=1;i<=n;i++) cin>>A[i];
    ll a =0,b=0,u=0;
    ll k1=0,k2 =0;
    for(int i=1;i<=n;i++)
    {
        if(A[i]== i)k1++;
        if(A[i]== (n+1)-i)k2++;
    }
    if(n <= 2*k1) cout<<"First\n";
    else if(n< 2*k2)cout<<"Second\n";
    else cout<<"Tie\n";
    // cout<<a<<" "<<b<<" "<<" "<<u<<endl;
    return;
} 
int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}