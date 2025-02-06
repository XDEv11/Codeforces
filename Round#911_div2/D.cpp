//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());

	vector<int> cnt(v[n - 1] + 1), ans{cnt};
	for (int i{0}; i < n; ++i) {
		for (int d{1}; d * d <= v[i]; ++d) {
			if (v[i] % d) continue;

			if (d * d != v[i]) {

			}
		}
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
