#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
void solve() {
    ll n; 
    cin >> n;
    vector<ll> A(n+1,0);
    for(int i=1;i<=n;i++) cin>>A[i];
    ll a =0,b=0,u=0;
    for(int i=1;i<=n;i++)
    {
        if(A[i]!=i && A[i]!= (n+1)-i) u++;
        else if(A[i]!= i)a++;
        else if(A[i]!= (n+1)-i)b++;
    }
    if(n&1)
    {
        if(n-a-u >=((n+1)/2)) cout<<"Win\n";
        else if(n-a-u >= ((n+1)/2)+1) n-a-u >=((n+1)/2);
        else cout<<"Tie\n";
    }
    else
    {
        if(n-a-u >=(n/2))cout<<"Win\n";
        else if(n-b-u >= (n/2 + 1))cout<<"Lose\n";
        else cout<<"Tie\n";
    }
    // if(a+u<=b) cout<<"Win\n";
    // else if(a > b+u)cout<<"Lose\n";
    // else cout<<"Tie\n";
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