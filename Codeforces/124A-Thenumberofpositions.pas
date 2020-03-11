/*
	SubmissionId	:	5600730
	ContestId	:	124
	Index	:	A
	ProblemName	:	The number of positions
	ProblemTags	:	['math']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

var
	n, a, b, Count, i: LongInt;
begin
	read(n, a, b);
	for i := 1 to n do
		if i - 1 >= a then
			if n - i <= b then
				Inc(Count);
	Writeln(Count);
end.