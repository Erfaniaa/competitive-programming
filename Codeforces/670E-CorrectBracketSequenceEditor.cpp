/*
	SubmissionId	:	17737680
	ContestId	:	670
	Index	:	E
	ProblemName	:	Correct Bracket Sequence Editor
	ProblemTags	:	['data structures', 'dsu']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF (1000 * 1000 * 1000)
#define MAXN 500010

int n, m, p, nxt[MAXN], prv[MAXN], match[MAXN];
vector <int> st;
char s[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++)
	{
		char ch;
		cin >> ch;
		s[i] = ch;
		if (ch == '(')
			st.push_back(i);
		else
		{
			int top = st[(int)st.size() - 1];
			match[i] = top;
			match[top] = i;
			st.pop_back();
		}
	}
	for (int i = 0; i <= n + 1; i++)
	{
		nxt[i] = i + 1;
		prv[i] = i - 1;
	}
	prv[0] = 0;
	nxt[n + 1] = n + 1;
	for (int i = 1; i <= m; i++)
	{
		char ch;
		cin >> ch;
		if (ch == 'L')
			p = prv[p];
		if (ch == 'R')
			p = nxt[p];
		if (ch == 'D')
		{
			int q = match[p];
			if (q < p)
			{
				nxt[prv[q]] = nxt[p];
				prv[nxt[p]] = prv[q];
				p = nxt[p];
				if (p == n + 1)
					p = prv[q];
			}
			else
			{
				prv[nxt[q]] = prv[p];
				nxt[prv[p]] = nxt[q];	
				p = nxt[q];
				if (p == n + 1)
					p = prv[p];
			}
		}
	}
	int idx = 0;
	idx = nxt[idx];
	while (idx != n + 1)
	{
		cout << s[idx];
		idx = nxt[idx];
	}
	cout << endl;
	return 0;
}