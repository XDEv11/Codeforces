//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

static char Ask(int i) {
	cout << "? " << i + 1 << endl;
	char r;
	return cin >> r, r;
}

static void Ans(const vector<int>& v) {
	cout << "! ";
	for (auto& x : v) cout << x << ' ';
	cout << endl;
}

void solve() {
	int n;
	cin >> n;

	vector<int> ans(n);

	int i1{0}; // 3n
	while (Ask(i1) != '=') ;
	for (int i{1}; i < n; ++i) {
		if (Ask(i) == '<') {
			i1 = i;
			while (Ask(i1) != '=') ;
		} else Ask(i1);
	}

	int in{0}; // 3n
	while (Ask(in) != '=') ;
	for (int i{1}; i < n; ++i) {
		if (Ask(i) == '>') {
			in = i;
			while (Ask(in) != '=') ;
		} else Ask(in);
	}
	int x{n};

	vector<tuple<int, int, vector<int>>> v{};
	{
		vector<int> t(n); iota(t.begin(), t.end(), 0);
		v.emplace_back(1, n, t);
	}

	bool f{false};
	while (!v.empty()) { // 11 * (n + 2n)
		vector<tuple<int, int, vector<int>>> t{};
		for (auto& [l, r, idx] : v) {
			if (l < r) {
				int m{(l + r) / 2};
				while (x < m) Ask(in), ++x;
				while (x > m) Ask(i1), --x;
				vector<int> lt{}, gt{};
				for (auto& i : idx) {
					switch (Ask(i)) {
						break; case '=': ans[i] = m;
						break; case '<': Ask(in), lt.push_back(i);
						break; case '>': Ask(i1), gt.push_back(i);
					}
				}
				if (!f && !lt.empty()) t.emplace_back(l, m - 1, lt);
				if (!gt.empty()) t.emplace_back(m + 1, r, gt);
				if (f && !lt.empty()) t.emplace_back(l, m - 1, lt);
			} else {
				for (auto& i : idx) ans[i] = l;
			}
		}
		v = t;
		reverse(v.begin(), v.end()), f = !f;
	}

	Ans(ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
