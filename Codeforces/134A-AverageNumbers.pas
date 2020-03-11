/*
	SubmissionId	:	5600746
	ContestId	:	134
	Index	:	A
	ProblemName	:	Average Numbers
	ProblemTags	:	['brute force', 'implementation']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

uses Math;
var
    A: array of Extended;
    n, i, j: LongInt;
    M: Real;
    B: array [1..200000]of Boolean;
begin
    Readln(n);
    SetLength(a, n);
    for i := 0 to n - 1 do
        read(a[i]);
    M := Mean(A);
    if M - Trunc(M) > 0.1 then
    begin
        Writeln(0);
        Writeln;
        exit;
    end;
    for i := 0 to n - 1 do
    begin
        if Abs(a[i] - M) <= 0.000001 then
        begin
            Inc(j);
            B[i] := true;
        end;
    end;
    Writeln(j);
    for i := 0 to n - 1 do
        if B[i] then
            write(i + 1, ' ');
    Writeln;
end.