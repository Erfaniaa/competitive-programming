/*
	SubmissionId	:	5600847
	ContestId	:	1
	Index	:	A
	ProblemName	:	Theatre Square
	ProblemTags	:	['math']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/


 var
  n, m, a, x, y: Int64;
begin
    read(m, n, a);
  if m mod a = 0 then
    x := m div a
  else
    x := (m div a) + 1;
  if n mod a = 0 then
    y := n div a
  else
    y := (n div a) + 1;
  Writeln(x * y);
end.