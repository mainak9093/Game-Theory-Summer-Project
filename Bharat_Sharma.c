#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int *a = malloc((n + 1) * sizeof(int));
        bool *is_blue = malloc((n + 1) * sizeof(bool));

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        // Pre-check: already sorted?
        bool sortedA = true, sortedD = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] != i) sortedA = false;
            if (a[i] != (n + 1 - i)) sortedD = false;
        }
        if (sortedA) {
            printf("Aria Wins\n");
            free(a); free(is_blue);
            continue;
        }
        if (sortedD) {
            printf("Darrus Wins\n");
            free(a); free(is_blue);
            continue;
        }

        // Initialize all locked (red)
        memset(is_blue, 0, (n + 1) * sizeof(bool));

        // Count needed unlocks
        int needA = 0, needD = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != i) needA++;
            if (a[i] != (n + 1 - i)) needD++;
        }

        int unlockedA = 0, unlockedD = 0;
        int turn = 0; // 0 = Aria, 1 = Darrus
        int winner = 0; // 0 = undecided, 1 = Aria, 2 = Darrus, 3 = Tie
        int max_moves = 2 * n + 5;

        for (int move = 0; move < max_moves; move++) {
            // Turn-start win check
            if (turn == 0 && unlockedA == needA) { winner = 1; break; }
            if (turn == 1 && unlockedD == needD) { winner = 2; break; }

            // Try to unlock a helpful position
            bool did_unlock = false;
            for (int i = 1; i <= n; i++) {
                if (is_blue[i]) continue;
                if (turn == 0 && a[i] != i) {
                    is_blue[i] = true; unlockedA++;
                    if (a[i] != (n + 1 - i)) unlockedD++;
                    did_unlock = true; break;
                }
                if (turn == 1 && a[i] != (n + 1 - i)) {
                    is_blue[i] = true; unlockedD++;
                    if (a[i] != i) unlockedA++;
                    did_unlock = true; break;
                }
            }

            // Pass if no unlock possible
            if (!did_unlock) {
                if ((turn == 0 && unlockedA < needA) ||
                    (turn == 1 && unlockedD < needD)) {
                    winner = 3; break;
                }
            }

            turn ^= 1; // Next turn
        }

        // Output result
        if (winner == 1) printf("First\n");
        else if (winner == 2) printf("Second\n");
        else printf("Tie\n");

        free(a);
        free(is_blue);
    }
    return 0;
}