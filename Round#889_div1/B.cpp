//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	bitset<200000> bs{}, mask{};
	bs[0] = true, mask.set();
	for (int i{0}; i < n; ++i) {
		bs |= (bs & mask) << v[i];
		mask[i] = false;
	}

	vector<long long> ps(n);
	ps[0] = v[0];
	for (int i{1}; i < n; ++i) ps[i] = ps[i - 1] + v[i];

	long long ans{};
	for (int i{0}; i < 2 * n; ++i) {
		if (!bs[i]) continue;
		ans = max(ans, ps[min(n - 1, i)] - i);
	}

	return cout << ans << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
