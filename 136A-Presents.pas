/*
	SubmissionId	:	5600669
	ContestId	:	136
	Index	:	A
	ProblemName	:	Presents
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

var
    a, i, n: Long;
  b: arr [1..100] of Long;

begin
    r(n);
  for i := 1 to n do
  begin
    read(a);
    b[a] := i;
  end;
  for i := 1 to n do
    write(b[i], ' ');
end.