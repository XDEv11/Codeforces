//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	rotate(v.begin(), find(v.begin(), v.end(), 0), v.end());

	vector<pair<int, int>> t{};
	ll ans{0}, s{0};
	for (int i{1}; i < n; ++i) {
		int c{1};
		while (!t.empty() && t.back().fi > v[i]) {
			s -= ll(t.back().fi) * t.back().se, c += t.back().se;
			t.pop_back();
		}
		t.emplace_back(v[i], c), s += ll(v[i]) * c;
		ans = max(ans, s);
	}

	cout << (ans + n) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
