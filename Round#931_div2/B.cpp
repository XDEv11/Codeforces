//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const array<int, 5> a{1, 3, 6, 10, 15};
const array<int, 4> ub{[] {
	array<int, 4> t;
	for (int i{0}; i + 1 < a.size(); ++i)
		for (t[i] = 1; ; ++t[i]) {
			bool f{false};
			for (int j{i + 1}; j < a.size(); ++j) {
				if ((a[i] * (t[i] + 1)) % a[j] == 0) f = true;
			}
			if (f) break;
		}
	return t;
}()};

void solve() {
	int n;
	cin >> n;

	int ans{n};
	for (array<int, 4> c{}; ; ) {
		int x{}, y{};
		for (int i{0}; i < 4; ++i) x += a[i] * c[i], y += c[i];
		if (x <= n && (n - x) % a.back() == 0) ans = min(ans, y + (n - x) / a.back());

		if (c == ub) break;
		for (int i{0}; i < 4; ++i) {
			if (c[i] < ub[i]) {
				++c[i];
				break;
			} else c[i] = 0;
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
