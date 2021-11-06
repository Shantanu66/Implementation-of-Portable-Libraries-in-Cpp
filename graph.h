#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

class graph
{
public:
    //using adjacency list
    vector<vector<int>> matrix;
    int n = matrix.size();
    vector<bool> visited(n, false);
    void createusingadjacencylist(int N)
    {
        unordered_set<int> List[N + 1];
        cout << "Enter number of edges:" << endl;
        int edges;
        cin >> edges;
        for (auto i = 1; i <= edges; i++)
        {
            cout << "Enter first vertex and second vertex for edge " << i << endl;
            int sv, fv;
            cin >> sv >> fv;
            List[sv].insert(fv);
        }
    }
    //using adjacency matrix
    void createusingadjacencymatrix(int edges)
    {

        for (int i = 1; i <= edges; i++)
        {
            cout << "Enter first and second vertex for edge : " << i << endl;
            int fv, sv;
            cin >> fv >> sv;
            matrix[fv - 1][sv - 1] = 1;
            matrix[sv - 1][fv - 1] = 1;
        }
    }
    bool checkifverticesareconnected(int sv, int ev)
    {
        if (matrix[sv - 1][ev - 1] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void BFS(int &count)
    {
        int n = matrix.size();
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count++;
                queue<int> q;
                q.push(i + 1);
                visited[i] = true;
                while (!q.empty())
                {
                    int sv = q.front();
                    q.pop();
                    cout << sv << endl;
                    for (int j = 0; j < n; j++)
                    {
                        if (matrix[sv - 1][j] && !visited[j])
                        {
                            q.push(j + 1);
                            visited[j] = true;
                        }
                    }
                }
            }
        }
    }

    void DFS(int sv, vector<bool> &visited)
    {
        cout << sv << endl;
        visited[sv - 1] = true;
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[sv - 1][i] == 1 && visited[i] == false)
            {
                DFS(i + 1, visited);
            }
        }
    }
    //shortest source single path algo(Dijikstra)
    vector<int> Dijikstra(int N, vector<vector<int>> mat, vector<vector<int>> adj)
    {
        for (int i = 0; i < mat.size(); i++)
        {
            adj[mat[i][0]][mat[i][1]] = mat[i][2];
            adj[mat[i][1]][mat[i][0]] = mat[i][2];
        }
        vector<int> vertex(N + 1), dist(N + 1, INT_MAX);
        vector<bool> visited(N + 1, false);
        for (int i = 1; i <= N; i++)
        {
            vertex[i] = i;
        }
        dist[1] = 0;
        typedef pair<int, int> Pair;
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        pq.push({0, 1});
        while (!pq.empty())
        {
            int u = pq.top().second;
            int distance = pq.top().first;
            pq.pop();
            visited[u] = true;
            for (int i = 0; i < adj.size(); i++)
            {
                if (adj[u][i] && visited[i] == false)
                {
                    int v = i;
                    int weight = adj[u][i];
                    if ((distance + weight) < dist[v])
                    {
                        dist[v] = distance + weight;
                        pq.push(make_pair(dist[v], v));
                    }
                }
            }
        }
        return dist;
    }
    int Prims(int N, vector<vector<int>> matrix, vector<vector<int>> adj)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            adj[matrix[i][0]][matrix[i][1]] = matrix[i][2];
            adj[matrix[i][1]][matrix[i][0]] = matrix[i][2];
        }
        int sum = 0;
        typedef pair<int, int> Pair;
        vector<int> vertex(N + 1), parent(N + 1, -1), wt(N + 1, INT_MAX);
        vector<bool> visited(N + 1, false);
        for (int i = 1; i <= N; i++)
        {
            vertex[i] = i;
        }
        wt[1] = 0;
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        pq.push({0, 1});
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            visited[u] = true;
            for (int i = 0; i < adj.size(); i++)
            {
                if (adj[u][i] && visited[i] == false)
                {
                    int v = i;
                    int weight = adj[u][i];
                    if (visited[v] == false && weight < wt[v])
                    {
                        wt[v] = weight;
                        parent[v] = u;
                        pq.push(make_pair(wt[v], v));
                    }
                }
            }
        }
        for (int i = 1; i <= N; i++)
        {
            sum += wt[i];
        }
        return sum;
    }
    void topologicalsort(int N, vector<vector<int>> adj)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            adj[matrix[i][0]][matrix[i][1]] = 1;
        }
        vector<int> indegree(N + 1, 0);
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (adj[i][j] == 1)
                {
                    indegree[j] += 1;
                }
            }
        }
        queue<int> q;
        for (int i = 1; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            cout << u << " ";
            q.pop();
            for (int i = 1; i < adj.size(); i++)
            {
                if (adj[u][i] == 1)
                {
                    int v = i;
                    indegree[v]--;
                    if (indegree[v] == 0)
                    {
                        q.push(v);
                    }
                }
            }
        }
    }
};