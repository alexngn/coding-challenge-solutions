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
typedef vector<int> vi;
typedef vector<pii> vii;
using namespace std;

static long INF = 1e18;
static int mod = 1e9 + 7;
static vector<ll> memo;

vector<vector<pii>> adj;

class Compare
{
public:
    bool operator()(pii &p1, pii &p2)
    {
        return p1.S > p2.S;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    adj = vector<vector<pii>>(n + 1);
    vector<ll> dist(n + 1, INF);
    vector<ll> minPrice(n + 1, 0);
    vector<ll> minFlight(n + 1, INF);
    vector<ll> maxFlight(n + 1, 0);

    rep(i, 0, m)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].PB({b, c});
    }
    dist[1] = 0;
    minPrice[1] = 1;
    minFlight[1] = 0;
    maxFlight[1] = 0;
    priority_queue<pii, vector<pii>, Compare> pq;
    pq.push({1, 0});
    while (!pq.empty())
    {
        pii p = pq.top();
        pq.pop();
        // Handle Stale
        if (p.S > dist[p.F])
            continue;
        int m = adj[p.F].size();
        rep(i, 0, m)
        {
            int no = adj[p.F][i].F;
            int w = adj[p.F][i].S;
            if (dist[no] > p.S + w)
            {
                pq.push({no, p.S + w});
                dist[no] = p.S + w;
                minPrice[no] = minPrice[p.F];
                minFlight[no] = minFlight[p.F] + 1;
                maxFlight[no] = maxFlight[p.F] + 1;
            }
            else if (dist[no] == p.S + w)
            {
                minPrice[no] += minPrice[p.F];
                minPrice[no] %= mod;
                minFlight[no] = min(minFlight[no], minFlight[p.F] + 1);
                maxFlight[no] = max(maxFlight[no], maxFlight[p.F] + 1);
            }
        }
    }

    cout << dist[n] << " " << minPrice[n] << " " << minFlight[n] << " " << maxFlight[n];
}