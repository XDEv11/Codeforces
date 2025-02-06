//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second

using namespace std;

void solve() {
	int l, r;
	cin >> l >> r;
	vector<int> v2(r - l + 1);
	for (auto& x : v2) cin >> x;

	vector<int> v1(r - l + 1);
	for (int i{l}; i <= r; ++i) v1[i - l] = i;

	int x{0};
	vector<pair<vector<int>, vector<int>>> s{{v1, v2}};
	for (int b{16}; b >= 0; --b) {
		vector<pair<vector<int>, vector<int>>> ns{};
		bool f{false};
		for (auto& [v1, v2] : s) {
			vector<int> v1o{}, v1e{}, v2o{}, v2e{};
			for (auto& e : v1) ((e >> b) & 1 ? v1o : v1e).push_back(e);
			for (auto& e : v2) ((e >> b) & 1 ? v2o : v2e).push_back(e);
			f = f || (v1o.size() != v2o.size());
		}
		if (f) x |= (1 << b);
		for (auto& [v1, v2] : s) {
			vector<int> v1o{}, v1e{}, v2o{}, v2e{};
			for (auto& e : v1) ((e >> b) & 1 ? v1o : v1e).push_back(e);
			for (auto& e : v2) ((e >> b) & 1 ? v2o : v2e).push_back(e);
			if (!v1o.empty()) ns.emplace_back(v1o, f ? v2e : v2o);
			if (!v1e.empty()) ns.emplace_back(v1e, f ? v2o : v2e);
		}
		s = move(ns);
	}

	cout << x << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
