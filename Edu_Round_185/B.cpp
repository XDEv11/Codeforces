//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		priority_queue<int> pq{};
		for (auto& x : v) {
			if (x) pq.push(x);
		}

		for (int _{0}; _ < n - 1; ++_) {
			auto x{pq.top()}; pq.pop();
			if (--x) pq.push(x);
		}

		cout << pq.size() << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
