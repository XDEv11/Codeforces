//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		array<int, 2> a, b;
		cin >> a[0] >> a[1] >> b[0] >> b[1];

		if (a[0] > b[0]) swap(a, b);

		int ans;
		if (a[1] < b[0]) ans = 1;
		else if (a[1] <= b[1]) {
			ans = a[1] - b[0];
			if (a[0] < b[0]) ++ans;
			if (a[1] < b[1]) ++ans;
		} else {
			ans = b[1] - b[0];
			if (a[0] < b[0]) ++ans;
			++ans;
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
