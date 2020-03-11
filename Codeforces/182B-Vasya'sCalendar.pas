/*
	SubmissionId	:	1626734
	ContestId	:	182
	Index	:	B
	ProblemName	:	Vasya's Calendar
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
{$define th:=then}

uses Classes, SysUtils, StrUtils, Math;

var
	d, n, i, a: LongInt;
	Count: Int64;

begin
	r(d, n);
  for i := 1 to n - 1 do
  be
  	r(a);
    Inc(Count, d - a);
  en;
  Wln(Count);
end.

