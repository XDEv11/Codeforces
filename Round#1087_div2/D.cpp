//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	const array<char, 3> ch{'R', 'G', 'B'};
	void solve() {
		array<int, 3> a;
		for (auto& x : a) cin >> x;

		vector<int> ans{};
		array<array<int, 2>, 3> t;
		for (int i{0}; i < 3; ++i) t[i] = {a[i], i};
		sort(t.rbegin(), t.rend());
		auto put{[&](int i) { ans.push_back(t[i][1]), --t[i][0]; }};

		while (t[1][0] > t[2][0]) put(0), put(1);
		while (t[1][0] && t[0][0] > t[1][0]) put(0), put(2), put(0), put(1);
		for (int k{0}; t[1][0]; ++k) put(k % 3), put((k + 1) % 3), put((k + 2) % 3);
		if (t[0][0] && (ans.empty() || ans.back() != t[0][1])) put(0);

		for (auto& x : ans) cout << ch[x];
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
