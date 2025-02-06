#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second

using namespace std;

namespace D {
	int n;
	vector<int> ask(int v) {
		cout << "? " << v + 1 << endl;
		vector<int> d(n);
		for (auto& x : d) cin >> x;
		return d;
	}
	void ans(const vector<pair<int, int>>& a) {
		cout << "!\n";
		for (auto& [u, v] : a) cout << u + 1 << ' ' << v + 1 << '\n';
		cout << flush;
	}
	void solve() {
		cin >> n;

		vector<int> d{ask(0)};

		vector<pair<int, int>> a{};
		int cnt{};
		for (int v{1}; v < n; ++v) cnt += (d[v] & 1);
		for (int u{0}; u < n; ++u) {
			if ((d[u] & 1) != (cnt < n - cnt)) continue;
			vector<int> d2{u ? ask(u) : d};
			for (int v{0}; v < n; ++v) {
				if (d2[v] != 1) continue;
				a.emplace_back(u, v);
			}
		}

		ans(a);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) D::solve();

	return 0;
}
