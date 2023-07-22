def count_ice_squares(N, M, grid):
    def is_valid(x, y):
        return 1 <= x <= N and 1 <= y <= M

    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    visited = set()
    stack = [(2, 2)]

    while stack:
        x, y = stack.pop()
        if (x, y) in visited:
            continue

        visited.add((x, y))

        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if is_valid(nx, ny) and grid[nx][ny] == '.':
                stack.append((nx, ny))

    return len(visited)

# Read input
N, M = map(int, input().split())
grid = [input() for _ in range(N)]

# Calculate and print the result
result = count_ice_squares(N, M, grid)
print(result)
