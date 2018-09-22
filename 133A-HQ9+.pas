/*
	SubmissionId	:	5600687
	ContestId	:	133
	Index	:	A
	ProblemName	:	HQ9+
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

var
    S: AnsiString;
begin
    Readln(S);
    if (Pos('H', S) > 0) or (Pos('Q', S) > 0) or (Pos('9', S) > 0) then
        Writeln('YES')
    else
        Writeln('NO');
end.