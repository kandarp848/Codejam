#include<bits/stdc++.h>
#define io std :: ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define M 1000000007
#define int long long
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl "\n"
#define yy "YES\n"
#define nn "NO\n"
#define ff first
#define ss second
using namespace std;

int sq[60][60], n, k, tc;
bool rows[60][60], cols[60][60],fg;

void solver(int row, int col, int m)
{
    if(row==n && col==n+1 && m==k && !fg)
    {
        fg=true;
        cout << "Case #" << tc << ": " << "POSSIBLE\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << sq[i][j] << " ";
            cout << nl;
        }
        return;
    }
    else if(row > n)
        return;
    else if(col > n)
        solver(row + 1, 1, m);
    for(int i = 1; i <= n && !fg; i++)
    {
        if (!rows[row][i] && !cols[col][i])
        {
            rows[row][i] = cols[col][i] = true;
            if (row == col)
                m += i;
            sq[row][col] = i;
            solver(row,col+1,m);
            rows[row][i] = cols[col][i] = false;
            if (row == col)
                m -= i;
            sq[row][col] = 0;
        }
    }
}

signed main()
{
    io;
    int t;
    cin>>t;
    for(tc=1;tc<=t;tc++)
    {
        cin>>n>>k;
        solver(1,1,0);
        if(!fg)
            cout<<"Case #"<<tc<<": "<<"IMPOSSIBLE\n";
        fg=false;
    }
    return 0;
}
