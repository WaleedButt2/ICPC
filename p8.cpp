#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <limits.h>
#include <queue>
using namespace std;
class map
{
public:
    bool t = false;
    bool flag;
    queue<int> qx;
    queue<int> qy;
    int **maze;
    int u, v;
    bool **visited;
    int start_pos_x, start_pos_y;
    map(int u, int v)
    {
        flag = false;
        this->u = u;
        this->v = v;
        maze = new int *[u];
        for (int i = 0; i < u; i++)
            maze[i] = new int[v];
        visited = new bool *[u];
        for (int i = 0; i < u; i++)
            visited[i] = new bool[v];
        start_pos_x = -1;
        start_pos_y = -1;
    }
    void BackTrack(int u, int v, int dist, int &min_dist)
    {
        if (maze[u][v] == 2)
        {
            min_dist = min(dist, min_dist);
            return;
        }
        visited[u][v] = true;
        //    cout<<u<<' '<<v<<endl;
        //    print_visit();
        if (u + 1 < this->u && maze[u + 1][v] != 3 && maze[u + 1][v] != 4)
            if (!visited[u + 1][v])
                BackTrack(u + 1, v, dist + 1, min_dist);
        if (u - 1 >= 0 && maze[u - 1][v] != 3 && maze[u - 1][v] != 4)
            if (!visited[u - 1][v])
                BackTrack(u - 1, v, dist + 1, min_dist);
        if (v + 1 < this->v && maze[u][v + 1] != 3 && maze[u][v + 1] != 4)
            if (!visited[u][v + 1])
                BackTrack(u, v + 1, dist + 1, min_dist);
        if (v - 1 >= 0 && maze[u][v - 1] != 3 && maze[u][v - 1] != 4)
            if (!visited[u][v - 1])
                BackTrack(u, v - 1, dist + 1, min_dist);
        visited[u][v] = false;
    }
    void print_visit()
    {
        for (int i = 0; i < u; i++)
        {
            for (int j = 0; j < v; j++)
                if (visited[i][j] == true)
                    cout << 1 << ' ';
                else
                    cout << 0 << ' ';
            cout << endl;
        }
        cout << endl;
    }
    void read()
    {
        for (int i = 0; i < u; i++)
            for (int j = 0; j < v; j++)
                visited[i][j] = false;
        for (int i = 0; i < u; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cin >> maze[i][j];
                if (maze[i][j] == 1)
                {
                    start_pos_x = i;
                    start_pos_y = j;
                }
            }
        }
        cout << endl;
        blocks();
    }
    void blocks()
    {
        for (int i = 0; i < u; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (maze[i][j] == 3)
                {
                    if (i + 1 != u)
                        if (maze[i + 1][j] == 0)
                            maze[i + 1][j] = 4;
                    if (!i - 1 < 0)
                        if (maze[i - 1][j] == 0)
                            maze[i - 1][j] = 4;
                    if (j + 1 != v)
                        if (maze[i][j + 1] == 0)
                            maze[i][j + 1] = 4;
                    if (!j - 1 < 0)
                        if (maze[i][j - 1] == 0)
                            maze[i][j - 1] = 4;
                    if (i + 1 != u && j + 1 != v)
                        if (maze[i + 1][j + 1] == 0)
                            maze[i + 1][j + 1] = 4;
                    if (!i - 1 < 0 && j + 1 != v)
                        if (maze[i - 1][j + 1] == 0)
                            maze[i - 1][j + 1] = 4;
                    if (!i - 1 < 0 && !j - 1 < 0)
                        if (maze[i - 1][j - 1] == 0)
                            maze[i - 1][j - 1] = 4;
                    if (i + 1 != u && !j - 1 < 0)
                        if (maze[i + 1][j - 1] == 0)
                            maze[i + 1][j - 1] = 4;
                }
            }
        }
    }
    void print()
    {
        for (int i = 0; i < u; i++)
        {
            for (int j = 0; j < v; j++)
                cout << maze[i][j] << ' ';
            cout << endl;
        }
        cout << endl;
    }
};
int main()
{
    int u, v;
    cin >> u >> v;
    map maze(u, v);
    maze.read();
    maze.print();
    int x = INT_MAX;
    maze.BackTrack(maze.start_pos_x, maze.start_pos_y, 0, x);
    if (x == INT_MAX)
        x = -1;
    cout << x << endl;
}
/*
8 8
0 0 0 0 0 0 0 0 
0 1 0 0 0 0 0 0
0 0 0 3 3 0 0 0
0 2 0 3 3 0 0 0
0 0 0 3 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0
*/