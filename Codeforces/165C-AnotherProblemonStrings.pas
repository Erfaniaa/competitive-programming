/*
	SubmissionId	:	5600836
	ContestId	:	165
	Index	:	C
	ProblemName	:	Another Problem on Strings
	ProblemTags	:	['binary search', 'brute force', 'dp', 'math', 'strings', 'two pointers']
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
    k, i: LongInt;
  S: Ansi;
  A: TFPList;
  Sum: Int64;

begin
    Rln(k);
    Rln(s);
  A := TFPList.Create;
  A.Add(Pointer(0));
  for i := 1 to Length(s) do
    if S[i] = '1' th
        A.Add(Pointer(i));
  A.Add(Pointer(Length(S) + 1));
  if k <> 0 th
    for i := 1 to A.Count - 1 - k do
      Sum := Sum + (Int64(A[i]) - Int64(A[i - 1])) * (Int64(A[i + k]) - Int64(A[i + k - 1]))
    el
        for i := 1 to A.Count - 1 do
        Sum := Sum + ((Int64(A[i]) - 1 - Int64(A[i - 1])) * (Int64(A[i]) - Int64(A[i - 1]))) div 2;
  Wln(Sum);
end.