/*
	SubmissionId	:	1890313
	ContestId	:	205
	Index	:	A
	ProblemName	:	Little Elephant and Rozdil
	ProblemTags	:	['brute force', 'implementation']
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
	n, i, d: LongInt;
  Mn: Int64;
  a: arr [1..100000] of Long;

begin
	r(n);
  Mn := 10000000000;
  for i := 1 to n do
  be
  	r(a[i]);
    if a[i] < Mn th
    be
    	d := i;
      Mn := a[i];
    en;
  en;
  for i := 1 to n do
  	if a[i] = mn th
    	if d <> i th
      be
      	Wln('Still Rozdil');
	      exit;
	    en;
  Wln(d)
end.

