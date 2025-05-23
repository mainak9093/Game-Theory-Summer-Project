#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSortedAscending(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

bool isSortedDescending(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > arr[i - 1]) return false;
    }
    return true;
}

string whoWinsTheGame(vector<int>& arr) {
    int n = arr.size();

        vector<int> ascending = arr;
    sort(ascending.begin(), ascending.end()); // [1, 2, ..., n]

    vector<int> descending = ascending;
    reverse(descending.begin(), descending.end()); // [n, n-1, ..., 1]

    // First, just in case, check if the array is already sorted
    if (arr == ascending) return "Win";  // Aria already won
    if (arr == descending) return "Lose";  // Darrus already won

       // - If n is odd, Aria unlocks the last number → she gets to rearrange first
    // - If n is even, Darrus does → he rearranges first

    if (n % 2 == 1) {
        // Aria rearranges first → she can win by arranging in ascending order
        return "Win";
    } else {
        // Darrus rearranges first → he will try to win
        // But Aria can undo his rearrangement next turn
        // So unless Darrus wins immediately, it’s a Tie
        return "Tie";
    }
}

// Main function to read input and run the game
int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n; 
        vector<int> arr(n); 
                for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

               cout << whoWinsTheGame(arr) << endl;
    }

    return 0;
}

