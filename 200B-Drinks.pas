/*
	SubmissionId	:	1826761
	ContestId	:	200
	Index	:	B
	ProblemName	:	Drinks
	ProblemTags	:	['implementation', 'math']
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

uses Classes, SysUtils, StrUtils, Math;

var
	n, i, a, Sum: LongInt;

begin
	r(n);
  for i := 1 to n do
  be
  	r(a);
    Inc(Sum, a);
  en;
  Wln(Sum / n: 0: 5);
end.

