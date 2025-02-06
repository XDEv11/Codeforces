//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int maxval{300000};

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	int s, t;
	cin >> s >> t, --s, --t;
	if (s == t) return cout << "1\n" << s + 1 << '\n', []{}();

	vector<vector<int>> adj(n + maxval + 1);
	for (int x{0}; x < n; ++x) {
		for (int y{2}; y * y <= v[x]; ++y) {
			if (v[x] % y) continue;
			while (v[x] % y == 0) v[x] /= y;
			adj[x].push_back(n + y), adj[n + y].push_back(x);
		}
		if (v[x] > 1) adj[x].push_back(n + v[x]), adj[n + v[x]].push_back(x);
	}

	vector<int> pa(n + maxval + 1, -1);
	queue<int> qu{}; qu.push(s), pa[s] = s;
	while (!qu.empty()) {
		auto u{qu.front()}; qu.pop();
		for (auto& v : adj[u]) {
			if (pa[v] != -1) continue;
			qu.push(v), pa[v] = u;
			if (v == t) {
				vector<int> ans{};
				while (t != s) ans.push_back(t), t = pa[pa[t]];
				ans.push_back(s);
				cout << ans.size() << '\n';
				for (int i{ans.size() - 1}; i >= 0; --i) cout << ans[i] + 1 << " \n"[i == 0];
				return ;
			}
		}
	}
	cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	//cin >> t;
	while (t--) solve();
}
