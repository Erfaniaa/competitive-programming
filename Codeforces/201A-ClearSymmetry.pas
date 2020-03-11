/*
	SubmissionId	:	5600984
	ContestId	:	201
	Index	:	A
	ProblemName	:	Clear Symmetry
	ProblemTags	:	['constructive algorithms', 'dp', 'math']
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
    m, n, i, x, xx, y, Cnt, lim, mx, k, l: LongInt;
  A: arr [-1..101, -1..101] of 0..1;

func Count: Long;
var
    x, y, Sum: Long;
be
    Sum := 0;
    for x := 1 to m do
    for y := 1 to m do
        Sum := Sum + A[x, y];
  exit(Sum);
en;

proc Zero;
var
    x, y: Long;
be
    for x := 1 to m do
    for y := 1 to m do
        A[x, y] := 0;
en;

func CanPut: Bool;
be
    for x := 1 to lim do
    for y := 1 to lim do
        if (A[x, y] = 0) and (A[x - 1, y] = 0) and (A[x + 1, y] = 0) and (A[x, y - 1] = 0) and (A[x, y + 1] = 0) th
        exit(true);
  exit(false);
en;

func IsClear: Bool;
be
    for x := 1 to m do
    for y := 1 to m do
        if (A[x, y] = 1) and ((A[x - 1, y] = 1) or (A[x + 1, y] = 1) or (A[x, y - 1] = 1) or (A[x, y + 1] = 1)) th
        exit(false);
  exit(true);
en;

proc Put(x, y: Long);
be
    if A[x, y] = 0 th
    Inc(Cnt);
    A[x, y] := 1;
en;

begin
    Rln(xx);
  if Sqrt(xx) = Trunc(Sqrt(xx)) th
    m := Trunc(Sqrt(xx))
  el
      m := Trunc(Sqrt(xx)) + 1;
  Randomize;
  wh true do
  be
    //Wln(m);
    //Rln;
    if m mod 2 = 0 th
        lim := m div 2
    el
        lim := m div 2 + 1;
    for k := 1 to 10000 do
    be
        repeat
            mx := Random(lim * lim) + 1;
      until mx <= xx;
      Zero;
      Cnt := 0;
      //Wln('Zero');
        for l := 1 to mx do
      be
        repeat
            x := Random(lim) + 1;
            y := Random(lim) + 1;
          //Wln(x, ' ', y);
        until (A[x, y] = 0) and (A[x - 1, y] = 0) and (A[x + 1, y] = 0) and (A[x, y - 1] = 0) and (A[x, y + 1] = 0);
        {A[x, y] := 1;
        A[m - x + 1, y] := 1;
        A[x, m - y + 1] := 1;
        A[m - x + 1, m - y + 1] := 1;}
        Put(x, y);
        Put(m - x + 1, y);
        Put(x, m - y + 1);
        Put(m - x + 1, m - y + 1);
        {for y := 1 to m do
        be
            for x := 1 to m do
            w(A[x, y], ' ');
          Wln;
        en;}
        //Cnt := Count;
        if Cnt = xx th
          if IsClear th
          be
            Wln(m);
            exit;
          en;
        if not CanPut th
            brk;
      en;
    en;
    Inc(m);
  en;   
end.