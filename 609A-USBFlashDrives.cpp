/*
	SubmissionId	:	14900115
	ContestId	:	609
	Index	:	A
	ProblemName	:	USB Flash Drives
	ProblemTags	:	['greedy', 'implementation', 'sortings']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std ;


int main(){
	int n , m ;
	cin >> n >> m ;
	vector < int > vec ;
	for(int i = 0 ;i < n ; i ++){
		int a ;
		cin >>a ;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end(), greater<int>());
	int now = 0 ;
	while(m > 0){
		m -= vec[now] ;
		now ++ ;
	}
	cout << now << endl ;
	return 0 ;
}
