//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	long long ans{0};
	long long s1{0}, s2{0};
	for (int i{n - 1}; i >= 0; --i) {
		if (s2 < v[i]) {
			v[i] -= s2;
			auto k2{min(k, i + 1)};
			auto t{(v[i] + k2 - 1) / k2};
			s2 += t * k2, ans += t;
			s1 += t, v[i] = t;
		} else v[i] = 0;

		if (i + k < n) s1 -= v[i + k];
		s2 -= s1;
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
