#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

constexpr int Max = 10e6;

bool sieve[Max]; 
vector<int> primes;
void create()
{
	int sqrt_max = sqrt(Max);
	sieve[0] = sieve[1] = true;
	for (int i=2; i <= sqrt_max; i++)
		if (!sieve[i])
			for (int k = (Max - 1) / i, j = i * k; k >= i; k--, j -= i)
				if (!sieve[k])
					sieve[j] = true;
}

int f(int n) {
	for (const auto& p : primes)
		if (n % p == 0) return p;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	create();
	for (int i = 2; i < Max; i++)
	    	if (!sieve[i])
			primes.push_back(i);

	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < k; ++i) {
			n += f(n);
		}
		cout << n << endl;
	}
	return 0;
}
