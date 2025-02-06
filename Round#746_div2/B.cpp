#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (auto& e : v) cin >> e;

	auto s{v};
	sort(s.begin(), s.end());

	int k{n};
	for (int i{0}; i < n; ++i)
		if (v[i] != s[i]) k = min(k, max(i, n - 1 - i));

	cout << (k >= x ? "YES\n"s : "NO\n"s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
