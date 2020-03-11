/*
	SubmissionId	:	5600764
	ContestId	:	39
	Index	:	H
	ProblemName	:	Multiplication Table
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

{$MACRO ON}
{$define W:=write}
{$define Wln:=Writeln}
{$define R:=read}
{$define Rln:=Readln}
{$define Wh:=while}
{$define arr:=array}
{$define str:=string}
{$define Int:=Integer}
{$define Long:=LongInt}
{$define Ansi:=AnsiString}
{$define Bool:=Boolean}
{$define func:=function}
{$define proc:=procedure}
{$define be:=begin}
{$define en:=end}
{$define el:=else}
{$define brk:=break}

uses Math, strUtils;

var
    n, i, j: LongInt;

begin
    r(n);
    for i := 1 to n - 1 do
    begin
        for j := 1 to n - 1 do
            W(Dec2Numb(i * j, Trunc(logn(n, i * j)) + 1, n), ' ');
        Writeln;
    end; 
end.