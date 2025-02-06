//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		vector<array<ll, 2>> t{};
		for (int i{0}; i < n; ++i) t.push_back({v[i] + i, v[i] + i + i});
		sort(t.rbegin(), t.rend());

		map<ll, ll> mp{};
		for (auto& [x, y] : t) mp[x] = max(mp[x], mp.count(y) ? mp[y] : y);

		cout << (mp.count(n) ? mp[n] : n) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
