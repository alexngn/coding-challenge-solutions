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
typedef vector<vector<ll>> vvi;
typedef vector<pii> vii;
using namespace std;

static ll INF = 1e18;
static ll INF2 = -1e18;
static int mod = 1e9 + 7;

vector<vi> adj;

int main()
{
    int n, m;
    cin >> n >> m;
    vvi weights;

    rep(i, 0, m)
    {
        ll a, b, x;
        cin >> a >> b >> x;
        weights.PB(vi{a, b, x});
        if (a == b && x < 0)
        {
            cout << "YES" << endl;
            cout << a << " " << a;
            return 0;
        }
    }

    vi dist(n + 1, 0);
    dist[1] = 0;
    vi p(n + 1);
    rep(k, 1, n + 1) rep(i, 0, m)
    {
        ll start = weights[i][0];
        ll end = weights[i][1];
        ll w = weights[i][2];
        ll t = w + dist[start];
        if (t < dist[end])
        {
            p[end] = start;
            dist[end] = t;
        }
    }

    vi seen(n + 1);
    rep(i, 0, m)
    {
        ll start = weights[i][0];
        ll end = weights[i][1];
        ll w = weights[i][2];
        ll t = w + dist[start];
        if (t < dist[end])
        {

            vector<int> cycle;
            int node = start;
            while (!seen[node])
            {
                cycle.PB(node);
                seen[node] = 1;
                node = p[node];
            }
            cycle.PB(node);
            reverse(cycle.begin(), cycle.end());
            cout << "YES" << endl;
            while (cycle.back() != cycle.front())
                cycle.pop_back();
            for (int v : cycle)
                cout << v << " ";
            return 0;
        }
    }
    cout << "NO";
}