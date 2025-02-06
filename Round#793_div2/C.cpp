//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());
	int ans{0};
	int mx1{numeric_limits<int>::max()}, mx2{mx1};
	int j{n - 1};
	while (j - 1 >= 0 && v[j] == v[j - 1]) {
		mx1 = mx2 = v[j];
		j = j - 2;
		while (j >= 0 && v[j] == mx1) --j;
		++ans;
	}
	if (j >= 0) {
		++ans;
		mx1 = mx2 = v[j--];
	}
	while (true) {
		while (j >= 0 && v[j] == mx1) --j;
		if (j < 0) break;
		mx1 = v[j--];
		while (j >= 0 && v[j] == mx2) --j;
		if (j < 0) break;
		mx2 = v[j--];
		++ans;
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
