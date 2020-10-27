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

int main()
{
    int n, m;
    cin >> n >> m;
    adj = vector<vi>(n + 1);
    vi indegree(n + 1);

    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;

        adj[a].PB(b);
        indegree[b]++;
    }

    queue<int> q;
    rep(i, 1, n + 1) if (!indegree[i]) q.push(i);

    vi ans;
    while (!q.empty())
    {
        int no = q.front();
        q.pop();
        trav(node, adj[no])
        {
            indegree[node]--;
            if (!indegree[node])
                q.push(node);
        }
        ans.PB(no);
    }

    rep(i, 1, n + 1)
    {
        if (indegree[i])
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    trav(node, ans) cout
        << node << " ";
}