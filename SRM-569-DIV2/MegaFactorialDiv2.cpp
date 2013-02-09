#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <bitset>
#include <list>
#include <sstream>
using namespace std;

typedef long long LL;

int primes[1000];
int prime_len;
int gash[1000];
LL ans[2][101][168];
LL b[1001][168];

int MOD = 1000000009;

class MegaFactorialDiv2
{
        public:
        int countDivisors(int N, int K)
        {
			init();
			memset(b , 0 , sizeof(b));
			memset(ans , 0 , sizeof(ans));
			for (int i=2 ; i<=N ; i++) {
				int temp = i;
				for (int j=0 ; j<prime_len ; j++) {
					if (temp % primes[j] == 0) {
						int cnt = 0;
						while (temp % primes[j] == 0) {
							cnt++;
							temp /= primes[j];
						}
						b[i][gash[primes[j]]] = cnt;
						if (temp == 1) break;
					}
				}
			}

			int u = 0;
			int p = 1;
			
			for (int i=1 ; i<=N ; i++) {
				for (int k=0 ; k<prime_len ; k++) {
					ans[u][1][k] = ans[p][1][k] + b[i][k];
					if (ans[u][1][k] >= MOD)
						ans[u][1][k] %= MOD;
				}
				for (int j=2 ; j<=K ; j++) {
					for (int k=0 ; k<prime_len ; k++) {
						ans[u][j][k] = ans[p][j][k] + ans[u][j - 1][k];
						if (ans[u][j][k] >= MOD)
							ans[u][j][k] %= MOD;
					}
				}

				p = 1 - p;
				u = 1 - u;
			}

			LL result = 1;
			for (int i=0 ; i<prime_len ; i++) {
				result = result * (ans[p][K][i] + 1);
				if (result >= MOD)
					result %= MOD;
			}

			return ((int)result);
		}

		void init() {
			primes[0] = 2;
			prime_len = 1;
			gash[2] = 0;
			for (int i=3 ; i<=1000 ; i++) {
				bool find = false;

				for (int j=0 ; j<prime_len ; j++) {
					if (i % primes[j] == 0) {
						find = true;
						break;
					}
				}

				if (!find) {
					gash[i] = prime_len;
					primes[prime_len++] = i;
				}
			}

			
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 4; verify_case(0, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 6; verify_case(1, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 18; verify_case(2, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 1392; verify_case(3, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 2; int Arg2 = 321266186; verify_case(4, Arg2, countDivisors(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        MegaFactorialDiv2 ___test;
        ___test.run_test(-1);
       getchar();
        return 0;
}
// END CUT HERE
