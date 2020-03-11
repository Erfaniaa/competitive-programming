/*
	SubmissionId	:	1586826
	ContestId	:	181
	Index	:	A
	ProblemName	:	Series of Crimes
	ProblemTags	:	['brute force', 'geometry', 'implementation']
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
	xx, yy, x, y, x1, y1, x2, y2: Long;
  S: array [1..200] of string;

begin
	Readln(yy, xx);
  for y := 1 to yy do
  	Readln(S[y]);
  x2 := -1;
  y2 := -1;
  x1 := 200;
  y1 := 200;
  for y := 1 to yy do
  	for x := 1 to xx do
    	if s[y, x] = '*' then
      be
      	x1 := min(x1, x);
        y1 := min(y1, y);
        x2 := max(x2, x);
        y2 := max(y2, y);
      en;
  if s[y1, x1] = '.' th
  	Wln(y1, ' ', x1);
  if s[y2, x1] = '.' th
  	Wln(y2, ' ', x1);
  if s[y1, x2] = '.' th
  	Wln(y1, ' ', x2);
  if s[y2, x2] = '.' th
  	Wln(y2, ' ', x2);
end.

