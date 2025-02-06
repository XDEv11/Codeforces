//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <cassert>

using namespace std;

int digital_logarithm(int x) {
	int res{0};
	while (x) ++res, x /= 10;
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	multiset<int> msa{};
	for (auto& x : a) msa.insert(x);
	vector<int> tb{};
	for (auto& x : b) {
		auto it{msa.find(x)};
		if (it != msa.end()) msa.erase(it), --n;
		else tb.push_back(x);
	}
	a.assign(msa.begin(), msa.end());
	b = move(tb);

	assert(a.size() == n && a.size() == b.size());

	int ans{0};
	array<int, 10> cnta{}, cntb{};
	for (auto& x : a) {
		if (x >= 10) ++ans, ++cnta[digital_logarithm(x)];
		else ++cnta[x];
	}
	for (auto& x : b) {
		if (x >= 10) ++ans, ++cntb[digital_logarithm(x)];
		else ++cntb[x];
	}

	for (int i{9}; i >= 2; --i) {
		if (cnta[i] > cntb[i]) {
			ans += cnta[i] - cntb[i];
			cnta[digital_logarithm(i)] += cnta[i] - cntb[i];
		} else {
			ans += cntb[i] - cnta[i];
			cntb[digital_logarithm(i)] += cntb[i] - cnta[i];
		}
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
