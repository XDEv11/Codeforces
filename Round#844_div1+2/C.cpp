//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <array>
#include <utility>
#define fi first
#define se second
#include <algorithm>
#include <queue>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	array<pair<vector<int>, int>, 26> pos{};
	for (int i{0}; i < n; ++i) pos[v[i] - 'a'].fi.push_back(i);
	for (int i{0}; i < 26; ++i) pos[i].se = i;
	sort(pos.begin(), pos.end(),
		[](const pair<vector<int>, int> &a, const pair<vector<int>, int> &b) { return a.fi.size() > b.fi.size(); });

	int mn{n}, mnk;
	for (int k{1}; k <= 26; ++k) {
		if (n % k) continue;
		int d{0};
		for (int i{0}; i < 26; ++i) {
			int t{i < k ? n / k : 0};
			d += max(0, int(pos[i].fi.size()) - t);
		}
		if (d < mn) {
			mn = d;
			mnk = k;
		}
	}

	queue<int> qu{};
	for (int i{0}; i < 26; ++i) {
		int t{i < mnk ? n / mnk : 0};
		for (int j{t}; j < pos[i].fi.size(); ++j) qu.push(pos[i].fi[j]);
	}
	for (int i{0}; i < 26; ++i) {
		int t{i < mnk ? n / mnk : 0};
		while (pos[i].fi.size() < t) {
			auto j{qu.front()}; qu.pop();
			v[j] = 'a' + pos[i].se;
			pos[i].fi.push_back(j);
		}
	}

	cout << mn << '\n';
	for (auto& x : v) cout << x;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
