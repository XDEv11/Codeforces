//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	vector<pair<int, int>> ta(n), tb(n);
	for (int i{0}; i < n; ++i) ta[i] = {a[i], i};
	for (int i{0}; i < n; ++i) tb[i] = {b[i], i};
	sort(ta.begin(), ta.end());
	sort(tb.rbegin(), tb.rend());
	sort(tb.begin(), tb.begin() + n - k);
	sort(tb.begin() + n - k, tb.end());

	for (int i{0}; i < n; ++i) b[ta[i].se] = tb[i].fi;
	int c{};
	for (int i{0}; i < n; ++i) c += a[i] > b[i];

	if (c == k) {
		cout << "YES\n";
		for (auto& x : b) cout << x << ' ';
		cout << '\n';
	} else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
