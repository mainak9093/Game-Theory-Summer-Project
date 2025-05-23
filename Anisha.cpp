#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string analyze_game(int n, const vector<int>& sequence) {
    vector<int> sorted_asc = sequence;
    sort(sorted_asc.begin(), sorted_asc.end());
    if (sequence == sorted_asc) {
        return "Win";
    }

    vector<int> sorted_desc = sequence;
    sort(sorted_desc.begin(), sorted_desc.end(), greater<int>());
    if (sequence == sorted_desc) {
        return "Lose";  // Note: In Python it was "Lose" with one 's', but in your code it's "Lose"
    }

    int aria_positions = 0;
    int darrus_positions = 0;

    for (int i = 0; i < n; ++i) {
        if (sequence[i] == i + 1) {
            aria_positions += 1;
        }
        if (sequence[i] == n - i) {
            darrus_positions += 1;
        }
    }

    int steps_needed_aria = n - aria_positions;
    int steps_needed_darrus = n - darrus_positions;

    // Aria plays first, so tie-breaking favors her on equality
    if (steps_needed_aria <= aria_positions) {
        return "First";
    }
    if (steps_needed_darrus < darrus_positions) {
        return "Second";
    }

    return "Tie";
}

int main() {
    int test_cases;
    cin >> test_cases;
    for (int _ = 0; _ < test_cases; ++_) {
        int size;
        cin >> size;
        vector<int> array(size);
        for (int i = 0; i < size; ++i) {
            cin >> array[i];
        }
        string result = analyze_game(size, array);
        cout << result << endl;
    }
    return 0;
}