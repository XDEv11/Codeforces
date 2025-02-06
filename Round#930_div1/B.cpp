//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	deque<int> dql{}, dqr{};
	for (int i{0}; i < n; ++i) {
		if (v[i] == '<') dqr.push_back(i);
	}

	vector<ll> ans(n);
	ll c{};
	for (int i{0}; i < n; ++i) {
		if (v[i] == '<') { // dqr[0] == i
			if (dql.size() < dqr.size()) c += dqr[dql.size()] - i;
			else c -= i - dql[dqr.size() - 1];
			dqr.pop_front();
		}

		ans[i] = 2 * c;
		if (v[i] == '>') {
			if (dqr.size() <= dql.size()) ans[i] += n - i;
			else ans[i] += 2 * (dqr[dql.size()] - i) + (i + 1);
		} else if (v[i] == '<') {
			if (dql.size() <= dqr.size()) ans[i] += i + 1;
			else ans[i] += 2 * (i - dql[dqr.size()]) + (n - i);
		}

		if (v[i] == '>') {
			dql.push_front(i);
			if (dql.size() <= dqr.size()) c += dqr[dql.size() - 1] - i;
			else c -= i - dql[dqr.size()];
		}
	}

	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
