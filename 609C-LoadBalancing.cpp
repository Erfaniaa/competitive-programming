/*
	SubmissionId	:	14900581
	ContestId	:	609
	Index	:	C
	ProblemName	:	Load Balancing
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std ;

int main(){
	int n ;
	int tot= 0 ;
	cin >> n ;
	vector < int > vec ;
	for(int i = 0 ;i < n ; i++){
		int a ;
		cin >>a ;
		vec.push_back(a);
		tot += a ;
	}
	int good = 1 ;
	int av = tot/n ;
	if(tot %n){
		good = 0 ;
	}
	int tm1 = 0 , tm2= 0 ;
	int tmx = 0 ;
	for(auto it : vec){
		if(good){
			tmx += abs(it - av);
		}
		else{
			if(it > av){
				tm1+= abs((av + 1) - it);
			}
			else{
				tm2+= abs(av - it);
			}
		}
	}
	int out = max(tm1 , tm2);
	if(good)
		out= tmx/2 ;
	cout << out << endl ;
	return 0 ;
}
