//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& e : v) cin >> e;

	vector<int> x(n, -1);
	{stack<int> stk{};
	for (int i{0}; i < n; ++i) {
		while (!stk.empty() && v[stk.top()] > v[i]) stk.pop();
		if (!stk.empty()) x[i] = stk.top();
		stk.push(i);
	}}
	vector<int> y(n, -1);
	{stack<int> stk1{}, stk2{};
	for (int i{n - 1}; i >= 0; --i) {
		while (!stk2.empty() && v[stk2.top()] < v[i]) y[stk2.top()] = i, stk2.pop();
		while (!stk1.empty() && v[stk1.top()] > v[i]) stk2.push(stk1.top()), stk1.pop();
		stk1.push(i);
	}}
	vector<int> z(n, n);
	{stack<int> stk{};
	for (int i{n - 1}; i >= 0; --i) {
		while (!stk.empty() && v[stk.top()] > v[i]) stk.pop();
		if (!stk.empty()) z[i] = stk.top();
		stk.push(i);
	}}

	using ll = long long;
	ll ans{ll(n - 1) * n * (n + 1) / 6};
	for (int i{0}; i < n; ++i) ans -= ll(x[i] - y[i]) * (z[i] - i);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
