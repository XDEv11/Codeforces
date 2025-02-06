//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> v(n);
	if (n & 1) {
		v[0] = n / 2;
		for (int i{1}; i < n; ++i) v[i] = i & 1 ? ((i - 1) / 2) : (n / 2 + 1 + (i - 1) / 2);
	} else {
		for (int i{0}; i < n; ++i) v[i] = i & 1 ? (i / 2) : (n / 2 + i / 2);
	}

	for (auto& x : v) cout << x + 1 << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
