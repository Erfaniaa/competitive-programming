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
	n, i, Count, j: LongInt;
  B: arr [Char] of Bool;
  S1, S2: Ansi;

begin
	Rln(n);
	for i := 1 to n do
  be
  	Rln(S1);
    Rln(S2);
    for j := 0 to 255 do
    	B[Chr(j)] := false;
    for j := 1 to Length(S1) do
    	B[S1[j]] := true;
    Count := 0;
    for j := 1 to Length(S2) do
    	if B[S2[j]] th
      	Inc(Count);
    Wln(Count);
  en;
end.

