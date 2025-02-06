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

	cout << n - 1 << '\n';
	if (n > 1) cout << "1 " << n << '\n';
	for (int i{1}; i < n - 1; ++i) {
		if ((v[i] + v[0]) & 1) cout << "1 " << i + 1 << '\n';
		else cout << i + 1 << ' ' << n << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
