//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <deque>
#include <numeric>
#include <iterator>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n; ll k;
		cin >> n >> k;
		vector<ll> a(n), b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;
		if (accumulate(a.begin(), a.end(), 0ll) <= k) return cout << "0\n", []{}();

		vector<ll> d(2 * n);
		for (int i{0}; i < n; ++i) d[i] = d[n + i] = a[i] - b[i];
		for (int i{1}; i < n * 2; ++i) d[i] += d[i - 1];

		//int p{distance(d.begin(), min_element(d.begin() + n, d.end()))};

		int l{0}, r{n};
		while (r - l > 1) {
			int m{(l + r) / 2};
			deque<int> dq{};
			ll c{};
			for (int i{n * 2 - 1}; i >= 1; --i) {
				while (!dq.empty() && dq.front() - (i - 1) > m) dq.pop_front();
				while (!dq.empty() && d[dq.back()] >= d[i]) dq.pop_back();
				dq.push_back(i);
				if (i <= n) c += max(0ll, d[dq.front()] - d[i - 1]);
			}
			(c <= k ? r : l) = m;
		}

		cout << r << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
