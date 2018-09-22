/*
	SubmissionId	:	5600819
	ContestId	:	25
	Index	:	A
	ProblemName	:	IQ test
	ProblemTags	:	['brute force']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

//IQ Test.pas

{$MACRO ON}
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

var
    n, i, b: long;
    a: arr [1..200] of Long;
    d: arr [0..1] of Long;
begin
    r(n);
    for i := 1 to n do
        r(a[i]);
    for i := 1 to 3 do
        Inc(d[a[i] mod 2]);
    if d[0] > d[1] then
        b := 1;
    for i := 1 to n do
        if a[i] mod 2 = b th
        be
            Wln(i);
            brk;
        en;
end.