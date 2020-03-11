/*
	SubmissionId	:	1844331
	ContestId	:	202
	Index	:	A
	ProblemName	:	LLPS
	ProblemTags	:	['binary search', 'bitmasks', 'brute force', 'greedy', 'implementation', 'strings']
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
	S: Ansi;
  C: Char;
  i: Long;
  Count: arr ['a'..'z'] of Long;

begin
	Rln(S);
  for i := 1 to Length(S) do
  	Inc(Count[S[i]]);
  for c := 'z' downto 'a' do
  	if Count[c] > 0 th
    be
    	Wln(StringOfChar(c, Count[c]));
    	exit;
    en;
end.

