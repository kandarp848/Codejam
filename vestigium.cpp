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
using namespace std;
signed main()
{
    io;
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int n,trace=0,columns=0,rows=0;
        cin>>n;
        vector<vector<int>>v(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>v[i][j];
                if(i==j)
                    trace+=v[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            map<int,bool>mp;
            for(int j=0;j<n;j++)
            {
                if(!mp[v[i][j]])
                    mp[v[i][j]]=true;
                else
                {
                    rows++;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            map<int,bool>mp;
            for(int j=0;j<n;j++)
            {
                if(!mp[v[j][i]])
                    mp[v[j][i]]=true;
                else
                {
                    columns++;
                    break;
                }
            }
        }
        cout<<"Case #"<<tc<<": "<<trace<<" "<<rows<<" "<<columns<<nl;
    }
}
