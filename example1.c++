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

    # Left side of the rectangle (excluding the top and bottom corners)
    for i in range(r_max - 1, r_min, -1):
        perimeter_sum += matrix[i][c_min]

    return perimeter_sum

# Example usage:
matrix = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12]
]
p1, q1 = 0, 1
p2, q2 = 2, 2

result = get_rectangle_perimeter_sum(matrix, p1, q1, p2, q2)
print("Sum of numbers on the perimeter of the rectangle:", result)
