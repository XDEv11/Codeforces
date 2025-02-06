//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	int cnta{count(a.begin(), a.end(), '1')}, cntb{count(b.begin(), b.end(), '1')};
	int d{0};
	for (int i{0}; i < n; ++i)
		if (a[i] != b[i]) ++d;

	int ans{n + 1};
	if (cnta == cntb) ans = d;
	if (n - cnta + 1 == cntb) ans = min(ans, n - d);
	if (ans == n + 1) ans = -1;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
