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
	t, n, ans, i, j: Integer;
	a: arr [1..10000] of LongInt;

begin
	r(t);
	for i := 1 to t do
	begin
		r(n);
		for j := n downto 1 do
			r(a[j]);
		ans := n;
		for j := n - 1 downto 1 do
		begin
			if (a[j] > a[j + 1]) then
			begin
				a[j] := a[j + 1];
				Dec(Ans);
			end;
		end;
		Wln(Ans);
	end;
end.
