//#pragma GCC optimize ("O3")

#include <iostream>
#include <set>
#include <iterator>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		multiset<int> a{}, b{};
		for (int i{0}; i < n; ++i) {
			int x;
			cin >> x, a.insert(x);
		}
		for (int i{0}; i < m; ++i) {
			int x;
			cin >> x, b.insert(x);
		}

		while (!b.empty() && b.size() <= a.size()) {
			int x; {
				auto it{prev(b.end())};
				x = *it, b.erase(it);
			}
			auto it{a.find(x)};
			if (it == a.end()) {
				b.insert(x / 2), b.insert((x + 1) / 2);
			} else a.erase(it);
		}

		cout << (b.empty() && a.empty() ? "Yes\n" : "No\n");
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
