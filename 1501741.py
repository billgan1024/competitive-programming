order = input()
grid = "1234"

for x in order:
    if x == "H":
        new_string = grid[2] + grid[3] + grid[0] + grid[1]
        grid = new_string
        
    else:
        new_string = grid[1] + grid[0] + grid[3] + grid[2]
        grid = new_string
        
print(grid[0], grid[1])
print(grid[2], grid[3])