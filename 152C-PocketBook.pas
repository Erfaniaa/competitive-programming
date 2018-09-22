/*
	SubmissionId	:	5600776
	ContestId	:	152
	Index	:	C
	ProblemName	:	Pocket Book
	ProblemTags	:	['combinatorics']
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
    n, m, i, j, a: Long;
  Ch: Char;
  Count: QWord;
  S: arr [1..100] of string;
  B: arr ['A'..'Z'] of Bool;

be
    Rln(n, m);
  for i := 1 to n do
    Rln(S[i]);
  Count := 1;
  for j := 1 to m do
  be
    for ch := 'A' to 'Z' do
        B[ch] := false;
    for i := 1 to n do
        B[S[i, j]] := true;
    a := 0;
    for ch := 'A' to 'Z' do
        if B[ch] th
        Inc(a);
    Count := (Count * a) mod 1000000007;
  en;
  Wln(Count);
en.