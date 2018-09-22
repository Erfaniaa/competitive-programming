/*
	SubmissionId	:	14909732
	ContestId	:	603
	Index	:	A
	ProblemName	:	Alternative Thinking
	ProblemTags	:	['dp', 'greedy']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std ;
int arr[123123];
int nums[123123];
int main(){
    int n ;
    cin >> n ;
    string str ;
    cin >> str ;
    for(auto &it : str){
        it -= '0' ;
    }
    arr[0] =1 ;
    int num =  1;
    for(int i = 1;i < n ; i++){
        if(str[i-1] == str[i]){
            arr[i]= arr[i-1] + 1 ; 
        }
        else{
            nums[arr[i-1]] ++ ;
            num ++ ;
            arr[i] = 1;
        }
    }
    nums[arr[n-1]] ++ ;
    int m= 0 ;
    for(int i =1 ;i <= n ; i++){
        if(nums[i]){
            m = max(m , i);
        }
    }
    if(m > 2 || nums[2] >= 2){
        cout<< num + 2 << endl ; 
    }
    else if(nums[2]){
        cout << num + 1 << endl ;
    }
    else{
        cout <<num << endl ;
    }
    return 0 ;
}
