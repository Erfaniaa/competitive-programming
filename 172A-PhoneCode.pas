/*
	SubmissionId	:	5600829
	ContestId	:	172
	Index	:	A
	ProblemName	:	Phone Code
	ProblemTags	:	['brute force', 'implementation']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

var
    S1, S2: AnsiString;
  m, i, j, n: LongInt;
begin
    Readln(n);
  Readln(S1);
  m := Length(S1);
  S2 := S1;
  for i := 2 to n do
  begin
    Readln(S1);
    J := 1;
    while (S1[j] = S2[j]) and (j <= m) do
    begin
      Inc(j);
      if j > m then
        break;
    end;
    m := j - 1;
    S2 := S1;
  end;
  Writeln(m);
end.