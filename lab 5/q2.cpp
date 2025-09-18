#include <iostream>
using namespace std;

const int n = 5;

bool isSafe(int maze[n][n], int x, int y, int n)
{
    if (x < n && y < n && maze[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool ratinMaze(int maze[n][n], int x, int y, int solArr[n][n])
{
    if (x == (n - 1) && y == (n - 1))
    {
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y, n))
    {
        solArr[x][y] = 1;
        if (ratinMaze(maze, x + 1, y, solArr))
        {
            return true;
        }
        if (ratinMaze(maze, x, y + 1, solArr))
        {
            return true;
        }
        solArr[x][y] = 0;
    }

    return false;
}

int main()
{
    int maze[n][n] = {
        1,0,1,0,1,
        1,1,1,1,1,
        0,1,0,1,1,
        1,0,0,1,1,
        1,1,1,0,1, 
    };
    int solArr[n][n] = {0};

    if (ratinMaze(maze, 0, 0, solArr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No path to the cheese found!\n";
    }
    return 0;
}
