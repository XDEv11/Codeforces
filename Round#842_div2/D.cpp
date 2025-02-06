//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// fast disjoint set union
class DSU {
    vector<int> p, sz;
public:
    explicit DSU(int n) : p(n, -1), sz(n, 1) {}
    int find(int x) { // collapsing find
        return p[x] == -1 ? x : p[x] = find(p[x]);
    }
    void unionn(int x, int y) { // weighted union
        auto rx{find(x)}, ry{find(y)};
        if (rx == ry) return ;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        p[ry] = rx, sz[rx] += sz[ry];
    }
};

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x, --x;

	vector<int> p(n); iota(p.begin(), p.end(), 0);


	int ans{0};
	DSU dsu{n};
	vector<bool> vis(n);
	for (int i{0}; i < n; ++i) {
		if (vis[i]) continue;
		int j{i}, cnt{0};
		do {
			j = v[j], ++cnt;
			vis[j] = true;
			dsu.unionn(i, j);
		} while (j != i);
		ans += cnt - 1;
	}

	bool flag{false};
	for (int i{0}; i + 1 < n; ++i) flag = flag || (dsu.find(i) == dsu.find(i + 1));

	cout << ans + (flag ? -1 : 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
