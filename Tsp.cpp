//TSP
#include <iostream>
#include <iomanip>
using namespace std;
class tsp
{
    int n, a[10][10], v[10];

public:
    int cost;
    void read_matrix();
    int least(int);
    int mincost(int);
    tsp()
    {
        cost = 0;
    }
};
void tsp::read_matrix()
{
    int i, j;
    cout << "Enter the number of cities\n";
    cin >> n;
    cout << "Enter the cost matrix\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
            v[i] = 0;
        }
}
int tsp::least(int c)
{
    int i, nc = 999, min = 999;
    for (i = 0; i < n; i++)
    {
        if (a[c][i] != 0 && v[i] == 0)
            if (a[c][i] <= min)
            {
                min = a[c][i];
                nc = i;
            }
    }
    if (min != 999)
        cost += min;
    return nc;
}
int tsp::mincost(int city)
{
    int i, ncity;
    v[city] = 1;
    cout << city << setw(5);
    ncity = least(city);
    if (ncity == 999)
    {
        ncity = 0;
        cout << ncity;
        cost += a[city][ncity];
        return 0;
    }
    mincost(ncity);
    return 0;
}
int main()
{
    int i, j, source;
    tsp t;
    t.read_matrix();
    cout << "Enter the source city\n";
    cin >> source;
    cout << "Sequence of cities visited\n";
    t.mincost(source);
    cout << "\nThe minimum cost is " << t.cost;
    return 0;
}
