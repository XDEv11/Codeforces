//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> c(n);
	for (auto& x : c) cin >> x;

	vector<int> a(n), t{};
	int k{accumulate(c.begin(), c.end(), 0ll) / n};
	for (int i{n - 1}; i >= 0 && k; --i) {
		int s{(k <= t.size() ? t[t.size() - k] : n) - (i + 1)};
		if (c[i] - s == i + 1) a[i] = 1, --k;
		else a[i] = 0, t.push_back(i);
	}

	for (auto& x : a) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	cin >> t;
	while (t--) solve();
}
