#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

struct Items
{
    int v,w;
};
int p[100][100];
int selected_items_index[100][100];
struct Arrow
{
    int I,W;
};
Arrow arrow[100][100];
void knapsack(Items items[],int n,int W)
{
    for(int i=0; i<=n; i++)
    {
        p[i][0]=0;
    }
    for(int w=0; w<=W; w++)
    {
        p[0][w]=0;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=W; j++)
        {
            if(items[i-1].w<=j)
            {
                p[i][j]=max(p[i-1][j],items[i-1].v+p[i-1][j-items[i-1].w]);
                int c1=p[i-1][j];
                int c2=items[i-1].v+p[i-1][j-items[i-1].w];
                if(c1>c2)
                {
                    arrow[i][j].I=i-1;
                    arrow[i][j].W=j;
                }
                else
                {
                    arrow[i][j].I=i-1;
                    arrow[i][j].W=j-items[i-1].w;
                }
            }
            else
            {
                p[i][j]=p[i-1][j];
                arrow[i][j].I=i-1;
                arrow[i][j].W=j;
            }
        }
    }
}
int main()
{
    int n,W;
    cin >> n;
    Items items[n];
    for(int i=0; i<n; i++)
    {
        cin >> items[i].w >> items[i].v;
    }
    cin >> W;
    knapsack(items,n,W);
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=W; j++)
        {
            cout << p[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "_______________________________________________" << endl;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=W; j++)
        {
            cout << arrow[i][j].I << arrow[i][j].W<<"  ";
        }
        cout << endl;
    }
    cout << "_______________________________________________" << endl;
    cout << "Selected items: " << endl;
    int i=n,j=W;
    while(j!=0)
    {
        if(j!=arrow[i][j].W)
        {
            cout << "Item- " << i << endl;
        }
        int temp_index=arrow[i][j].I;
        j=arrow[i][j].W;
        i=temp_index;
    }
}
/*
4
2 12
1 10
3 20
2 15
5
-------
3
3 7
5 9
4 6
5
*/
