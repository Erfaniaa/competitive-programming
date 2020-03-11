/*
	SubmissionId	:	5600948
	ContestId	:	234
	Index	:	B
	ProblemName	:	Reading
	ProblemTags	:	['sortings']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

#define cin fin
#define cout fout

int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > nums(n);
    for (int i = 0; i < n; i++)
    {
    cin >> nums[i].first;
    nums[i].second = i + 1;
    }
    sort(nums.begin(), nums.end());
//    cout << "nums.size(): " << nums.size() << endl;
    cout << nums[nums.size() - k].first << endl;
    for (int i = nums.size() - 1; i >= ((int) nums.size()) - k; i--)
    {
    cout << nums[i].second << " ";
    }
    cout << endl;
    return 0;
}