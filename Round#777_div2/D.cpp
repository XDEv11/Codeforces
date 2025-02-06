//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#define fi first
#define se second

using namespace std;

void solve() {
	int x, d;
	cin >> x >> d;

	vector<int> b{};
	auto ck = [&d](int a) {
		return a % d == 0 && a / d % d != 0;
	};
	for (int i{2}; i * i <= x; ++i) {
		if (ck(i)) b.push_back(i);
		if (i * i != x && ck(x / i)) b.push_back(x / i);
	}

	int ans{0};
	map<pair<int, int>, int> dp{};
	dp[{x, 1}] = 1;
	while (!dp.empty()) {
		auto s{prev(dp.end())};
		if (s->fi.fi == 1) ans += s->se;
		for (auto& a : b) {
			if (s->fi.fi % a == 0 && a >= s->fi.se)
				dp[{s->fi.fi / a, a}] += s->se;
		}
		dp.erase(s);
	}
	cout << (ans >= 2 ? "YES\n" : "NO\n");
}

const vector<int>
void solve2() {
	int x, d;
	cin >> x >> d;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve2();
}
