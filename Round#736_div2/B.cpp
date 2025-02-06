#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	int ans{0};
	for (int i{0}; i < n; ++i)
		if (a[i] == '0') {
			if (b[i] == '1') b[i] = '0', ++ans;
		} else {
			if (i - 1 >= 0 && b[i - 1] == '1') b[i - 1] = '0', ++ans;
			else if (i + 1 < n && b[i + 1] == '1') b[i + 1] = '0', ++ans;
		}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
