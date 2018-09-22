/*
	SubmissionId	:	5600840
	ContestId	:	59
	Index	:	A
	ProblemName	:	Word
	ProblemTags	:	['implementation', 'strings']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

var
    s: AnsiString;
  i, a, b: LongInt;

begin
    Readln(s);
  for i := 1 to Length(s) do
    if (s[i] >= 'a') and (s[i] <= 'z') then
        Inc(a)
    else
        Inc(b);
    if a >= b then
    s := LowerCase(s)
  else
    s := UpCase(s);
  Writeln(s);
end.