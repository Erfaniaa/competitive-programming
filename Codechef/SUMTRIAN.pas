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
	n, i, a, j, k: LongInt;
  x: arr [1..1000, 1..1000] of Long;

begin
	r(n);
	for i := 1 to n do
	begin
		r(a);
    for j := 1 to a do
    	for k := 1 to j do
      	r(x[j, k]);
    for j := a - 1 downto 1 do
    	for k := 1 to j do
      	Inc(x[j, k], Max(x[j + 1, k], x[j + 1, k + 1]));
    Wln(x[1, 1]);
	end;
end.

