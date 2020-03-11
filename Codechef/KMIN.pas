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
	n, k, mink, sum, j, a, i, mn: LongInt;
	count: array [0..100000] of LongInt;

begin
	r(n, k);
	mink := 100001;
	mn := 100001;
	for i := 1 to n do
	begin
		r(a);
		if a = -1 then
		begin
			sum := 0;
			for j := mn to 100000 do
			begin
				sum := sum + count[j];
				if (sum >= k) then
				begin
					mink := j;
					Wln(j);
					break;
				end;
			end;
		end
		else
		begin
			mn := min(mn, a);
			if a <= mink then
				Inc(count[a]);
		end;
	end;
end.
