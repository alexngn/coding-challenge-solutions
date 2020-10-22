#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
using namespace std;

static int mod = 1e9 + 7;
static vector<ll> memo;

vector<vi> adj;
vi visited;
vi ans;
stack<int> path;
bool dfs(int no)
{
    visited[no] = 1;
    path.push(no);

    trav(i, adj[no])
    {
        int visit = visited[i];
        if (visit == 1)
        {
            ans = vi();
            ans.PB(i);
            while (path.top() != i)
            {
                ans.PB(path.top());
                path.pop();
            }
            ans.PB(i);
            reverse(ans.begin(), ans.end());
            return 1;
        }
        if (visit != 2 && dfs(i))
            return 1;
    }
    visited[no] = 2;
    path.pop();
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj = vector<vi>(n + 2);
    visited = vi(n + 2);
    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;

        adj[a].PB(b);
    }
    rep(i, 1, n + 1)
    {
        vi path;
        if (visited[i] != 2 && dfs(i))
        {
            int m = sz(ans);
            cout << m << endl;
            rep(i, 0, m) cout << ans[i] << " ";
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}