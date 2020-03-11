/*
	SubmissionId	:	5600803
	ContestId	:	159
	Index	:	C
	ProblemName	:	String Manipulation 1.0
	ProblemTags	:	['binary search', 'brute force', 'data structures', 'strings']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
string IntToStr(int i){
        stringstream ss;
        ss << i;
        return ss.str();
}
int main(){
    int n,k;
    string s,tempS;
    map<char ,vector<int> > Position;
    //map<char,int> Count;
    
    cin >> k;
    cin >> s;
    tempS=s;
    for (int i=0;i < k-1 ;i++)
        s+=tempS;
    cin >> n;
    for (int i = 0; i < s.length(); i++)
    {
        Position[s[i]].push_back(i);
        //cout << s[i] << i;
    }
    for(int i=0;i < n;i++)
    {
            int a;
            char s2;
            cin >> a >> s2;
            s[Position[s2][a-1]] = '~';
            //cout << s <<endl;
            Position[s2].erase(Position[s2].begin()+(a-1));
    }
    for (int i=0;i< s.length();i++)
        if(s[i] != '~')
            cout<<s[i];
    cout<<endl;
    //cin.get();
        return 0;
}