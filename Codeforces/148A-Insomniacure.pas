/*
	SubmissionId	:	5600665
	ContestId	:	148
	Index	:	A
	ProblemName	:	Insomnia cure
	ProblemTags	:	['constructive algorithms', 'implementation', 'math']
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

var
    a, b, c, d, j, i, e: LongInt;
  fl: arr [1..100000] of Boolean;

begin
    read(a, b, c, e, d);
  for i := 1 to d div a do
    fl[i * a] := true;
  for i := 1 to d div b do
    fl[i * b] := true;
  for i := 1 to d div c do
    fl[i * c] := true;
  for i := 1 to d div e do
    fl[i * e] := true;
  for i := 1 to d do
    if not fl[i] then
        Inc(j);
  Writeln(d - j);
end.