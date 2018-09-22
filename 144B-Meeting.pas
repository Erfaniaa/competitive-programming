/*
	SubmissionId	:	5600642
	ContestId	:	144
	Index	:	B
	ProblemName	:	Meeting
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

uses Math;
var
    x1, x2, y1, y2, a, b, Count, i, n: LongInt;
    x, y, r: array [1..1000] of LongInt;
begin
    read(x1, y1, x2, y2);
    read(n);
    for i := 1 to n do
        read(x[i], y[i], r[i]);
    for a := Min(x1, x2) to Max(x1, x2) do
        for b := Min(y1, y2) to Max(y1, y2) do
            if (a = Min(x1, x2)) or (a = Max(x1, x2)) or (b = Min(y1, y2)) or (b = Max(y1, y2)) then
                for i := 1 to n do
                    if Sqrt(Sqr(a - x[i]) + Sqr(b - y[i])) <= r[i] then
                    begin
                        Inc(Count);
                        break;
                    end;
    Writeln((Max(x1, x2) - Min(x1, x2) + 1) * (Max(y1, y2) - Min(y1, y2) + 1) - (Max(x1, x2) - Min(x1, x2) - 1) * (Max(y1, y2) - Min(y1, y2) - 1) - Count);
end.