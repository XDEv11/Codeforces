//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	for (auto& x : v) cin >> x, --x;

	vector<int> cnt(n);
	for (auto& x : v) ++cnt[x];

	int l{0}, r{(m + n - 1) / n * 2};
	while (r - l > 1) {
		int t{(l + r) / 2};
		int s{0};
		for (auto& x : cnt) {
			if (x > t) s += 2 * (x - t);
			else s -= (t - x) / 2 * 2;
		}
		if (s > 0) l = t;
		else r = t;
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
