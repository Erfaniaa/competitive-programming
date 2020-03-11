/*
	SubmissionId	:	1595338
	ContestId	:	177
	Index	:	B1
	ProblemName	:	Rectangular Game
	ProblemTags	:	['number theory']
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
	i: LongInt;
  x, n: Int64;

begin
	r(n);
 	x := n;
  while n <> 1 do
  	for i := 2 to n do
    	if n mod i = 0 th
      be
      	n := n div i;
        x := x + n;
      	brk;
      en;
  Wln(x);
end.

