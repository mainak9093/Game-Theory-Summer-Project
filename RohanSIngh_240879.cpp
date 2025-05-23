#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <numeric>
#include <iomanip>
#include <climits>
#define endl '\n'
#define int long long
#define For(i,a,b) for(int i=a; i<b; i++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(x) (x).begin(), (x).end()
#define inSet(st,num) (st.find(num)!=st.end())
#define minPair(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define pii pair<int,int>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    // An optimal strategy for both the players would be to make blue such numbers which are not at there correct place and also they are
    // in correct place for opponent so that any player do not give chance to their opponent 
    // for eg. 4 3 1 2 for Aria none of the numbers are in correct place but for Darrus 4 and 3 are in correct place so optimal move for aria
    // will be to make either 3 or 4 Blue so that aria is getting advantage and Darrus is getting nothing because for him 3 and 4 are already
    // in right place.

    // In
    
    // For Aria since Aria is making first move if the number of correctly placed numbers for Aria are either n/2 or greater Aria is winning
    // For Darrus since he is making second move if the number of correctly placed numbers for Darrus are greater than n/2
    // there is one edge case which is contradicting above argument example.. numbers are 5 2 3 4 1 here 3 is set for both Aria and Darrus
    // so both have number of correctly placed > n/2 still Aria wins 
    // in all other cases it leads to draw

    // Why this is a winning strategy?
    // for win either of the player have to turn blue the positions which or not in correct position for them which is only possible if 
    // majority elements are in correct position for the player also Aria is making first move so she will win when number of elements
    // are in correct position for her are exactly n/2 (n is even)

    // Players cannot deviate from the strategy it will lead to either lose or draw
    // for example.. 1 2 4 3
    // here let's say Aria turns 1 blue
    // then Darrus sets 2 blue
    // now if Aria turns any of them blue it will lead to  draw or lose

    int setAria = 0, setDarrus = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == i+1) {
            setAria++;
        }
        if(arr[i] == n - (i+1)) {           // Not else if because in case 5 2 3 4 1    3 is set for both Aria and Darrus
            setDarrus++;
        }
    }
    if(setAria >= (n%2==0 ? n/2 : n/2 + 1)) {
        cout << "Win" << endl;
    } else if(setDarrus > n/2) {
        cout << "Lose" << endl;
    } else {
        cout << "Tie" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
// Test Case failed to pass:
// 5
// 3 4 5 2 1
// Expected output: Lose
// Your Output : Tie