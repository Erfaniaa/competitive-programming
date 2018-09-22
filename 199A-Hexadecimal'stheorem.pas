/*
	SubmissionId	:	5600910
	ContestId	:	199
	Index	:	A
	ProblemName	:	Hexadecimal's theorem
	ProblemTags	:	['brute force', 'constructive algorithms', 'implementation', 'number theory']
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
    F: arr [0..10000] of Long;

func Fibo(a: Long): Long;
var
    i: Long;
be
  for i := 2 to a do
    if F[i - 1] + F[i - 2] < 1000000000 th
        F[i] := F[i - 1] + F[i - 2]
    el
        brk;
  exit(F[i]);
en;

var
    n, i, a: LongInt;

begin
    F[1] := 1;
  r(n);
  Fibo(10000);
  for i := 0 to 10000 do
    if F[i] = n th
    be
        a := i;
      brk;
    en;
  if a = 0 th
    Wln('0 0 0')
  el if a = 1 th
    Wln('0 0 1')
  el if a = 2 th
    Wln('0 0 1')
  el if a = 3 th
    Wln('0 1 1')
  el
  be
    Wln(F[i - 4], ' ', F[i - 3], ' ', F[i - 1]);
  en;
end.