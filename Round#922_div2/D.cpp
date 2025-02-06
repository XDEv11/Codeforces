//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#define fi first
#define se second
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n + 2);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	ll l{0}, r{accumulate(v.begin(), v.end(), 0ll)};
	while (r - l > 1) {
		ll m{(l + r) / 2};

		vector<ll> dp(n + 2);
		ll s{};
		deque<pair<ll, int>> w{};
		w.emplace_back(0, 0);
		for (int i{1}, j{1}; i <= n + 1; ++i) {
			dp[i] = w.front().fi + v[i];

			s += v[i];
			while (!w.empty() && w.back().fi >= dp[i]) w.pop_back();
			w.emplace_back(dp[i], i);

			while (s > m) s -= v[j++];
			while (w.front().se < j - 1) w.pop_front();
		}

		if (dp[n + 1] <= m) r = m;
		else l = m;
	}

	cout << r << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
