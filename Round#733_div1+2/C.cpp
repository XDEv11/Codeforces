#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int sa{0}, sb{0};
	for (int i{n / 4}; i < n; ++i) sa += a[i], sb += b[i];

	int ans{0};
	int j{n / 4 - 1};
	while (sa < sb) {
		++n, ++ans;
		sa += 100;
		if (n % 4 == 0) {
			sa -= a[n / 4 - 1];
		} else {
			if (j >= 0) sb += b[j--];
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

	return 0;
}
