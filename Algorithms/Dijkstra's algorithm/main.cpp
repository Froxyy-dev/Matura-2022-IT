#include <iostream>

using namespace std;

#define INF 999

int V, src, cost[100][100], dist[100], parent[100];
bool visited[100];

void initialize()
{
    for(int i=0; i<V; i++)
    {
        parent[i] = i;
        dist[i] = INF;
    }
    dist[src] = 0;
}

int getNearest()
{
    int minValue = INF;
    int minNode = 0;
    for(int i=0; i<V; i++)
        if(!visited[i] && dist[i] < minValue)
        {
            minValue = dist[i];
            minNode = i;
        }
    return minNode;
}

void djikstra()
{
    for(int i=0; i<V; i++)
    {
        int nearest = getNearest();
        visited[nearest] = true;

        for(int adj=0; adj<V; adj++)
        {
            if(cost[nearest][adj] != INF && dist[nearest] + cost[nearest][adj] < dist[adj])
            {
                dist[adj] = dist[nearest] + cost[nearest][adj];
                parent[adj] = nearest;
            }
        }
    }

}

void display()
{
    cout<<"Node:\t\t\tCost:\t\t\tPath";
    for(int i=0; i<V; i++)
    {
        cout<<endl;
        cout<<i<<"\t\t\t"<<dist[i]<<"\t\t\t"<<" ";
        cout<<i<<" ";

        int parNode = parent[i];
        while(parNode != src)
        {
            cout<<" <- "<<parNode<<" ";
            parNode = parent[parNode];
        }
        if(i != src)
            cout<<" <- "<<src<<" ";
        cout<<endl;
    }
}

int main()
{
    cin>>V;
    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            cin >> cost[i][j];
    cin>>src;

    initialize();
    djikstra();
    display();

    return 0;
}

/*

    0   4   999 999 999 999 999 8   999
4   0   8   999 999 999 999 8   999
999 8   0   7   999 4   999 999 2
999 999 7   0   9   14  999 999 999
999 999 999 9   0   10  999 999 999
999 999 4   14  10  0   2   999 999
999 999 999 999 999 2   0   1   6
8   11  999 999 999 999 1   0   7
999 999 2   999 999 999 6   7   0

*/
