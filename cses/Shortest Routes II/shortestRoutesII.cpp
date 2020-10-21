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
typedef long long ll;
typedef pair<int, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vii;
using namespace std;

static ll INF = 1e18;
static int mod = 1e9 + 7;
static vector<ll> memo;

vector<vi> adj;
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    adj = vector<vi>(n + 1, vi(n + 1, INF));
    rep(i, 1, n + 1) adj[i][i] = 0;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (adj[a][b] != INF)
            adj[a][b] = min(adj[a][b], (ll)c);
        else
            adj[a][b] = c;
        adj[b][a] = adj[a][b];
    }

    rep(k, 1, n + 1) rep(i, 1, n + 1) rep(j, 1, n + 1)
    {
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << (adj[a][b] == INF ? -1 : adj[a][b]) << endl;
    }
}