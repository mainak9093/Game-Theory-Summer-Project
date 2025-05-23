def analyze_game(n, sequence):
    if sequence == sorted(sequence):
        return "Win"
    if sequence == sorted(sequence, reverse=True):
        return "Lose"

    aria_positions = 0
    darrus_positions = 0

    for i in range(n):
        if sequence[i] == i + 1:
            aria_positions += 1
        if sequence[i] == n - i:
            darrus_positions += 1

    steps_needed_aria = n - aria_positions
    steps_needed_darrus = n - darrus_positions

    # Aria plays first, so tie-breaking favors her on equality
    if steps_needed_aria <= aria_positions:
        return "First"
    if steps_needed_darrus < darrus_positions:
        return "Second"

    return "Tie"

def main():
    test_cases = int(input())
    for _ in range(test_cases):
        size = int(input())
        array = list(map(int, input().split()))
        result = analyze_game(size, array)
        print(result)

if __name__ == "__main__":
    main()
#Cases where both have numbers in common is not considered
#Test Cases not passes
#Code had crux of the idea of the solution
#Code is not commented