#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
int lis(const std::vector<int>& arr) {
    std::vector<int> tail;
    for (int num : arr) {
        auto it = std::lower_bound(tail.begin(), tail.end(), num);
        if (it == tail.end()) {
            tail.push_back(num);
        } else {
            *it = num;
        }
    }
    return tail.size();
}
int lds(const std::vector<int>& arr) {
    std::vector<int> tail;
    // Process array in reverse to find LDS
    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        int num = *it;
        auto pos = std::lower_bound(tail.begin(), tail.end(), num);
        if (pos == tail.end()) {
            tail.push_back(num);
        } else {
            *pos = num;
        }
    }
    return tail.size();
}
void solve() {
    int n; 
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++)cin>>A[i];
    int is = lis(A);
    int ds = lds(A);
    if(is>ds) cout<<"First"<<endl;
    else if(ds>is) cout<<"Second"<<endl;
    else cout<<"Tie"<<endl;

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