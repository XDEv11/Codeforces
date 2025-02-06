//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	bool ck{false};
	for (int i{1}; i < n - 1; ++i) ck = ck || (v[i] >= 2);
	if (!ck || (n == 3 && v[1] & 1)) return cout << "-1\n", []{}();

	long long ans{0};
	for (int i{1}; i < n - 1; ++i) ans += (v[i] + 1) / 2;
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
