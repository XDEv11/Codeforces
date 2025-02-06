//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	using ll = long long;

	ll n;
	cin >> n;

	vector<ll> ans{1};
	ll t{n};
	for (ll f{2}; f * f <= n; ++f) {
		for (int i{0}; i < n; ++i) {
			if (t % f) break;
			t /= f;
			if (i == ans.size()) ans.push_back(1);
			ans[i] *= f;
		}
	}
	if (t > 1) ans[0] *= t;

	cout << accumulate(ans.begin(), ans.end(), 0ll) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
