/*
	SubmissionId	:	1696000
	ContestId	:	190
	Index	:	B
	ProblemName	:	Surrounded
	ProblemTags	:	['geometry']
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
  x1, x2, y1, y2, r1, r2, alpha, p1x, p1y, p2x, p2y, D: Double;

begin
	r(x1, y1, r1);
  r(x2, y2, r2);
  D := Sqrt(Sqr(x1 - x2) + Sqr(y1 - y2));
  if (D = 0) and (r1 = r2) th
  be
  	Wln('0.000000000000');
    exit;
  en;
  if D > r1 + r2 th
  be
    alpha := ArcTan2(y2 - y1, x2 - x1);
    p1x := x1 + r1 * cos(alpha);
    p1y := y1 + r1 * sin(alpha);
    p2x := x2 - r2 * cos(alpha);
    p2y := y2 - r2 * sin(alpha);
    Wln(Sqrt(Sqr(p1x - p2x) + Sqr(p1y - p2y)) / 2: 0: 12);
    exit;
  en;
  if (D = r1 + r2) or (D = Abs(r1 - r2)) or ((D > Abs(r1 - r2)) and (D < r1 + r2)) th
  be
  	Wln('0.000000000000');
    exit;
  en;
  if D < Abs(r1 - r2) th
  be 	
    if r1 > r2 th
    	Wln((r1 - (D + r2)) / 2: 0: 12)
    el
    	Wln((r2 - (D + r1)) / 2: 0: 12);
  en;
end.

