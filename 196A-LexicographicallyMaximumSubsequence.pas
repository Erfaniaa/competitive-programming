/*
	SubmissionId	:	5600913
	ContestId	:	196
	Index	:	A
	ProblemName	:	Lexicographically Maximum Subsequence
	ProblemTags	:	['greedy']
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
    n, i, c, Pos, pos2: LongInt;
  S: Ansi;
  B: arr ['a'..'z'] of Bool;
  Last: arr ['a'..'z'] of Long;
  Ch: Char;

begin
    Rln(S);
  for i := 1 to Length(S) do
    B[S[i]] := true;
  for i := Length(S) downto 1 do
    Last[S[i]] := Max(Last[S[i]], i);
  pos := 1;
  for ch := 'z' downto 'a' do
  be
    if not B[ch] th
        continue
    el
    be  
        c := 0;
      pos2 := -1;
        for i := pos to Last[ch] do
        if S[i] = ch th
        be
            Inc(c);
          pos2 := i;
        en;
      W(StringofChar(Ch, c));
      if pos2 > -1 th
          pos := pos2;
      if Pos = Length(S) th
        brk;
    en;
  en;
    Wln;
end.