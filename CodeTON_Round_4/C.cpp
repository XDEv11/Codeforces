//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n; ll c, d;
	cin >> n >> c >> d;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());

	ll ans{n * c + d}, cnt1{0}, cnt2{};
	int l{0};
	for (int i{0}; i < n; ++i) {
		if (v[i] == l) cnt2 += c;
		else cnt1 += (v[i] - 1 - l) * d;
		ans = min(ans, cnt1 + cnt2 + (n - 1 - i) * c);
		l = v[i];
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
