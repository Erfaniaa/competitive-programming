/*
	SubmissionId	:	1587448
	ContestId	:	181
	Index	:	B
	ProblemName	:	Number of Triplets
	ProblemTags	:	['binary search', 'brute force']
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
	n, i, j, Count: LongInt;
  C: arr [1..3000] of TPoint;
  B: arr [-1000..1000, -1000..1000] of Bool;

begin
	r(n);
  for i := 1 to n do
  be
  	r(C[i].x, C[i].y);
    B[C[i].x, C[i].y] := true;
  en;
  for i := 1 to n - 1 do
  	for j := i + 1 to n do
    be
    	if (C[i].x + C[j].x) mod 2 = 0 th
	    	if (C[i].y + C[j].y) mod 2 = 0 th
        	if B[(C[i].x + C[j].x) div 2, (C[i].y + C[j].y) div 2] th
          	Inc(Count);
    en;
  Wln(Count);
end.

