/*
	SubmissionId	:	5600777
	ContestId	:	152
	Index	:	B
	ProblemName	:	Steps
	ProblemTags	:	['binary search', 'implementation']
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
{$define brk:=break}
{$define th:=then}
{$define el:=else}
{$define rpt:=repeat}
{$define unt:=until}

uses Classes, SysUtils, Math, StrUtils;

var
    Count, x, y, n, m, k, vx, vy, x2, y2, vx2, vy2, Mn: Int64;
  i: LongInt;

be
    r(n, m);
  r(x, y);
  r(k);
  for i := 1 to k do
  be
    r(vx, vy);
    if vx < 0 th
        x2 := x - 1
    el
    if vx > 0 th
        x2 := n - x
    el
        x2 := MaxLongInt;
    if vy < 0 th
        y2 := y - 1
    el
    if vy > 0 th
        y2 := m - y
    el
        y2 := MaxLongInt;
    vx2 := Abs(vx);
    vy2 := Abs(vy);
    if (vy2 <> 0) and (vx2 <> 0) th
        Mn := Min(x2 div vx2, y2 div vy2)
    el
        if vy2 = 0 th
        Mn := x2 div vx2
      el
        Mn := y2 div vy2;
    Count := Count + Mn;
    x := x + Mn * vx;
    y := y + Mn * vy;
  en;
    Wln(Count);
en.