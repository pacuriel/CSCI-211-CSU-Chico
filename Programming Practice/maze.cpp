//
// Created by Tony PC on 3/5/2021.
//

bool solve_maze(char** maze, ) {

    while (maze[row][col] != "C") {

    }

}



int main() {
    bool result=false;
    int row_count, col_count; // Used for maze dimensions
    char **maze = read_maze(row_count, col_count);
    print_maze(maze, row_count, col_count);
    int row, col; // Tack location of mouse in maze
    result = solve_maze(maze, row_count, col_count, row, col);
    return (result ? 0 : 1);
}