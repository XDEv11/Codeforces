//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	vector<ll> ps(n);
	ps[0] = b[0];
	for (int i{1}; i < n; ++i) ps[i] = ps[i - 1] + b[i];

	vector<ll> v1(n), v2(n);
	for (int i{0}; i < n; ++i) {
		if (i - 1 >= 0) a[i] += ps[i - 1];
		int l{-1}, r{n};
		while (r - l > 1) {
			int m{(l + r) / 2};
			if (ps[m] <= a[i]) l = m;
			else r = m;
		}
		v1[i] += 1;
		if (r < n) {
			v1[r] -= 1;
			v2[r] += a[i] - (l >= 0 ? ps[l] : 0);
		}
	}
	for (int i{1}; i < n; ++i) v1[i] += v1[i - 1];

	for (int i{0}; i < n; ++i) cout << v1[i] * b[i] + v2[i] << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
