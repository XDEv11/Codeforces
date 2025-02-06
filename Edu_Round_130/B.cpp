//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	sort(v.rbegin(), v.rend());
	vector<long long> ps(n + 1);
	for (int i{0}; i < n; ++i) ps[i + 1] = ps[i] + v[i];

	while (q--) {
		int x, y;
		cin >> x >> y;

		cout << ps[x] - ps[x - y] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
