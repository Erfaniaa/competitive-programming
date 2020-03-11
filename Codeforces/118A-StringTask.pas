/*
	SubmissionId	:	5600691
	ContestId	:	118
	Index	:	A
	ProblemName	:	String Task
	ProblemTags	:	['implementation', 'strings']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

uses SysUtils, StrUtils;
var
    S: AnsiString;
    I: Longint;
begin
    Readln(S);
    S := LowerCase(S);
    S := DelChars(S, 'a');
    S := DelChars(S, 'e');
    S := DelChars(S, 'i');
    S := DelChars(S, 'o');
    S := DelChars(S, 'u');
    S := DelChars(S, 'y');
    for i := Length(S) downto 1 do
        Insert('.', S, i);
    Writeln(S);
end.