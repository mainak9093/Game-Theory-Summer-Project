#include <stdbool.h>
#include <stdio.h>

bool is_ascending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

bool is_descending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int count_ascending_moves(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            count++;
        }
    }
    return count;
}

int count_descending_moves(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != n - i) {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        if (is_ascending(arr, n)) {
            printf("First\n");
            continue;
        }
        if (is_descending(arr, n)) {
            printf("Second\n");
            continue;
        }

        int asc_moves = count_ascending_moves(arr, n);
        int desc_moves = count_descending_moves(arr, n);

        if (asc_moves < desc_moves) {
            printf("First\n");
        } else if (desc_moves < asc_moves) {
            printf("Second\n");
        } else {
            printf("Tie\n");
        }
    }
    return 0;
}