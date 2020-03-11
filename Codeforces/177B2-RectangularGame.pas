/*
	SubmissionId	:	1599016
	ContestId	:	177
	Index	:	B2
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
	i, j: LongInt;
  x, n: Int64;
  B: Bool;

begin
	r(n);
 	x := n;
  wh n <> 1 do
  be
  	B := false;
  	for i := 2 to Round(Sqrt(n)) do
    	if n mod i = 0 th
      be
      	B := true;
      	n := n div i;
        x := x + n;
        brk;
      en;
    if not B th
    be
    	x := x + 1;
      brk;
    en;
  en;
  Wln(x);
end.

