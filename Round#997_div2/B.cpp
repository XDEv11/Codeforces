//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<vector<char>> adj(n, vector<char>(n));
		for (auto& v : adj)
			for (auto& x : v) cin >> x;

		list<int> ans{0};
		for (int i{1}; i < n; ++i) {
			for (auto it{ans.begin()}; ; ++it) {
				if (it == ans.end() || (i < *it && adj[i][*it] == '1') || (*it < i && adj[*it][i] == '0')) {
					ans.insert(it, i);
					break;
				}
			}
		}

		for (auto& x : ans) cout << (x + 1) << ' ';
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
