/*
	SubmissionId	:	5600673
	ContestId	:	134
	Index	:	B
	ProblemName	:	Pairs of Numbers
	ProblemTags	:	['brute force', 'dfs and similar', 'math', 'number theory']
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

uses Math, Classes;

type
    TPair = record
    a, b: 1..1000000;
    d: 0..63;
  end;

func Pair(a, b, d: Long): TPair;
var
    z: TPair;
be
    z.a := a;
  z.b := b;
  z.d:=d;
  Pair := z;
en;

var
  x, M: QWord;

{proc Pair(a, b, k: Long);
begin
    if (a < x) and (b < x) then
  begin
    Pair(a, a + b, k + 1);
    Pair(a + b, b, k + 1);
    exit;
    end
  else
  if (a = x) or (b = x) then
    M := Min(k, M);
end;}

var
    L, L2: arr [1..20000000] of TPair;
  Total, i: QWord;
  j: Long;

begin
  r(X);
  //SetLength(L, 10001);
  if x = 1 then
  be
    Writeln(0);
    exit;
  en;
  for j := X - 1 downto X div 2 do
    L[X - j] := Pair(X, j, 0);
  Total := X - j;
  wh true do
  be
    Inc(i);
    {if i = 1 then
    begin
        //Writeln(L[i].a, ' ', L[i].b, ' ', L[i].d);
            Readln;
    end;}
    if L[i].a - L[i].b >= 1 then
    begin
        if L[i].a = 2 then
      begin
        Writeln(L[i].d + 1);
        exit;
      end
      else
      begin
            if true{B[L[i].a + L[i].b]} then
        begin
          Inc(Total);
            L[Total] := Pair(Max(L[i].a - L[i].b, L[i].b), Min(L[i].a - L[i].b, L[i].b), L[i].d + 1);
          (*if Total = 100 then
          begin
            Writeln('Yes!');
            {SetLength(L2, Total - i + 2);
            Writeln('Yes!');
            Writeln(L[i].a);
            for j := 1 to Total - i + 1 do
                L2[j] := L[i + j - 1];
            SetLength(L, Total - i + 2);
            Writeln('Yes!');
            L := l2;
            SetLength(L, 10001);
            SetLength(L2, 1);
            Writeln('Yes!');
            Writeln(i);
            Writeln('Yes!');}
            L := Copy(L, i, Total - i + 1);
            SetLength(L, 10001);
            Total := Total - i + 1;
            i := 0;
            continue;
          end;
//          B[L[i].a + L[i].b] := true;*)
        end;
      end;
    end;
  en;
end.