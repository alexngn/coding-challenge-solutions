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

static int mod = 1e9 + 7;
static vector<ll> memo;
vector<int> dist;

vector<vi> adj;

int main()
{
    int n, m;
    cin >> n >> m;
    adj = vector<vi>(n + 1);
    dist = vi(n + 1);
    vi indegree(n + 1);
    vi parents(n + 1);
    vi topsort(n + 1);
    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        adj[a].PB(b);
        indegree[b]++;
    }

    queue<int> q;
    rep(i, 1, n + 1) if (!indegree[i]) q.push(i);
    while (!q.empty())
    {
        int no = q.front();
        q.pop();
        topsort.PB(no);
        trav(node, adj[no])
        {
            if (--indegree[node] == 0)
                q.push(node);
        }
    }

    dist[1] = 1;
    trav(node, topsort) trav(edge, adj[node])
    {
        if (dist[node] && dist[node] + 1 > dist[edge])
            dist[edge] = dist[node] + 1, parents[edge] = node;
    }

    stack<int> order;
    int node = n;
    while (parents[node] != 0)
    {
        order.push(node);
        node = parents[node];
    }
    if (node != 1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    order.push(node);
    cout << order.size() << endl;
    while (!order.empty())
    {
        cout << order.top() << " ";
        order.pop();
    }
}