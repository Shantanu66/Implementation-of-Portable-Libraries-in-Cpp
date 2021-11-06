#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

class graph
{
public:
    //using adjacency list
    vector<vector<int>> matrix;
    int n=matrix.size();
    vector<bool> visited(n,false);
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
                DFS( i + 1, visited);
            }
        }
    }
    //shortest source single path algo(Dijikstra)
    
};