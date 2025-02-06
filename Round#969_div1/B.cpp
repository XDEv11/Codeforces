//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n; ll s;
		cin >> n >> s;
		vector<int> p(n);
		for (int v{1}; v < n; ++v) cin >> p[v], --p[v];

		vector<int> d(n);
		for (int v{1}; v < n; ++v) d[v] = d[p[v]] + 1;

		vector<int> len(n), c1(n, -1), c2(n, -1);
		for (int v{0}; v < n; ++v) {
			int u{v}, w{(v + 1) % n};
			while (u != w) {
				if (d[u] < d[w]) swap(u, w);
				(c1[u] == -1 ? c1[u] : c2[u]) = v, ++len[v];
				u = p[u];
			}
		}

		ll t{}; int f{n};
		for (int _{}; _ < n - 1; ++_) {
			int v; ll c{};
			cin >> v >> c, --v;
			if (!--len[c1[v]]) --f;
			if (!--len[c2[v]]) --f;
			t += c;

			cout << (t * 2 + (s - t) * f) << ' ';
		}
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
