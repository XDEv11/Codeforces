//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	int l{n};
	while ((l + 1) * l / 2 > k) --l;
	for (int i{0}; i < n; ++i) {
		if (i < l) cout << "2 ";
		else if (i == l) {
			k -= (l + 1) * l / 2;
			cout << -((l - k + 1) * 2 - 1) << ' ';
		} else cout << "-1000 ";
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
