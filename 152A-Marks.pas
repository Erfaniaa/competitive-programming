/*
	SubmissionId	:	5600774
	ContestId	:	152
	Index	:	A
	ProblemName	:	Marks
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
{$define brk:=break}
{$define th:=then}
{$define el:=else}
{$define rpt:=repeat}
{$define unt:=until}

uses Classes, SysUtils, Math, StrUtils;

var
    n, m, i, j, k, Mx, Count: Long;
  S: string;
  A: arr [1..100, 1..100] of Int;
  Success: Bool;

be
    rln(n, m);
  for i := 1 to n do
  be
    Rln(S);
    for j := 1 to m do
        A[i, j] := Ord(S[j]) - 48;
  en;
  for i := 1 to n do
    for j := 1 to m do
    be
        Mx := A[i, j];
      Success := true;
        for k := 1 to n do
        if A[k, j] > Mx th
        be
          Success := false;
          brk;
        en;
      if Success th
      be
        Inc(Count);
        brk;
      en;
      en;   
  Wln(Count);
en.