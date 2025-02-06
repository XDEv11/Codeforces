//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

static void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int s{};
	for (auto& x : v) s |= x;

	array<int, 20> c{};
	auto check{[&s, &c] {
		bool f{true};
		for (int k{0}; k < 20; ++k) f = f && ((!!c[k]) == ((s >> k) & 1));
		return f;
	}};
	auto add{[&v, &c](int i) {
		for (int k{0}; k < 20; ++k) c[k] += (v[i] >> k) & 1;
	}};
	auto sub{[&v, &c](int i) {
		for (int k{0}; k < 20; ++k) c[k] -= (v[i] >> k) & 1;
	}};

	int ans{1};
	for (int i{0}, j{0}; i < n; ++i) {
		while (!check() && j < n) add(j++);
		int ii{i};
		while (!check()) add(--ii);
		ans = max(ans, j - ii);
		if (ii < i) break;
		sub(i);
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
