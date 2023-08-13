def get_rectangle_perimeter_sum(matrix, p1, q1, p2, q2):
    r_min, r_max = min(p1, p2), max(p1, p2)
    c_min, c_max = min(q1, q2), max(q1, q2)

    perimeter_sum = 0

    # Top side of the rectangle
    for j in range(c_min, c_max + 1):
        perimeter_sum += matrix[r_min][j]

    # Right side of the rectangle (excluding the top and bottom corners)
    for i in range(r_min + 1, r_max):
        perimeter_sum += matrix[i][c_max]

    # Bottom side of the rectangle
    for j in range(c_max, c_min - 1, -1):
        perimeter_sum += matrix[r_max][j]

    # Left side of the rectangle (excluding the borders of top and bottom)
    for i in range(r_max - 1, r_min, -1):
        perimeter_sum += matrix[i][c_min]

    return perimeter_sum

def main():
    test_cases = int(input("TestCases: "))

    for test_case in range(1, test_cases + 1):
        print(f"Test Case {test_case}:")
        rows, cols = map(int, input("Enter the number of rows and columns: ").split())

        matrix = []
        for _ in range(rows):
            row = list(map(int, input().split()))
            matrix.append(row)

        p1, q1 = map(int, input("Enter the first coordinates ").split())
        p2, q2 = map(int, input("Enter the second coordinates: ").split())

        result = get_rectangle_perimeter_sum(matrix, p1, q1, p2, q2)
        print("Total sum of the perimeter of rectangle", result) #calculating the complete perimeter 
        print()

if __name__ == "__main__":
    main()


