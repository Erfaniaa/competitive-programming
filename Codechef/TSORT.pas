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
	n, i, j, a: LongInt;
  c: arr [1..1000000] of Long;

begin
	r(n);
  for i := 1 to n do
  be
  	r(a);
    Inc(c[a]);
  en;
  for i := 1 to 1000000 do
  	for j := 1 to c[i] do
    	Wln(i);
end.

