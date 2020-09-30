#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
using namespace std;

static int mod = 1e9 + 7;
static vector<ll> memo;

set<int> visited;
vector<vi> adj;

void dfs(int a)
{
    if (visited.find(a) != visited.end())
        return;
    visited.insert(a);
    rep(i, 0, adj[a].size())
    {
        dfs(adj[a][i]);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj = vector<vi>(n + 1);
    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;
    int prev = 0;
    vii bridges;
    rep(i, 1, n + 1)
    {
        if (!visited.count(i))
        {
            ans++;
            dfs(i);
            if (prev)
            {
                bridges.push_back({i, prev});
            }
            prev = i;
        }
    }
    cout << ans - 1 << endl;
    rep(i, 0, bridges.size())
    {
        cout << bridges[i].first << " " << bridges[i].second << endl;
    }
}