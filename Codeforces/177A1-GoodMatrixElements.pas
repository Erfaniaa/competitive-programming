/*
	SubmissionId	:	1594316
	ContestId	:	177
	Index	:	A1
	ProblemName	:	Good Matrix Elements
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
	n, x, y: LongInt;
  Count, a: Int64;

begin
	r(n);
  n := n div 2;
	for y := n downto -n do
  	for x := -n to n do
  	be
    	r(a);
      if (x = y) or (x = -y) or (x = 0) or (y = 0) then
      	Count := Count + a;
    en;
	Wln(Count);
end.

