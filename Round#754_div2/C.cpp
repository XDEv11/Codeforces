#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	for (int i{0}; i + 1 < n; ++i)
		if (v[i] == 'a' && v[i + 1] == 'a') return cout << "2\n", []{}();
	for (int i{0}; i + 2 < n; ++i)
		if (v[i] == 'a' && v[i + 2] == 'a') return cout << "3\n", []{}();
	for (int i{0}; i + 3 < n; ++i)
		if (v[i] == 'a' && v[i + 3] == 'a' && v[i + 1] != v[i + 2]) return cout << "4\n", []{}();
	for (int i{0}; i + 6 < n; ++i)
		if (v[i] == 'a' && v[i + 3] == 'a' && v[i + 6] == 'a' && v[i + 1] != v[i + 4]) return cout << "7\n", []{}();

	cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
