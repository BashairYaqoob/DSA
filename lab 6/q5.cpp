#include <iostream>
using namespace std;

const int N=5;

bool isSafe(int maze[N][N], int x, int y){
	return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMaze(int maze[N][N],int solution[N][N] ,int x, int y){
	if(x==2 && y==2){
		solution[x][y]=1;
		return true;
	}
	if(isSafe(maze, x, y) && solution[x][y] == 0){
		solution[x][y] = 1;

        if (solveMaze(maze, solution, x, y + 1)) {
            return true;
        }

        if (solveMaze(maze, solution, x + 1, y)) {
            return true;
        }
        
        if (solveMaze(maze, solution, x - 1, y)) {
            return true;
        }
        
        if (solveMaze(maze, solution, x , y-1)) {
            return true;
        }

        solution[x][y] = 0;
	}
	return false;
}

int main(){
	int maze[N][N]={
	{1,1,1,0,1},
	{0,1,0,1,1},
	{1,1,1,1,0},
	{0,1,0,1,1},
	{1,1,1,0,1}
	};
	
	int solutioncat[N][N]={0};
	int solutionrabbit[N][N]={0};
	
	cout<<"Solution for cat: \n";
	if (solveMaze(maze, solutioncat, 4, 4)) {
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << solutioncat[i][j] << " ";
            }
            cout << std::endl;
        }
    } else {
        cout << "No path to the meat found." << std::endl;
    }
    
    cout<<"\nSolution for Rabbit:\n";
    if (solveMaze(maze, solutionrabbit, 0, 0)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << solutionrabbit[i][j] << " ";
            }
            cout << std::endl;
        }
    } else {
        cout << "No path to the meat found." << std::endl;
    }
    
	return 0;
}
