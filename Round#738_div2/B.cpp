#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> c(n);
	for (auto& x : c) cin >> x;
	c.push_back('B');

	int i{0};
	while (c[i] == '?') ++i;
	for (int k{i - 1}; k >= 0; --k)
		c[k] = ((c[i] == 'B' && (i - k - 1) & 1) || (c[i] == 'R' && (i - k) & 1) ? 'B' : 'R');
	while (true) {
		while (i < n && c[i] == '?') ++i;
		if (i >= n) break;
		int j{i + 1};
		while (j < n && c[j] == '?') ++j;

		for (int k{i + 1}; k < j; ++k) c[k] = ((c[i] == 'B' && (k - i - 1) & 1) || (c[i] == 'R' && (k - i) & 1) ? 'B' : 'R');
		i = j;
	}

	for (int i{0}; i < n; ++i) cout << c[i];
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
