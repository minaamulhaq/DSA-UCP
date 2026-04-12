#include <iostream>
// #include <stack>
#include <fstream>
#include"../myStack.h"
using namespace std;
struct Node
{
    int x, y;
    Node() {} 
    Node(int _x, int _y) : x(_x), y(_y) {}
};

bool isSafe(int **maze, int size, int x, int y)
{
    if (x >= 0 && x < size && y >= 0 && y < size && maze[x][y] == 1)
        return true;
    return false;
}

myStack<Node> solveMaze(int **maze, int n, int x, int y);

void printMaze(int **maze, int rowCount, int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}
void clearMaze(int **maze, int rowCount, int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            maze[i][j] = 0;
        }
    }
}

int main()
{

    ifstream infile;
    infile.open("input.txt");
    // if file not open then simple print error message and return 1
    if (!infile.is_open())
    {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    string line;
    int rowCount = 0;
    // Count the number of rows in the file by reading it line by line
    while (getline(infile, line))
    {
        if (!line.empty()) // ignore empty lines
            rowCount++;
    }
    infile.close();

    // Create a 2D array to store the maze using rowCount;
    int **maze = new int *[rowCount];
    for (int i = 0; i < rowCount; i++)
    {
        maze[i] = new int[rowCount];
    }

    // Read the maze from the file and store it in the 2D array
    infile.open("input.txt");
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < rowCount; j++)
        {
            infile >> maze[i][j];
        }
    }
    infile.close();

    cout << "Maze loaded:" << endl;
    printMaze(maze, rowCount, rowCount);
    myStack<Node> path = solveMaze(maze, rowCount, 0, 0);
    clearMaze(maze, rowCount, rowCount);
    ofstream outfile;
    outfile.open("output.txt");
    cout << "Output Maze:" << endl;
    if (path.isEmpty())
    {
        outfile << "No Path Found" << endl;
    }
    else
    {
        while (!path.isEmpty())
        {
            Node current = path.top();
            path.pop();
            maze[current.x][current.y] = 1; // Mark the path in the maze
        }
        for (int i = 0; i < rowCount; i++)
        {
            for (int j = 0; j < rowCount; j++)
            {
                outfile << maze[i][j] << " ";
                cout << maze[i][j] << "  ";
            }
            outfile << endl;
            cout << endl;
        }
    }

    outfile.close();

    for (int i = 0; i < rowCount; i++)
    {
        delete[] maze[i];
    }
    delete[] maze;

    return 0;
}

// Function to solve the maze using backtracking

myStack<Node> solveMaze(int **maze, int n, int x, int y)
{
    myStack<Node> path(1000);
    path.push(Node(x, y));
    maze[x][y] = -1;

    while (!(x == n - 1 && y == n - 1))
    {
        if (isSafe(maze, n, x - 1, y))
        {
            path.push({x - 1, y});
            x = x - 1;
        }
        else if (isSafe(maze, n, x, y + 1))
        {
            path.push({x, y + 1});
            y = y + 1;
        }
        else if (isSafe(maze, n, x + 1, y))
        {
            path.push({x + 1, y});
            x = x + 1;
        }
        else if (isSafe(maze, n, x, y - 1))
        {
            path.push({x, y - 1});
            y = y - 1;
        }
        else
        {
            if (path.isEmpty())
            {
                cout << "No Path Found";
                return myStack<Node>(0);
            }
            Node last = path.top();
            path.pop();
            x = last.x;
            y = last.y;
        }
        maze[x][y] = -1;
    }

    return path;
}