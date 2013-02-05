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

int ans[100][8];

int min(int a , int b) {
	return a > b ? b : a;
}

class BallsSeparating
{
        public:
        int minOperations(vector <int> red, vector <int> green, vector <int> blue)
        {
			memset(ans , -1 , sizeof(ans));
			ans[0][1] = green[0] + blue[0];
			ans[0][2] = red[0] + blue[0];
			ans[0][4] = red[0] + green[0];

			for (int i=1 ; i<red.size() ; i++) {
				for (int j=0 ; j<8 ; j++) {
					if (ans[i - 1][j] != -1) {
						if (ans[i][1 | j] == -1)
							ans[i][1 | j] = ans[i - 1][j] + green[i] + blue[i];
						else
							ans[i][1 | j] = min(ans[i][1 | j] , ans[i - 1][j] + green[i] + blue[i]);
					
						if (ans[i][2 | j] == -1)
							ans[i][2 | j] = ans[i - 1][j] + red[i] + blue[i];
						else
							ans[i][2 | j] = min(ans[i][2 | j] , ans[i - 1][j] + red[i] + blue[i]);

						if (ans[i][4 | j] == -1)
							ans[i][4 | j] = ans[i - 1][j] + red[i] + green[i];
						else
							ans[i][4 | j] = min(ans[i][4 | j] , ans[i - 1][j] + red[i] + green[i]);
					}
				}
			}

			return ans[red.size() - 1][7];
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(0, Arg3, minOperations(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(1, Arg3, minOperations(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {4, 6, 5, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 4, 6, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6, 5, 3, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 37; verify_case(2, Arg3, minOperations(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {7, 12, 9, 9, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 10, 8, 8, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8, 9, 5, 6, 13}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 77; verify_case(3, Arg3, minOperations(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {842398, 491273, 958925, 849859, 771363, 67803, 184892, 391907, 256150, 75799}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {268944, 342402, 894352, 228640, 903885, 908656, 414271, 292588, 852057, 889141}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {662939, 340220, 600081, 390298, 376707, 372199, 435097, 40266, 145590, 505103}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7230607; verify_case(4, Arg3, minOperations(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        BallsSeparating ___test;
        ___test.run_test(-1);
       getchar();
        return 0;
}
// END CUT HERE
