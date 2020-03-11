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

function GCD(A,B:Long):Long;
begin
	if B=0then
  	GCD:=A
  else
  	GCD:=GCD(B,A mod B);
end;

var
	n, i, a, m, j: LongInt;
  b: string;

begin
	r(n);
	for i := 1 to n do
	begin
		r(a,b);
    delete(b, 1, 1);
    if a = 0 th
    be
    	Wln(b);
      continue;
    en;
    m := 0;
    for j := 1 to Length(b) do
    	m := (10 * m + (Ord(b[j]) - 48)) mod a;
    Wln(GCD(A, m));
	end;
end.