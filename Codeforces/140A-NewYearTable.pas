/*
	SubmissionId	:	5600711
	ContestId	:	140
	Index	:	A
	ProblemName	:	New Year Table
	ProblemTags	:	['geometry', 'math']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

uses Math;
var
    n, r1, r2, d2: LongInt;
  Angle, x: Real;
begin
    read(n, r1, r2);
  if r1 * r1 * Pi < n * r2 * r2 * Pi then
  begin
    Writeln('NO');
    exit;
  end;
  d2 := 2 * r2;
  if r1 - d2 = 0 then
  begin
    if n > 2 then
        Writeln('NO')
    else
        Writeln('YES');
    exit;
  end;
  if r1 - d2 < 0 then
  begin
    if n > 1 then
        Writeln('NO')
    else
        Writeln('YES');
    exit;
  end;  
  x := Sqrt(Sqr(r1 - r2) - r2 * r2);
  Angle := ArcTan2(r2, x);
  if n * 2 * Angle <= 2 * Pi then
      Writeln('YES')
  else
    Writeln('NO');  
end.