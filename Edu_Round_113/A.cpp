#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	for (int i{0}; i + 1 < n; ++i)
		if (v[i] != v[i + 1]) return cout << i + 1 << ' ' << i + 2 << '\n', []{}();
	cout << "-1 -1\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
