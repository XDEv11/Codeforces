#include <iostream>
#include <vector>

using namespace std;

static constexpr long long P{998244353};

static constexpr int MAXN{1000000};
static vector<int> nf(MAXN + 1, 1); // number of factors
static void build() {
	for (int i{2}; i <= MAXN; ++i) {
		for (int j{i}; j <= MAXN; j += i) nf[j] += 1;
	}
}

void solve() {
	int n;
	cin >> n;

	vector<long long> dp(n + 1);
	dp[0] = 1;
	long long ps{1}; // prefix sum
	for (int i{1}; i <= n; ++i) {
		dp[i] = (ps + nf[i] - 1) % P;
		ps = (ps + dp[i]) % P;
	}

	cout << dp[n] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	build();

	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
