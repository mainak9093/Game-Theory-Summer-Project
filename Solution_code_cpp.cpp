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
    if(a+u<=b) cout<<"Win\n";
    else if(a > b+u)cout<<"Lose\n";
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
/*
5
4
1 2 4 3
3
2 3 1
5
3 4 5 2 1
6
1 5 6 3 2 4
5
1 2 3 5 4
*/