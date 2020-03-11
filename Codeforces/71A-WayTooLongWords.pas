/*
	SubmissionId	:	5600728
	ContestId	:	71
	Index	:	A
	ProblemName	:	Way Too Long Words
	ProblemTags	:	['strings']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

var
    n, i: LongInt;
    S: AnsiString;
begin
    readln(n);
    for i := 1 to n do
    begin
        Readln(S);
        if Length(S) > 10 then
            Writeln(S[1], Length(S) - 2, S[Length(S)])
        else
            Writeln(S);
    end;
end.