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
	//B: arr [1..100002] of Bool;
	n, k, m, t, tt: LongInt;
	
begin
	r(t);
	for tt := 1 to t do
	begin
		r(n, k);
		m := 2 ** n;
		if (k mod m = m - 1) then
			Wln('ON')
		else
			Wln('OFF');
	end;
end.
