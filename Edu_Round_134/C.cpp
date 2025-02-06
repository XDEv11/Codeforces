//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& e : a) cin >> e;
	for (auto& e : b) cin >> e;

	for (int i{0}; i < n; ++i) cout << *lower_bound(b.begin(), b.end(), a[i]) - a[i] << ' ';
	cout << '\n';

	vector<int> mx(n);
	int x{b[n - 1]};
	for (int i{n - 1}; ; --i) {
		mx[i] = x - a[i];
		if (i <= 0) break;
		if (a[i] > b[i - 1]) x = b[i - 1];
	}
	for (auto& e : mx) cout << e << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
