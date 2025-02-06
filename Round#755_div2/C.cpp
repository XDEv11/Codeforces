#include <iostream>
#include <array>

using namespace std;

void solve() {
	int n;
	cin >> n;
	array<int, 201> cnta, cntb; cnta.fill(0), cntb.fill(0);
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		++cnta[x + 100];
	}
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		++cntb[x + 100];
	}

	bool ans{true};
	for (int i{0}; i <= 200; ++i) {
		if (i != 0) {
			if (cnta[i - 1] > cntb[i]) {
				ans = false;
				break;
			} else cntb[i] -= cnta[i - 1];
		}

		if (cnta[i] >= cntb[i]) cnta[i] -= cntb[i];
		else {
			ans = false;
			break;
		}
	}

	cout << (ans ? "YES\n"s : "NO\n"s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
