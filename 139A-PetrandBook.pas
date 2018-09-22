/*
	SubmissionId	:	5600708
	ContestId	:	139
	Index	:	A
	ProblemName	:	Petr and Book
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

var
    w: array [1..7] of LongInt;
  n, count, S: QWord;
  i: LongInt;
begin
    read(n);
  for i := 1 to 7 do
    read(w[i]);
  i := 0;
  while S < n do
  begin
    Inc(i);
    S := S + w[i];
    if S >= n then
        break;
    if i = 7 then
        i := 0;
  end;
  Writeln(i);
end.