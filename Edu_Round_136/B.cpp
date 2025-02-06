//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> d(n);
	for (auto& x : d) cin >> x;

	vector<int> a(n);
	a[0] = d[0];
	for (int i{1}; i < n; ++i) {
		if (d[i] && a[i - 1] - d[i] >= 0) return cout <<"-1\n", []{}();
		a[i] = a[i - 1] + d[i];
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
