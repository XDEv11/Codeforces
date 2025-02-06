//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <set>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	constexpr array<int, 2> t{1, -1};

	int a, b, xk, yk, xq, yq;
	cin >> a >> b >> xk >> yk >> xq >> yq;

	set<pair<int, int>> st1{}, st2{};
	for (int i{0}; i < 2; ++i)
		for (int j{0}; j < 2; ++j)
			for (int k{0}; k < 2; ++k) {
				st1.emplace(xk - t[j] * (i ? a : b), yk - t[k] * (i ? b : a));
				st2.emplace(xq - t[j] * (i ? a : b), yq - t[k] * (i ? b : a));
			}

	int ans{};
	for (auto& e : st1) ans += st2.count(e);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
