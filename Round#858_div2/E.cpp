//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <unordered_map>
#include <stack>
#include <tuple>

using namespace std;

namespace E {
	using ll = long long;
	const int D{100};
	int n, q;
	vector<int> p{}, d{}, dc{}, lb{};
	vector<ll> a{};
	vector<vector<ll>> ans{};
	ll find(int x, int y) {
		if (x > y) swap(x, y);
		if (static_cast<ll>(dc[d[x]]) * dc[d[x]] <= n) {
			if (lb[y] < ans[x].size()) {
			   if (ans[x][lb[y]] != -1) return ans[x][lb[y]];
			} else ans[x].resize(lb[y] + 1, -1);
			return ans[x][lb[y]] = find(p[x], p[y]) + a[x] * a[y];
		}
		return find(p[x], p[y]) + a[x] * a[y];
	}
	void solve() {
		cin >> n >> q;
		a.resize(n);
		for (auto& x : a) cin >> x;
		p.resize(n), d.resize(n), dc.assign(n, 0), lb.resize(n);
		p[0] = -1, d[0] = 0, lb[0] = 0;
		for (int i{1}; i < n; ++i) cin >> p[i], --p[i], d[i] = d[p[i]] + 1, lb[i] = dc[d[i]]++;

		ans.assign(n, {}), ans[0] = {a[0] * a[0]};
		while (q--) {
			int x, y;
			cin >> x >> y, --x, --y;

			cout << find(x, y) << '\n';
		}
	}
};

namespace E2 {
	using ll = long long;
	const int D{100};
	int n, q;
	vector<ll> a{};
	vector<int> p{}, d{};
	unordered_map<ll, ll> ans{};
	ll find(int x, int y) {
		if (x > y) swap(x, y);
		if (d[x] % D == 0) {
			ll id{static_cast<ll>(x) * n + y};
			auto it{ans.find(id)};
			if (it != ans.end()) return it->se;
			return ans[id] = find(p[x], p[y]) + a[x] * a[y];
		}
		return find(p[x], p[y]) + a[x] * a[y];
	}
	void solve() {
		cin >> n >> q;
		a.resize(n);
		for (auto& x : a) cin >> x;
		p.resize(n), d.resize(n);
		p[0] = -1, d[0] = 0;
		for (int i{1}; i < n; ++i) cin >> p[i], --p[i], d[i] = d[p[i]] + 1;

		ans.clear(), ans[0] = a[0] * a[0];
		while (q--) {
			int x, y;
			cin >> x >> y, --x, --y;

			cout << find(x, y) << '\n';
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) E2::solve();
}
