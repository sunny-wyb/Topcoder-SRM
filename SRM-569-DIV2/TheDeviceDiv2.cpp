//#include <iostream>
//#include <cstdlib>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
//#include <vector>
//#include <string>
//#include <map>
//#include <set>
//#include <queue>
//#include <stack>
//#include <fstream>
//#include <bitset>
//#include <list>
//#include <sstream>
//using namespace std;
//
//typedef long long LL;
//
//class TheDeviceDiv2
//{
//        public:
//        string identify(vector <string> plates)
//        {
//			bool ans = true;
//            int a[2];
//			int len = plates[0].length();
//			for (int j=0 ; j<len ; j++) {
//				a[0] = 0;
//				a[1] = 0;
//				for (int i=0 ; i<plates.size() ; i++) {
//					a[plates[i][j] - '0']++;
//				}
//				if (a[0] >= 1 && a[1] >= 2) {
//					continue;
//				}
//				else {
//					ans = false;
//					break;
//				}
//			}
//
//			if (ans) return "YES";
//			else return "NO";
//		}
//        
//// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arr0[] = {"010",
// "011",
// "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(0, Arg1, identify(Arg0)); }
//	void test_case_1() { string Arr0[] = {"1",
// "0",
// "1",
// "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, identify(Arg0)); }
//	void test_case_2() { string Arr0[] = {"11111"}
//; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(2, Arg1, identify(Arg0)); }
//	void test_case_3() { string Arr0[] = {"0110011",
// "0101001",
// "1111010",
// "1010010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, identify(Arg0)); }
//	void test_case_4() { string Arr0[] = {"101001011",
// "011011010",
// "010110010",
// "111010100",
// "111111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(4, Arg1, identify(Arg0)); }
//
//// END CUT HERE
//
//};
//// BEGIN CUT HERE
//int main()
//{
//        TheDeviceDiv2 ___test;
//        ___test.run_test(-1);
//       getchar();
//        return 0;
//}
//// END CUT HERE
