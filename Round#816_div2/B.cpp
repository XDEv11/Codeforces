//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
	long long n, k, b, s;
	cin >> n >> k >> b >> s;

	long long mx{s / k}, mn{max(0LL, (s - (n - 1) * (k - 1)) / k)};
	if (!(mn <= b && b <= mx)) return cout << "-1\n", []{}();

	long long fi{min(s, b * k + k - 1)};
	s -= fi;
	cout << fi << ' ';
	for (int i{1}; i < n; ++i) {
		long long ne{min(s, k - 1)};
		cout << ne << ' ';
		s -= ne;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
