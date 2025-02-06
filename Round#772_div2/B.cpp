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

	int c{0};
	for (int i{1}; i + 1 < n; ++i)
		if (v[i - 1] < v[i] && v[i] > v[i + 1]) {
			if (i + 2 < n) v[i + 1] = max(v[i], v[i + 2]);
			else v[i + 1] = v[i];
			++c;
		}

	cout << c << '\n';
	for (auto& x : v) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
