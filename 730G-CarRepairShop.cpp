/*
	SubmissionId	:	21892883
	ContestId	:	730
	Index	:	G
	ProblemName	:	Car Repair Shop
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > scheduled;

int goodFrom(int start, int dur) {
	for(auto& it : scheduled) {
		if(!(it.second < start || start + dur - 1 < it.first)) {
			return 0;
		}
	}
	return 1;
}

int getFirstGood(int dur) {
	int ret = 1231231231;
	for(auto& it: scheduled) {
		int tr = it.second + 1;
		if(goodFrom(tr, dur)) {
			ret = min(ret, tr);
		}
	}
	return ret;
}

int main(){
	scheduled.push_back(make_pair(0, 0));
	int n;
	cin>>n ;
	for(int i = 0 ;i < n ; i++) {
		int start, dur;
		cin >> start >> dur;
		if(goodFrom(start, dur)) {
			scheduled.push_back(make_pair(start, start + dur -1));
		} else {
			int fir = getFirstGood(dur);
			scheduled.push_back(make_pair(fir, fir + dur -1));
		}
	}
	for(auto& it: scheduled) {
		if(it.first != 0) {
			cout << it.first << " " << it.second << endl;
		}
	}
	return 0;
}
