/*
	SubmissionId	:	1661031
	ContestId	:	186
	Index	:	C
	ProblemName	:	Plant
	ProblemTags	:	['dp', 'math', 'matrices', 'number theory']
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

const
	M: Int64 = 1000000007;

func Power(b: Int64): Int64;
be
	if b = 0 th
  	exit(1);
  if b = 1 th
  	exit(2);
  if b mod 2 = 0 th
  	exit(Sqr(Power(b div 2) mod M) mod M)
  el
  	exit((2 * (Power(b - 1) mod M)) mod M);
en;

var
  n: Int64;

begin
	r(n);
  if n = 0 th
  	Wln(1)
  el
	  Wln((Power(2 * n - 1) + Power(n - 1)) mod M);
end.

