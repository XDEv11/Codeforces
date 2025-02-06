//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int j{n}, k{-1};
	for (int i{n - 1}; i >= 0; --i) {
		if (v[i] == 'A') j = i;
	}
	for (int i{0}; i < n; ++i) {
		if (v[i] == 'B') k = i;
	}

	if (j >= k) cout << "0\n";
	else cout << (k - j) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
