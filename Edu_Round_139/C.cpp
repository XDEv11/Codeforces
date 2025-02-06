//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second

using namespace std;

void solve() {
	using pcc = pair<char, char>;

	int n;
	cin >> n;
	vector<pcc> v(n);
	for (auto& [x, y] : v) cin >> x;
	for (auto& [x, y] : v) cin >> y;

	int last{0}, len;
	for (int i{0}; i < n; ++i) {
		if (v[i] == pcc{'B', 'B'}) ++len;
		else {
			int curr;
			if (v[i] == pcc{'B', 'W'}) curr = 1;
			else if (v[i] == pcc{'W', 'B'}) curr = 2;
			if (last) {
				if ((len & 1) == (last == curr)) return cout << "NO\n", []{}();
			}
			last = curr;
			len = 0;
		}
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
