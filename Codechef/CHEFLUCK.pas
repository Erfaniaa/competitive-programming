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
  B: Bool;

begin
	r(n);
  for i := 1 to n do
  be
  	r(a);
    B := false;
    for j := a div 7 downto 0 do
    	if (a - j * 7) mod 4 = 0 th
      be
      	Wln(j * 7);
        B := true;
        brk;
      en;
    if not B th
    	Wln(-1);
  en;
end.

