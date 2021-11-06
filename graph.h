#include <unordered_set>
#include <iostream>
using namespace std;

class graph
{
public:
    //using adjacency list
    vector<vector<int>> matrix;
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
        if (!matrix.empty())
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
        else
        {
            if()
        }
    }
};