//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int maxn{200000};
const int mod{1000000007};
const vector<long long> tb{[]() {
	vector<long long> tb(maxn + 1, 0);
	tb[0] = 1, tb[1] = 1;
	for (int i{2}; i <= maxn; ++i) tb[i] = (tb[i - 1] + tb[i - 2]) % mod;
	for (int i{1}; i <= maxn; ++i) tb[i] = (tb[i] + tb[i - 1]) % mod;
	return tb;
}()};

void solve() {
	int n, p;
	cin >> n >> p;
	set<int> s{};
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		s.insert(x);
	}

	vector<int> v{};
	for (auto& x : s) {
		auto t{x};
		bool f{false};
		while (true) {
			if (t & 1) t /= 2;
			else if ((t / 2) & 1) break;
			else t /= 4;
			if (!t) break;
			if (s.count(t)) {
				f = true;
				break;
			}
		}
		if (!f) v.push_back(x);
	}

	long long ans{0};
	for (auto& x : v) {
		int b{p - (32 - __builtin_clz(x))};
		if (b < 0) continue;

		ans = (ans + tb[b]) % mod;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
