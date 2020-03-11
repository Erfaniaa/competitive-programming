/*
	SubmissionId	:	13478943
	ContestId	:	584
	Index	:	E
	ProblemName	:	Anton and Ira
	ProblemTags	:	['constructive algorithms', 'greedy']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define deb(x) cout << #x << " : " << x << endl
#define debarr(arr , n) cout <<#arr << " : " ; for(int i = 1 ;i <= (n) ; i++) cout << arr[i] << " "; cout << endl 
const int maxn = 2010;

int p[maxn], q[maxn], mp[maxn], mq[maxn], ans, n;
vector<pair<int, int> > v;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		mp[x] = i;
		p[i] = x;
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		mq[x] = i;
		q[i] = x;
	}
	// 4
	// 4 2 1 3
	// 3 2 4 1
	for (int i = 1; i <= n; i++)
	{
		int idx = mp[q[i]]; // jaye adade i to avali
		while (idx != i)
		{
			// deb(i);
			// deb(idx);

			// cout << endl ;
			for (int k = n; k >= i + 1; k--)
			{
				int j = q[k];
				int idx2 = mp[j];
				if (idx2 < idx)
				{
					//swap
					swap(p[idx], p[idx2]);
					mp[p[idx]] = idx ;
					mp[p[idx2]] = idx2 ;
					v.push_back(make_pair(idx, idx2));
					ans+= idx - idx2;
					idx = idx2;
					// deb(idx);
					// deb(idx2);
					// cout << endl;

					// debarr(p,n);
					// debarr(q,n);
					// debarr(mp,n);
					// debarr(mq,n);


				}
			}
		}
	}
	cout <<   ans << endl;
	cout <<  (int)v.size() << endl;
	for (int i = 0; i < (int)v.size(); i++)
		cout << v[i].first << " " << v[i].second << "\n";
	return 0;
}