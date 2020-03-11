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
	//s: str;
	m, n, k, t, i: Long;

function Palindrome(l: LongInt; S: string): string;
begin
	if l mod 2 = 0 then
		exit(s + ReverseString(s))
	else
		exit(s + ReverseString(Copy(s, 1, length(s) - 1)) );
end;

begin
	rln(t);
	For i := 1 to t do
	begin
		//rln(s);
		r(n, k);
		//n := StrToInt(Copy(s, 1, Pos(',', s) - 1));
		//k := StrToInt(Copy(s, Pos(',', s) + 1, 100));
		if n = 1 then
			Wln(k)
		else if n = 2 then
			Wln(11 * k)
		else
		begin
			m := (n div 2) + (n mod 2) - 1;
			Wln(Palindrome(n, IntToStr(10 ** m + k - 1)));
		end;
	end;
end.
