//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#include <array>
#include <set>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	ll sx, sy;
	cin >> sx >> sy;
	vector<pair<ll, ll>> v(n);
	for (auto& [x, y] : v) cin >> x >> y;

	array<set<int>, 4> st{};
	for (int i{0}; i < n; ++i) {
		auto& [x, y]{cnt[i]};
		st[(((x - sx) & 1) << 1) | ((y - sy) & 1)].insert(i);
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
