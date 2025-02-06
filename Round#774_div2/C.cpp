//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	long long n;
	cin >> n;

	vector<long long> f{};
	long long x{2};
	for (int i{3}; x * i <= n; ++i) {
		x *= i;
		f.push_back(x);
	}

	int ans{__builtin_popcountll(n)};
	for (int i{1}; i < (1 << f.size()); ++i) {
		long long s{0};
		for (int j{0}; j < f.size(); ++j)
			if (i & (1 << j)) s += f[j];
		if (s <= n) ans = min(ans, __builtin_popcount(i) + __builtin_popcountll(n - s));
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
