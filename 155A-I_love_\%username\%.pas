/*
	SubmissionId	:	5600790
	ContestId	:	155
	Index	:	A
	ProblemName	:	I_love_\%username\%
	ProblemTags	:	['brute force']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

uses Math;
var
    Mn, Mx, n, i, a, Count: LongInt;

begin
    read(n);
  read(a);
  Mx := a;
  Mn := a;
  for i := 2 to n do
    begin
    read(a);
    if (a > Mx) or (a < Mn) then
        Inc(Count);
    Mx := Max(Mx, a);
    Mn := Min(Mn, a);
  end;
  Writeln(Count);
end.