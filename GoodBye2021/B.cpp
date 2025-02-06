//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	if (n >= 2 && v[0] == v[1]) return cout << v[0] << v[0] << '\n', []{}();

	int c{1}, p{n - 1};
	for (int i{1}; i < n; ++i) {
		v[i] != v[i - 1] ? (c = 1) : (++c);
		if (v[i] > v[i - 1]) {
			p = i - (c + 1) / 2;
			break;
		}
	}

	for (int i{0}; i <= p; ++i) cout << v[i];
	for (int i{p}; i >= 0; --i) cout << v[i];
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
