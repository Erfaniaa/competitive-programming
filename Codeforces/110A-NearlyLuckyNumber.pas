/*
	SubmissionId	:	5600851
	ContestId	:	110
	Index	:	A
	ProblemName	:	Nearly Lucky Number
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

uses SysUtils;

var
    s: AnsiString;
  B: Boolean;
  i, x: LongInt;

begin
    Readln(s);
  B := true;
  for i := 1 to Length(s) do
    if (s[i] = '4') or (s[i] = '7') then
        Inc(x);
  s := IntToStr(x);
  for i := 1 to Length(s) do
    if s[i] <> '4' then
        if s[i] <> '7' then
      begin
        B := false;
        break;
      end;
  if B then
    Writeln('YES')
  else
    Writeln('NO');
end.