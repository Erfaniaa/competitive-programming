/*
	SubmissionId	:	5600733
	ContestId	:	133
	Index	:	B
	ProblemName	:	Unary
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

uses StrUtils;
const
    S1: array [1..8] of string = ('>', '<', '+', '-', '.', ',', '[', ']');
    S2: array [1..8] of string = ('1000', '1001', '1010', '1011', '1100', '1101', '1110', '1111');
var
    S: AnsiString;
    i: LongInt;
    n: QWord;
    
begin
    Readln(S);
    for i := 1 to 8 do
        S := AnsiReplaceStr(S, S1[i], S2[i]);
    for i := 1 to Length(S) do
        n := (2 * n + (Ord(S[i]) - 48)) mod 1000003;
    Writeln(n);
end.