//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>

using namespace std;

const int maxn{10000000};
vector<int> pf{[](){
	vector<int> _pf(maxn + 1);
	for (long long i{2}; i <= maxn; ++i) {
		if (_pf[i]) continue;
		_pf[i] = i;
		for (long long j{i * i}; j <= maxn; j += i) _pf[j] = i;
	}
	return _pf;
}()};

void solve() {
	int x, y;
	cin >> x >> y;

	int ans{numeric_limits<int>::max()};
	int z{y - x};
	if (z == 1) return cout << "-1\n", []{}();
	while (z != 1) {
		int p{pf[z]};
		do {
			z /= p;
		} while (z % p == 0);
		ans = min(ans, ((x + p - 1) / p) * p - x);
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
