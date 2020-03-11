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
	i, t, x, y: LongInt;
	
begin
	r(t);
	for i := 1 to t do
	begin
		r(x, y);
		if (x = 0) or (y = 0) then
			Wln(0)
		else
			Wln(x - ((x + 1) div 2) + y - ((y + 1) div 2) + 1);
	end;
end.
