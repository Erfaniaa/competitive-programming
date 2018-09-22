/*
	SubmissionId	:	5600759
	ContestId	:	4
	Index	:	A
	ProblemName	:	Watermelon
	ProblemTags	:	['brute force', 'math']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

var
    N: LongInt;
begin
    read(n);
    if (n mod 2 = 0) and (n <> 2) then
        Writeln('YES')
    else
        Writeln('NO');
end.