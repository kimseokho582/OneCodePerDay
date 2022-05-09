#include <iostream>
#include <queue>
using namespace std;
#define MAX_VERTEX 1001

int visit[MAX_VERTEX] = {
    0,
};
int table[MAX_VERTEX][MAX_VERTEX];

int vertexN, edgeN, startVertex;

void dfs(int vertex)
{

    cout << vertex << ' ';
    visit[vertex] = 1;
    for (int i = 1; i <= vertexN; i++)
    {
        if (table[vertex][i] == 1 && visit[i] == 0)
        {
            dfs(i);
        }
    }
}

void bfs(int vertex)
{
    queue<int> tmpQ;
    tmpQ.push(vertex);
    visit[vertex] = 0;
    while (!tmpQ.empty())
    {
        vertex = tmpQ.front();
        cout << vertex << ' ';
        tmpQ.pop();
        for (int i = 1; i <= vertexN; i++)
        {
            if (visit[i] == 1 && table[vertex][i] == 1)
            {
                tmpQ.push(i);
                visit[i] = 0;
            }
        }
    }
}

int main()
{
    int x, y;
    cin >> vertexN >> edgeN >> startVertex;
    for (int i = 0; i < edgeN; i++)
    {
        cin >> x >> y;
        table[x][y] = table[y][x] = 1;
    }
    dfs(startVertex);
    cout << endl;
    bfs(startVertex);
}