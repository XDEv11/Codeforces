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

	for (int i{0}; i + 1 < n; ++i) {
		if (v[i] == 'L' && v[i + 1] == 'R') return cout << i + 1 << '\n', []{}();
		else if (v[i] == 'R' && v[i + 1] == 'L') return cout << "0\n", []{}();
	}
	cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
