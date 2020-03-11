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
	n, i, a, j, b, x: LongInt;

begin
	r(n);
	for i := 1 to n do
	begin
		r(a);
    x := 0;
    for j := 1 to a do
    be
    	r(b);
      Inc(x, b div j);
    en;
  	if x mod 2 = 0 th
    	Wln('BOB')
    el
    	Wln('ALICE');
	end;
end.

