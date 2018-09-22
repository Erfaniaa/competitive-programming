/*
	SubmissionId	:	5600796
	ContestId	:	158
	Index	:	D
	ProblemName	:	Ice Sculptures
	ProblemTags	:	['*special', 'brute force', 'number theory']
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
{$define th:=then}

uses Math;

var
    i, n: Long;
    a: arr [1..40000] of Int;
    Mx: Int64;

function Sum(x: Long): Int64;
var
    S, Mx: int64;
    i, j: LongInt;
begin
    Mx := -20000001;
    for j := 0 to x - 1 do
    begin
        S := 0;
        for i := 1 to (n div x) do
            S := S + a[j + i * x];
        Mx := Max(S, Mx);
    end;
    Sum := Mx;
end;

begin
    r(n);
    for i := 1 to n do
        r(a[i]);
    for i := n + 1 to 2 * n do
        a[i] := a[i - n];
    i := 1;
    Mx := -20000001;
    while n div i > 2 do
    begin
        if n mod i = 0 then
            Mx := Max(Mx, Sum(i));
        Inc(i);
    end;
    Wln(Mx);
end.