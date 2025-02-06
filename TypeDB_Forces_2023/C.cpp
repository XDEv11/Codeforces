//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n; ll s;
	cin >> n >> s;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	vector<ll> dp0(n), dp1(n);
	vector<ll> aux0(n), aux1(n);
	aux0[0] = aux1[0] = v[0];
	for (int i{1}; i < n - 1; ++i) {
		ll a, b;
		if (v[i] <= s) a = 0, b = v[i];
		else if (v[i] <= 2 * s) a = (v[i] - s), b = s;
		else a = s, b = (v[i] - s);

		dp0[i] = min(dp0[i - 1] + aux0[i - 1] * a, dp1[i - 1] + aux1[i - 1] * a);
		aux0[i] = b;
		dp1[i] = min(dp0[i - 1] + aux0[i - 1] * b, dp1[i - 1] + aux1[i - 1] * b);
		aux1[i] = a;
	}

	cout << min(dp0[n - 2] + aux0[n - 2] * v[n - 1], dp1[n - 2] + aux1[n - 2] * v[n - 1]) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
