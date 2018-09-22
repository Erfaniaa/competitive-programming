/*
	SubmissionId	:	5600769
	ContestId	:	149
	Index	:	B
	ProblemName	:	Martian Clock
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

uses StrUtils;

func IsOK(S: Ansi; B, M: Int): Bool;
var
    i, n, A: Int;
be
    A := 0;
    for i := 1 to Length(S) do
  be
    if S[i] in ['0'..'9'] then
        n := Ord(S[i]) - 48
    else
        n := Ord(S[i]) - 65 + 10;
    if n >= B then
        exit(false);
    A := A * B + n;
    if A > M th
        exit(false);
  en;
  exit(true);
en;

var
    A, B, S: ansi;
  Bl: Bool;
  i, j: Int;
  C: arr [1..100] of Int;

be
    Rln(S);
  A := Copy(S, 1, Pos(':', S) - 1);
  B := Copy(S, Pos(':', S) + 1, Length(S));
  A := TrimLeftSet(A, ['0']);
  B := TrimLeftSet(B, ['0']);
  Bl := false;
  for i := 1 to 60 do
  be
    if IsOk(A, i, 23) th
        if IsOK(B, i, 59) th
      be
        Inc(j);
        C[j] := i;
        if i = 60 then
            Bl := true;
        continue;
      en;
  en;
  if Bl then
  be
    Wln(-1);
    exit;
  en;
  if j = 0 then
    Wln(0);
  for i := 1 to j do
    W(C[i], ' ');
en.