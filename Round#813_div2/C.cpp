//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> fi(n + 1, -1), la(n + 1, -1);
	for (int i{n - 1}; i >= 0; --i) fi[v[i]] = i;
	for (int i{0}; i < n; ++i) la[v[i]] = i;
	vector<int> mx(n + 1);
	mx[0] = -1;
	for (int i{1}; i <= n; ++i) mx[i] = max(mx[i - 1], la[i]);

	int ans{0};
	int mx2{-1};
	for (int i{n}; i >= 1; --i) {
		if (fi[i] == -1) continue;
		if (fi[i] < max(mx[i - 1], mx2)) {
			ans += 1;
			mx2 = max(mx2, la[i]);
		}
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
