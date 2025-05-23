#include <stdio.h>
#include <stdbool.h>

bool is_asc(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool is_des(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

int count_asc_moves(int arr[], int n)
{
    int
        count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            count++;
        }
    }
    return count;
}

int count_des_moves(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != n - i)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int
            n;
        scanf("%d", &n);
        int arr[n];
        for (int i =
                 0;
             i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        if (is_asc(arr, n))
        {
            printf("Win\n");
            continue;
        }
        if (is_des(arr, n))
        {
            printf("Lose\n");
            continue;
        }

        int asc_moves = count_asc_moves(arr, n);
        int
            des_moves = count_des_moves(arr, n);

        if (asc_moves < des_moves)
        {
            printf("Win\n");
        }
        else if (des_moves < asc_moves)
        {
            printf("Lose\n");
        }
        else
        {
            printf("Tie\n");
        }
    }
    return 0;
}