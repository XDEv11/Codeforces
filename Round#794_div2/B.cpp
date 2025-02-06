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

	int ans{0}, i{0}, j{1};
	while (j < n) {
		while (j < n && v[j - 1] < v[j]) ++j;
		if (j == n) break;
		++ans;
		i = j + 1, j = i + 1;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
