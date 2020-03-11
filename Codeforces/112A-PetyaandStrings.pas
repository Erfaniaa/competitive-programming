/*
	SubmissionId	:	5600725
	ContestId	:	112
	Index	:	A
	ProblemName	:	Petya and Strings
	ProblemTags	:	['implementation', 'strings']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

uses SysUtils, Math;
var
    S1, S2: AnsiString;
begin
    Readln(S1);
    Readln(S2);
    Writeln(Max(Min(CompareText(S1, S2), 1), -1));
end.