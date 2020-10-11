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

static ll INF = -1e18;
static ll INF2 = 1e18;
static int mod = 1e9 + 7;

vector<vector<pii>> adj;

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
    }

    vi dist(n + 1, INF);
    dist[1] = 0;

    rep(k, 1, n) rep(i, 0, m)
    {
        int start = weights[i][0];
        int end = weights[i][1];
        int w = weights[i][2];
        if (dist[start] != INF && w + dist[start] > dist[end])
        {
            dist[end] = w + dist[start];
        }
    }

    rep(k, 1, n) rep(i, 0, m)
    {
        int start = weights[i][0];
        int end = weights[i][1];
        int w = weights[i][2];
        if (dist[start] != INF && w + dist[start] > dist[end])
        {
            dist[end] = INF2;
        }
    }
    cout << (dist[n] >= INF2 ? -1 : dist[n]);
}