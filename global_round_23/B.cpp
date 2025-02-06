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

	int ans{0};
	int i{0}, j{n - 1};
	while (i < j) {
		while (i < j && v[i] == 0) ++i;
		while (i < j && v[j] == 1) --j;
		if (i < j) {
			++i, --j;
			++ans;
		}
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
