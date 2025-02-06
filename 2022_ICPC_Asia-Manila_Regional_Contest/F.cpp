//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#define fi first
#define se second
#include <map>
#include <algorithm>

using namespace std;

bool solve() {
	using ll = long long;

	int n;
	if (!(cin >> n)) return false;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	ll s{};
	set<pair<ll, int>> st{};
	map<int, ll> mp{};
	for (int i{0}; i < n; ++i) s += v[i], st.emplace(v[i], i), mp[i] = v[i];

	vector<pair<int, ll>> ans{};
	for (int _{0}; _ < n; ++_) {
		auto sit{st.rbegin()->fi <= s / 2 ? st.lower_bound({st.rbegin()->fi, 0}) : st.begin()};
		auto [x, i]{*sit}; st.erase(sit);
		s -= x;

		auto mit{mp.find(i)};
		if (mit != mp.begin()) {
			auto& [j, y]{*prev(mit)};
			st.erase(pair<ll, int>{y, j}), y += x / 2, st.emplace(y, j);
			s += x / 2;
		}
		if (next(mit) != mp.end()) {
			auto& [k, z]{*next(mit)};
			st.erase(pair<ll, int>{z, k}), z += x / 2, st.emplace(z, k);
			s += x / 2;
		}
		mp.erase(mit);

		ans.emplace_back(i, x);
	}

	for (auto& [x, y] : ans) cout << (x + 1) << ' ' << y << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
