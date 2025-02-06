//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<long long> v(n);
	for (auto& e : v) cin >> e;

	sort(v.begin(), v.end());

	int ans{0};
	multimap<long long, int> mmp{};
	for (int i{0}; i < n; ++i) mmp.emplace(v[i], i);
	vector<bool> f(n, false);
	for (int i{0}; i < n; ++i) {
		if (f[i]) continue;
		auto it{mmp.find(v[i] * x)};
		if (it != mmp.end()) f[it->second] = true, mmp.erase(it);
		else ++ans;
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
