/*
	SubmissionId	:	5600767
	ContestId	:	149
	Index	:	A
	ProblemName	:	Business trip
	ProblemTags	:	['greedy', 'implementation', 'sortings']
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

uses Classes;

func Compare(a, b: Pointer): Long;
be
    if Long(a) < Long(b) then
    exit(1);
  if Long(a) > Long(b) then
    exit(-1);
  exit(0);
en;

var
  K, S: QWord;
  i, n: Long;
    A: TFPList;

be
    r(k);
    A := TFPList.Create;
  for i := 0 to 11 do
  be
    r(n);
    A.Add(Pointer(n));
  en;
  A.Sort(Compare);
  i := 0;
    while (S < K) and (i < 12) do
  be
        S := S + LongInt(A[i]);     
    Inc(i);
  en;
    if S >= K then
      Writeln(i)
  else
    Writeln(-1);
en.