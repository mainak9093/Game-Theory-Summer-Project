#include <bits/stdc++.h>
#define int long long
#define vi vector <int>
#define f(i,n) for(int i = 0 ; i < n ; i++)
#define all(x) x.begin(),x.end()
#define endl '\n' 
using namespace std;
         
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
    int count1 = 0;   // this is count of numbers which are in red and at suitable postion w.r.t Aria
    int count2 = 0;   // this  is the same for Darrus
    // looping from 0 to n-1
    f(i,n){
// Special Case when n is odd and the middle element is in it's place, we will simply ignore the element as it is in both's favour.
        if( (n & 1) && i == n/2 && a[i] == i + 1) continue;
        if(a[i] == i+1){
          count1++;   // if the number is in aria's favour,   increment cnt1
        }
        if(a[i] == n-i){
          count2++;   // if the number is in Darrus's favour, increment cnt2
        }
    }
                        
    
    if( (n-count1) <= count1){
        cout << "Win" << endl;
        return;
    }
    // Same logic goes for darrus except the equal to sign as Darrus's turn is second :(
    if( (n-count2) < count2){
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
    return 0;}
// #Cases where both have numbers in common is not considered
// #Test Cases not passes
// #Code had crux of the idea of the solution
// #Code is not commented