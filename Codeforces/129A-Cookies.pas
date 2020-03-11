/*
	SubmissionId	:	5600739
	ContestId	:	129
	Index	:	A
	ProblemName	:	Cookies
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

uses Math;
var
    a: array of Int64;
    i, j, n: LongInt;
    S: Int64;
begin
    readln(n);
    SetLength(a, n);
    for i := 0 to n - 1 do
        read(a[i]);
    S := SumInt(A);
    if S mod 2 = 0 then
    begin
        for i := 0 to n - 1 do
            if a[i] mod 2 = 0 then
                Inc(j);
    end
    else
    begin
        for i := 0 to n - 1 do
            if a[i] mod 2 = 1 then
                Inc(j);
    end;
    Writeln(j);
end.