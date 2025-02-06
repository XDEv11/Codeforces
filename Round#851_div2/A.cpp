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

	int c{0};
	for (auto& x : v) c += (x == 2);
	if (c == 0) return cout << "1\n", []{}();
	if (c & 1) return cout << "-1\n", []{}();

	int ch{0};
	for (int i{0}; i < n; ++i) {
		ch += (v[i] == 2);
		if (ch == c / 2) return cout << i + 1 << '\n', []{}();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
