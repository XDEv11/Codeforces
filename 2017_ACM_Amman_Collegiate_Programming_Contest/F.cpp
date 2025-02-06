#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#define fi first
#define se second
#include <set>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> nxt(n);
	map<int, int> mp{};
	for (int i{n - 1}; i >= 0; --i) {
		nxt[i] = mp[v[i]];
		if (nxt[i] == 0) nxt[i] = n;
		mp[v[i]] = i;
	}

	int ans{};
	priority_queue<pair<int, int>> pq{};
	set<int> st{};
	for (int i{0}; i < n; ++i) {
		if (!st.count(v[i])) {
			while (st.size() == k) {
				auto [t, x]{pq.top()}; pq.pop();
				st.erase(x);
			}
			++ans, st.insert(v[i]);
		}
		pq.emplace(nxt[i], v[i]);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	cin >> t;
	while (t--) solve();
}
