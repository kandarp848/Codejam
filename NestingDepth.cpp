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
        string s,res="";
        cin>>s;
        int n=s.length(),pre=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]-'0'==pre)
                res+=s[i];
            else if(s[i]-'0'>pre)
            {
                for(int j=0;j<(s[i]-'0')-pre;j++)
                    res+='(';
                res+=s[i];
                pre=s[i]-'0';
            }
            else
            {
                for(int j=0;j<pre-(s[i]-'0');j++)
                    res+=')';
                res+=s[i];
                pre=s[i]-'0';
            }
        }
        for(int i=0;i<pre;i++)
            res+=')';
        cout<<"Case #"<<tc<<": "<<res<<nl;
    }
}
