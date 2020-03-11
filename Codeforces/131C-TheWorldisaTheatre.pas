/*
	SubmissionId	:	5600752
	ContestId	:	131
	Index	:	C
	ProblemName	:	The World is a Theatre
	ProblemTags	:	['combinatorics', 'math']
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
{$define func:=function}
{$define proc:=procedure}
{$define be:=begin}
{$define en:=end}

var
  D: arr [0..100, 0..100] of QWord;
  S: QWord;
  i, m,  n, t: Long;

func C(n, r: Int): QWord;
be
    if D[n, r] > 0 then
    exit(D[n, r]);
    if r > n then
  begin
    D[n, r] := 0;
    D[n, n - r] := 0;
    exit(0);
  end;
  if (r = n) or (r = 0) then
  begin
    D[n, r] := 1;
    D[n, n - r] := 1;
    exit(1);
  end;
  D[n, r] := C(n - 1, r - 1) + C(n - 1, r);
  D[n, n - r] := D[n, r];
  C := D[n, r];
en;

begin
    r(m, n, t);
    for i := 4 to t - 1 do
  begin
    //Writeln(S);
    Inc(S, C(m, i) * C(n, t - i));
  end;
  Writeln(S);
end.