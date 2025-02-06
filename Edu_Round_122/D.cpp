//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <array>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int maxb{1000};
const vector<int> f{[]() {
	vector<int> f(maxb + 1, maxb);
	f[1] = 0;
	for (int i{1}; i < maxb; ++i) {
		for (int j{1}; j <= i / 2; ++j)
			if (i + i / j <= maxb) f[i + i / j] = min(f[i + i / j], f[i] + 1);
		f[i + 1] = min(f[i + 1], f[i] + 1);
	}
	return f;
}()};

const array<int, 10> a{[]() {
	array<int, 10> a; a.fill(10);
	a[0] = 0;
	cout << "a[0]=" << a[0] << endl; //
	return a;
}()};

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> b(n), c(n);
	for (auto& x : b) cin >> x, x = f[x];
	for (auto& x : c) cin >> x;

	if (k >= accumulate(b.begin(), b.end(), 0)) return cout << accumulate(c.begin(), c.end(), 0) << '\n', []{}();

	vector<int> dp(k + 1, 0);
	for (int i{0}; i < n; ++i)
		for (int j{k}; j >= b[i]; --j) dp[j] = max(dp[j], c[i] + dp[j - b[i]]);
 
	cout << dp[k] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
