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

double ans[100];
int card[100];
int a[100];

int cmp(const void *a , const void *b) {
	int *c = (int *)a;
	int *d = (int *)b;
	return *d - *c;
}

class ShuffleSort	
{
        public:
        double shuffle(vector <int> cards)
        {
			int len = cards.size();
			for (int i=0 ; i<len ; i++) {
				card[i] = cards[i];
			}
			qsort(card , len , sizeof(card[0]) , cmp);
			a[0] = 1;
			for (int i=1 ; i<len ; i++) {
				if (card[i] == card[i - 1])
					a[i] = a[i - 1] + 1;
				else
					a[i] = 1;
			}

			ans[0] = 1.0;
			for (int i=1 ; i<len ; i++) {
				ans[i] = (i + 1) * 1.0 / a[i] + (i - a[i - 1]) * 1.0 / i * ans[i - 1] + a[i - 1] * 1.0 / i * (ans[i - 1] - (i) * 1.0 / (a[i - 1]));
			}

			return ans[len - 1];
		}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(0, Arg1, shuffle(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.0; verify_case(1, Arg1, shuffle(Arg0)); }
	void test_case_2() { int Arr0[] = {2,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.0; verify_case(2, Arg1, shuffle(Arg0)); }
	void test_case_3() { int Arr0[] = {15,16,4,8,42,23}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 16.0; verify_case(3, Arg1, shuffle(Arg0)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(4, Arg1, shuffle(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        ShuffleSort ___test;
        ___test.run_test(-1);
       getchar();
        return 0;
}
// END CUT HERE
