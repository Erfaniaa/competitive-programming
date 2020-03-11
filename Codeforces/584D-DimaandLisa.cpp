/*
	SubmissionId	:	13477443
	ContestId	:	584
	Index	:	D
	ProblemName	:	Dima and Lisa
	ProblemTags	:	['number theory']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std ;

#define sz(x) ((int)(x).size())
typedef long long ll ;

int isprime(int a){
	if(a == 0){
		return 1 ;
	}

	if(a == 2)
		return 1 ;
	for(ll now = 2 ; now *now <= a ; now ++ ){
		if(a %now == 0){
			return 0;
		}
	}
	return 1 ;
}

int main(){
	int n ;
	cin >> n ;
	if(isprime(n)){
		cout <<1 << endl << n << endl ;
	}
	else if(isprime(n - 2)){
		cout << 2 << endl ;
		cout << 2 << " " << n - 2 <<endl ;
	}
	else if(isprime(n - 4)){
		cout << 3 << endl ;
		cout << 2 << " " << 2 << " " << n - 4 << endl ;

	}
	else{
		for(int i = n ; i >= 0 ; i -= 2 ){
			if(isprime(i)){
				cout << 3 << endl ;
				cout << i << " " ;
				for(int j = 2 ;j <= n - i ; j ++){
					if(isprime(j) && isprime(n - i - j)){
						cout << j  << " " << n - i - j << endl ;
						return 0 ;
					}
				}
				break;
			}
		}
	}

	return 0 ;
}                                                                                                                                                                    