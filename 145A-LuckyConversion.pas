/*
	SubmissionId	:	5600697
	ContestId	:	145
	Index	:	A
	ProblemName	:	Lucky Conversion
	ProblemTags	:	['greedy', 'implementation']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

uses Math;

var
    S1, S2: AnsiString;
    i, l: LongInt;
    A4, A7: LongInt;
    
begin
    Readln(S1);
    Readln(S2);
    L := Length(S1);
    for i := 1 to L do
        if S1[i] = '4' then
        begin
            if S2[i] = '7' then
                Inc(A4);
        end
        else
            if S1[i] = '7' then
                if S2[i] = '4' then
                    Inc(A7);
    Writeln(Max(A4, A7));
end.