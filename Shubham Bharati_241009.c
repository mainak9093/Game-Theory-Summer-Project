/* My logic is that between Aria and Darus that person will win who first unlock all the
 elements in the array which are not at the right place according to each of 
them. For example for Aria in array{1,5,6,3,2,4} 1 is only at its right place and for Darus in 
array{1,5,6,3,2,4} 2,3 and 5 are at its right place.So they will unlock
the other elements and also first those elements which are at the right place according to their 
rivals like in the above example Aria will first unlock 2,3 and 5 
while darus will unlock 1. After unlocking these elements each player will go for other elements which 
they have to unlock and that elements will be common for both
players like in the above example Aria and Darus both have 4 and 6 as that type of elements.
 They will unlock until they have one element left to unlock to win after
unlocking as mentioned if their rival also had  only 1 element left they will not unlock the
 element beacuse next turn is of their rival so their rival will now arrange 
the elements and win.So in this case either the player will rearrange the elements or pass 
the turn. Ultimately this case leads to tie.But if the rival has left with 
more than 1 element then the player will unlock the 1 element which is only left for his win
 and this ultimately lead to his win.
Optimal starategy--- First the player will unlock that elements which are at the right place
 according to their rivals. Then unlock other elements which they have to 
unlock and that elements will be common for both players. If at the end both the plyaer and 
their rival left with only 1 element to unlock then the player will not
unlock the element as it will lead to thair rival's win. In this case either the player will 
pass the turn or rearrange the elements which will lead to tie only.
*/
# include <stdio.h> 
    int main() {
        int t, n, A, AU, D, DU;//AU and DU are the elements which has to be unlocked by Aria and Darus respectively and A and D are elements which are at their right place for the win of Aria and Darus respectively
        scanf("%d", & t);
        for (int j = 0; j < t; j++) {
            A = 0, D = 0;
            scanf("%d", & n);
            int arr[n];//Array of the game
            for (int i = 0; i < n; i++) {
                scanf("%d", & arr[i]);
            }
            for (int i = 0; i < n; i++) {//This loop will give A and D their value according to the arr 
                if (arr[i] == i+1) {
                    A = A + 1;
                }
                else if (arr[i] == n - i) {
                    D = D + 1;
                }
            }
            AU = n - A;//This loop will give AU its value according to the arr
            DU = n - D;//This loop will give DU its value according to the arr
            int x = 1;
            while ((AU != 1 || DU != 1) && (DU != 0) && (AU != 0)) {//This loop will decide that when game proceeds AU and DU will reaches to 1 first which leads to tie or DU reaches to 0 first which leads to Darus win or AU reaches to 0 which leads to Aria win  
                if (x % 2 == 1) {
                    AU--;
                    if (D == 0) {
                        DU--;
                    }
                    else {
                        D--;
                    }
                }
                else {
                    DU--;
                    if (A == 0) {
                        AU--;
                    }
                    else {
                        A--;
                    }
                }
                x++;
            }
            if (AU == 1 && DU == 1) {
                printf("Tie\n");
            }
            else if (AU == 0) {
                printf("First\n");
            }
            else if (DU == 0) {
                printf("Second\n");
            }
        }
        return 0;
    }
// Consider the test case
// 4
// 1 3 2 4
// It gives output tie , when the output should be win
// Your optimal strategy is correct, but your core logic is incorect and fails to pass all test cases
//Also you used while loop to run was unnecessary and could be done iteratively
