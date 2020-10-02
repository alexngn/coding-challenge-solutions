#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
using namespace std;

static int mod = 1e9 + 7;
static vector<ll> memo;

set<int> visited;
vector<vi> adj;

int main()
{
    int n, m;
    cin >> n >> m;
    adj = vector<vi> (n+1);
    vi p(n+1);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<pii> q;
    q.push(make_pair(1,1));
    int par = 1;
    int count = 1;
    while (!q.empty()) {
        int s = sz(q);
        rep(i, 0, s) {
            pii no = q.front();
            q.pop();
            if (visited.count(no.first)) continue;
            visited.insert(no.first);
            p[no.first] = no.second;
            if (no.first == n) {
                cout << count << endl;
                int val = no.first;
                vi ans;
                while (val != 1) {
                    ans.push_back(val);
                    val = p[val];
                }
                ans.push_back(val);
                for (int i = ans.size()-1; i >= 0; i--) cout << ans[i] << " ";
                return 0;
            }
            rep(i, 0, adj[no.first].size()) q.push(make_pair(adj[no.first][i], no.first));
        }
        count++;
    }
    cout << "IMPOSSIBLE" << endl;
}