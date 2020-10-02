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

set<int> visited;
vector<vi> adj;

int main()
{
    int n, m;
    cin >> n >> m;
    adj = vector<vi>(n+1);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    set<int> red;
    set<int> blue;
    bool isRed = true;
    queue<int> q;
    rep(i, 1, n+1) {
        if(visited.count(i)) continue;
        q.push(i);
        while(!q.empty()) {
            int size = sz(q);
            rep(j, 0, size) {
                int no = q.front();
                q.pop();
                if ((red.count(no) && !isRed) || (blue.count(no) && isRed)) {
                    cout << "IMPOSSIBLE";
                    return 0;
                }
                if (visited.count(no)) continue;
                if (isRed) red.insert(no);
                else blue.insert(no);
                visited.insert(no);
                rep(k, 0, adj[no].size()) q.push(adj[no][k]);
            }
            isRed = !isRed;
        }
    }

    rep(i, 1, n+1) {
        if (red.count(i)) cout << 1 << " ";
        else cout << 2 << " ";
    }
}