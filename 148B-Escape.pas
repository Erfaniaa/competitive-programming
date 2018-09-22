/*
	SubmissionId	:	5600678
	ContestId	:	148
	Index	:	B
	ProblemName	:	Escape
	ProblemTags	:	['implementation', 'math']
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

var
    v1, v2, delay, spend, dis, i: Long;
  x1, x2, t: Real;

begin
    r(V1, v2, delay, spend, dis);
    if v1 >= v2 then
  begin
    Writeln(0);
    exit;
  end;
  x1 := v1 * delay;
  while x1 < dis do
  begin
    t := (x1 - x2) / (v2 - v1);
    x2 := x2 + v2 * t;
    x1 := x1 + v1 * t;
    //Writeln(x1 = x2);
    if x2 < dis then
    begin
        Inc(i);
      //Writeln(x1:0:2, ' ', x2:0:2, ' ', t:0:2);
    end;
    x1 := x1 + (spend + x2 / v2) * v1;
    x2 := 0;
  end;
  Writeln(i);
end.