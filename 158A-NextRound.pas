/*
	SubmissionId	:	5600782
	ContestId	:	158
	Index	:	A
	ProblemName	:	Next Round
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
    n, k, i, Count: Long;
    a: arr [1..50] of Long;
    
begin
    r(n, k);
    for i := 1 to n do
        r(a[i]);
    for i := 1 to n do
        if a[i] > 0 then
            if a[i] >= a[k] then
                Inc(Count);
    Wln(Count);
end.