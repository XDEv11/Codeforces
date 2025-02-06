//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define fi first
#define se second

using namespace std;

const long long mod{998244353};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (auto& x : a) cin >> x, --x;
	for (auto& x : b) cin >> x, --x;

	long long ans{1};

	vector<vector<pair<int, int>>> adj(n);
	for (int i{0}; i < n; ++i) {
		if (a[i] == b[i]) continue;
		adj[a[i]].emplace_back(b[i], i);
		adj[b[i]].emplace_back(a[i], i);
	}

	vector<bool> fixed(n);
	for (int i{0}; i < n; ++i) {
		if (a[i] == b[i]) {
			if (fixed[a[i]]) return cout << "0\n", []{}();
			fixed[a[i]] = true;
			ans = (ans * n) % mod;
		}
	}

	vector<pair<int, int>> cnt(n);
	for (int i{0}; i < n; ++i) {
		++cnt[a[i]].fi, cnt[a[i]].se = i;
		++cnt[b[i]].fi, cnt[b[i]].se = i;
	}
	for (int w{0}; w < n; ++w) {
		if (cnt[w].fi == 1) {
			if (a[cnt[w].se] == w) --cnt[];

		}
	}

	for (int w{0}; w < n; ++w) {
		if (fixed[w]) {
			queue<int> qu{}; qu.push(w);
			while (!qu.empty()) {
				auto u{qu.front()}; qu.pop();
				for (auto& [v, idx] : adj[u]) {
					if (fixed[v]) return cout << "0\n", []{}();
					fixed[v] = true;
					qu.push(v);
				}
			}
		}
	}

	for (int w{0}; w < n; ++w) {
		if (fixed[w]) continue;
		queue<int> qu{}; qu.push(w);
		while (!qu.empty()) {
			auto u{qu.front()}; qu.pop();
			for (auto& [v, i] : adj[u]) {
				if (fixed[v]) continue;
				fixed[v] = true;
				qu.push(v);
			}
		}
		ans = (ans * 2) % mod;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
