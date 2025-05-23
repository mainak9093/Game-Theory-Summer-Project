#include <bits/stdc++.h>
using namespace std;

string game_outcome(const vector<int>& perm) {
    int n = perm.size();
    int a = 0, b = 0, c = 0;

    // Classify each index as A-only, B-only, or common
    for (int i = 0; i < n; ++i) {
        int val = perm[i];
        bool needsA = (val != i+1);           // not already in ascending spot
        bool needsB = (val != (n - i));       // not already in descending spot

        if (needsA && needsB) {
            c++;  // common—both want it unlocked
        }
        else if (needsA) {
            a++;  // A-only
        }
        else if (needsB) {
            b++;  // B-only
        }
        // if neither needs it, it's already fixed for both—ignore
    }

    // Case 1: no overlap
    if (c == 0) {
        // pure race on uniques
        return (a <= b ? "Win" : "Lose");
    }

    // Case 2: there is common overlap
    if (a == 0 && b > 0) {
        // Aria start touching commons first
        return "Win";
    }
    if (b == 0 && a > 0) {
        // Darrus start touching commons first
        return "Lose";
    }

    // both have uniques and there is an overlap → neither wants to start on commons
    return "Tie";
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> perm(n);
        for (int i = 0; i < n; ++i) {
            cin >> perm[i];
        }
        cout << game_outcome(perm) << "\n";
    }
    return 0;
}