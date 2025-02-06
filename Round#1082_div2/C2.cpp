//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		vector<int> a(n);
		long long ans{}, s{};
		for (int i{0}; i < n; ) {
			int j{i + 1};
			while (j < n && clamp(v[j], v[i] + 1, v[j - 1] + 1) == v[j]) ++j;
			for (int k{i}; k < j; ++k) a[k] = j;
			s += (n - i);
			i = j;
		}

		vector<int> nxt(n);
		map<int, int> mp{};
		for (int i{n - 1}; i >= 0; --i) {
			nxt[i] = mp[v[i]];
			if (!nxt[i]) nxt[i] = n;
			mp[v[i]] = i;
		}

		for (int i{0}; i < n; ++i) {
			ans += s;

			int j{i + 1};
			while (j < a[i]) {
				if (nxt[j] < a[i]) {
					for (int k{j}; k < nxt[j]; ++k) a[k] = nxt[j];
					s += (n - nxt[j]);
				}
				j = nxt[j];
			}
			s -= (a[i] == i + 1 ? (n - i) : 1);
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
