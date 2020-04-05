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
const int N=1500;
signed main()
{
    io;
    int t;
        cin >> t;
        for(int tc = 1; tc <= t; tc++)
        {
            int n;
            cin >> n;
            vector <int> adj[N];
            int mx = 0;
            for(int i = 0; i < n; i++){
                int l,r;
                cin >> l >> r;
                adj[l].pb(i + 1);
                adj[r].pb(-i - 1);
                mx = max({mx,l,r});
            }
            bool fg = true;
            string res = string(n,' ');
            int arr[2] = {1,1};
            string name = "CJ";
            vector<int>out(N);
            for(int i = 0; i < mx + 1; i++)
            {
                sort(all(adj[i]));
                for(int x : adj[i]){
                    if(x > 0){
                        int use;
                        if(arr[0] > 0)  use = 0;
                        else if(arr[1] > 0) use = 1;
                        else{
                            fg = false;
                            break;
                        }
                        res[x - 1] = name[use];
                        out[x] = use;
                        arr[use]--;
                    }
                    else{
                        int ind = -x;
                        arr[out[ind]] = 1;
                    }
                }
                if(!fg) break;
            }
            if(!fg){
                cout<<"Case #"<<tc<<": " << "IMPOSSIBLE\n";
                continue;
            }
            cout<<"Case #"<<tc<<": "<< res << nl;
        }
}
