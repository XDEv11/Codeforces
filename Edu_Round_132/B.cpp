//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<long long> d1(n), d2(n);
	for (int i{1}; i < n; ++i) d1[i] = d1[i - 1] + max(0, v[i - 1] - v[i]);
	for (int i{n - 2}; i >= 0; --i) d2[i] = d2[i + 1] + max(0, v[i + 1] - v[i]);

	while (m--) {
		int s, t;
		cin >> s >> t, --s, --t;
		if (s < t) cout << d1[t] - d1[s] << '\n';
		else cout << d2[t] - d2[s] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
