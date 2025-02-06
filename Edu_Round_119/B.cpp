//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>

using namespace std;

void solve() {
	int w, h;
	cin >> w >> h;
	array<vector<int>, 4> a{};
	for (auto& v : a) {
		int k;
		cin >> k;
		v.resize(k);
		for (auto& x : v) cin >> x;
	}

	long long ans{0};
	for (int i{0}; i < 4; ++i) {
		ans = max(ans, static_cast<long long>(a[i].back() - a[i].front()) * (i <= 1 ? h : w));
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
