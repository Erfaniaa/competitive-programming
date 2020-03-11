/*
	SubmissionId	:	1599902
	ContestId	:	177
	Index	:	D1
	ProblemName	:	Encrypting Messages
	ProblemTags	:	['brute force']
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
	m, n, c, i, j: LongInt;
  a, b: arr [1..100000] of Int64;

begin
	r(n, m, c);
  for i := 1 to n do
  	r(a[i]);
  for i := 1 to m do
  	r(b[i]);
  for i := 1 to n - m + 1 do
  	for j := 0 to m - 1 do
    	a[i + j] := (a[i + j] + b[j + 1]) mod c;
  for i := 1 to n do
  	w(a[i], ' ');
  Wln;
end.

