#include <iostream>
#include <vector>
using namespace std;

// just checks how far array is from sorted (ascending or descending)
int countWrongPlaces(const vector<int>& a, bool ascending) {
    int wrong = 0;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        if (ascending) {
            if (a[i] != i + 1) wrong++;
        } else {
            if (a[i] != n - i) wrong++;
        }
    }
    return wrong;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int aria = countWrongPlaces(arr, true);
        int darrus = countWrongPlaces(arr, false);

        if (aria < darrus) {
            cout << "Win\n";
        } else if (darrus < aria) {
            cout << "Lose\n";
        } else {
            cout << "Tie\n";
        }
    }
    return 0;
}
