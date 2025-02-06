//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int m, q;
	cin >> m >> q;
	vector<int> v(m);
	for (auto& x : v) cin >> x, --x;

	while (q--) {
		int n;
		cin >> n;

		while (v[0] < n) {
			int c{};
			for (auto& x : v) c += x < n;
			n -= c;
		}

		cout << n << ' ';
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
