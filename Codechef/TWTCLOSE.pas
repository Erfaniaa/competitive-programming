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
	n, i, k, Count, a, j: LongInt;
  S: string;
  B: arr [1..1000] of Bool;

begin
	r(n);
	Rln(k);
  for i := 1 to k do
  be
  	Rln(S);
    if Copy(S, 1, 3) = 'CLI' th
    be
    	Delete(S, 1, 6);
	    a := StrToInt(S);
      if not B[a] th
      	Inc(Count)
      el
      	Dec(Count);
  	  B[a] := not B[a];
    en
    el
    be
    	for j := 1 to n do
      	B[j] := false;
      Count := 0;
    en;
    Wln(Count);
  en;
end.