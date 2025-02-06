//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	vector<long long> ps(n);
	ps[0] = v[0];
	for (int i{1}; i < n; ++i) ps[i] = ps[i - 1] + v[i];
	vector<long long> dp(n);
	dp[0] = ps[0];
	for (int i{1}; i < n; ++i) dp[i] = max(dp[i - 1], (ps[i] + i) / (i + 1));
	for (int i{0}; i < n; ++i) dp[i] = max(dp[i], (ps[n - 1] + i) / (i + 1));

	int q;
	cin >> q;
	while (q--) {
		long long t;
		cin >> t;

		if (t < dp[n - 1]) {
			cout << "-1\n";
			continue;
		}
		int l{-1}, r{n - 1};
		while (r - l > 1) {
			int m{(l + r) / 2};
			if (dp[m] <= t) r = m;
			else l = m;
		}
		cout << r + 1 << '\n';
	}
}

void solve2() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	long long s{0}, mx{0};
	for (int i{0}; i < n; ++i) {
		s += v[i];
		mx = max(mx, (s + i) / (i + 1));
	}

	int q;
	cin >> q;
	while (q--) {
		long long t;
		cin >> t;

		if (t < mx) cout << "-1\n";
		else cout << (s + t - 1) / t << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve2();
}
