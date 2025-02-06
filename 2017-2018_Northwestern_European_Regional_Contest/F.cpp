//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

const int maxval{10000000};
vector<int> pf{[] {
	vector<int> v(maxval + 1);
	v[0] = v[1] = 1;
	using ll = long long;
	for (ll i{2}; i <= maxval; ++i) {
		if (v[i]) continue;
		v[i] = i;
		for (ll j{i * i}; j <= maxval; j += i) v[j] = i;
	}
	return v;
}()};

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<set<int>> f(n);
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		while (x > 1) f[i].insert(pf[x]), x /= pf[x];
	}

	vector<int> l(n, -1), r(n, n);
	map<int, vector<int>> mp{};
	for (int i{0}; i < n; ++i) {
		for (auto& x : f[i]) mp[x].push_back(i);
	}
	for (auto& [x, v] : mp)
		for (int i{0}; i + 1 < v.size(); ++i) {
			int j{v[i]}, k{v[i + 1]};
			l[k] = max(l[k], j);
			r[j] = min(r[j], k);
		}

	vector<int> ans(n);
	queue<array<int, 3>> qu{};
	qu.push({0, n - 1, -1});
	while (!qu.empty()) {
		auto [x, y, p]{qu.front()}; qu.pop();
		if (x == y) ans[x] = p;
		else {
			int q{-1};
			for (int i{x}, j{y}; i <= j; ++i, --j) {
				if (l[i] < x && y < r[i]) {
					q = i;
					break;
				}
				if (l[j] < x && y < r[j]) {
					q = j;
					break;
				}
			}
			if (q == -1) return cout << "impossible\n", true;
			ans[q] = p;
			if (x <= q - 1) qu.push({x, q - 1, q});
			if (q + 1 <= y) qu.push({q + 1, y, q});
		}
	}

	for (auto& x : ans) cout << x + 1 << ' ';
	cout << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
