/*
	SubmissionId	:	5600653
	ContestId	:	147
	Index	:	A
	ProblemName	:	Punctuation
	ProblemTags	:	['implementation', 'strings']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

uses StrUtils;
var
    S: AnsiString;
  I: LongInt;
begin
    Readln(s);
  for i := Length(S) - 1 downto 2 do
    if S[i] in ['.', ',', '!', '?'] then
    begin
        Insert(' ', S, i);
      Insert(' ', S, i + 2);
    end;
  S := DelSpace1(S);
  for i := 2 to Length(S) - 1 do
  begin
    if S[i] in ['.', ',', '!', '?'] then
      Delete(S, i - 1, 1);
    if i > Length(S) - 1 then
        break;
  end;
  Writeln(S);
end.