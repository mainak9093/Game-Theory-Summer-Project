#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        ll a = 0, b = 0;

        for (int i = 1; i <= n; i++) {
            if(p[i]==i) a++;
            if(p[i]==(n+1)-i)b++;
        }
        if(n&1)
        {
            if(n<= 2*a)
            {
                cout << "First\n";
            }
            else if(n <= 2*b)
            {
                cout << "Second\n";
            }
            else
            {
                cout << "Tie\n";
            }
        }
        else
        {
             if(a-1>=(n/2))
            {
                cout << "First\n";
            }
            else if(b-1 >= n/2)
            {
                cout << "Second\n";
            }
            else
            {
                cout << "Tie\n";
            }
        }
        cout<<a<<" "<<b<<endl;
    }
    

    return 0;
}
