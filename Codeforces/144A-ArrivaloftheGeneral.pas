/*
	SubmissionId	:	5600637
	ContestId	:	144
	Index	:	A
	ProblemName	:	Arrival of the General
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

uses Classes, Math, SysUtils, StrUtils;
var
    n, i, j, k: LongInt;
    a: array of LongInt;
begin
    read(n);
    SetLength(a, n);
    for i := 0 to n - 1 do
        read(a[i]);
    for j := 0 to n - 1 do
        if a[j] = MaxIntValue(a) then
            break;
    for k := n - 1 downto 0 do
        if a[k] = MinIntValue(a) then
            break;
    Inc(j);
    Inc(k);
    if k > j then
        Writeln(j - 1 + n - k)
    else
        Writeln(j - 2 + n - k);
end.