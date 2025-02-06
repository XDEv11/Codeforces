//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> a(n + 2), b(n + 2);
		for (int i{1}; i <= n; ++i) cin >> a[i];
		for (int i{1}; i <= n; ++i) cin >> b[i];

		vector<int> pmn(n + 2, n * 2 + 1), pmx(n + 2), smn(n + 2, n * 2 + 1), smx(n + 2);
		for (int i{1}; i <= n; ++i) pmn[i] = min(pmn[i - 1], a[i]), pmx[i] = max(pmx[i - 1], a[i]);
		for (int i{n}; i >= 1; --i) smn[i] = min(smn[i + 1], b[i]), smx[i] = max(smx[i + 1], b[i]);

		vector<int> t(n * 2 + 1, 2 * n + 1);
		auto minimize{[](int& a, int b) { a = min(a, b); }};
		for (int i{1}; i <= n; ++i) minimize(t[min(pmn[i], smn[i])], max(pmx[i], smx[i]));
		for (int i{n * 2 - 1}; i >= 1; --i) minimize(t[i], t[i + 1]);

		long long ans{};
		for (int i{1}; i <= n * 2; ++i) ans += (n * 2 + 1 - t[i]);

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
