/*
	SubmissionId	:	1653263
	ContestId	:	186
	Index	:	A
	ProblemName	:	Comparing Strings
	ProblemTags	:	['implementation', 'strings']
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
	i, Count: LongInt;
  P: arr [1..3] of Long;
  S1, S2: Ansi;

begin
	Rln(S1);
  Rln(S2);
  if S1 = S2 th
	be
  	Wln('YES');
    exit;
  en;
  if Length(S1) <> Length(S2) th
  be
  	Wln('NO');
    exit;
  en;
  for i := 1 to Length(S1) do
  	if S1[i] <> S2[i] th
    be
    	Inc(Count);
      P[Count] := i;
      if Count = 3 th
      be
      	Wln('NO');
        exit;
      en;
    en;
	if Count = 2 th
  	if S1[P[1]] = S2[P[2]] th
    	if S2[P[1]] = S1[P[2]] th
      be
      	Wln('YES');
        exit;
      en;
  Wln('NO');
end.