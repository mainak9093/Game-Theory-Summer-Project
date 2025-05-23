#include <bits/stdc++.h>
#define int long long
#define vi vector <int>
#define f(i,n) for(int i = 0 ; i < n ; i++)
#define all(x) x.begin(),x.end()
#define endl '\n' 
using namespace std;
           // Name :- Shivam Gaikwad Roll no :- 240391
void solve(){
    int n; 
    cin >> n; 
    vi a(n);  // array to store input
    f(i,n) cin >> a[i];  //input the array
    if(is_sorted(all(a))){ // if array is already sorted
        cout << "Win" << endl;
        return;
    }
    if(is_sorted(a.rbegin(),a.rend())){ // if array is already reverse sorted
        cout << "Lose" << endl;
        return;
    }
    int cnt1 = 0;   // cnt1 is count of numbers which are in red and at suitable postion w.r.t Aria
    int cnt2 = 0;   // cnt2 is the same for Darrus
    // looping from 0 to n-1
    f(i,n){
// Special Case when n is odd and the middle element is in it's place, we will simply ignore the element as it is in both's favour.
        if( (n & 1) && i == n/2 && a[i] == i + 1) continue;
        if(a[i] == i+1){
          cnt1++;   // if the number is in aria's favour, increment cnt1
        }
        if(a[i] == n-i){
          cnt2++;   // if the number is in Darrus's favour, increment cnt2
        }
    }
                                           /* LOGIC OF THE CODE*/
 // Let's Just ignore the common numbers which both have to unlock (which are neither in both players favour)
 // For Optimal Strategy, Both players will first unlock the numbers which are in their opponent's favour
 // If you didn't follow above strategy and unlock the common number's first, it will eventually benefit opponent
 // Let's Suppose, both player unlocks all the number which were in their opponent's favour and now, only common number's are left,
 // Both players will go on to unlock the common numbers one by one and when there is only one number left both player will do nothing,
 // as if any player unlocked the last number 

     // ARIA's Win condition
     // For Aria to Win, She needs to unlock all n-cnt1 numbers until Darrus unlock all numbers which were in aria's Favour(cnt 1)
     // (This is because the numbers which are in aria's favour, she will never unlock it, only darrus has to do it and vice versa)
     // That is, Numbers to unlock for aria <= Numbers to unlock by Darrus which are in aria's favour
     // The equal to sign is because Aria's turn is first which gives her the edge :)
     // Suppose Darrus unlocks cnt1 numbers before aria unlocks n-cnt1, eventually common numbers will be left and game will be tie
    if( (n-cnt1) <= cnt1){
        cout << "Win" << endl;
        return;
    }
    // Same logic goes for darrus except the equal to sign as Darrus's turn is second :(
    if( (n-cnt2) < cnt2){
        cout << "Lose" << endl;
        return;
    }
    // If the above conditions didn't met, it will eventually be a Tie :)
    cout << "Tie" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}