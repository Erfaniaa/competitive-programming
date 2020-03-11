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
	n, i, a, j, b, c: LongInt;
  Bl: arr [1..1000000] of Bool;

begin
	r(n);
  Bl[1] := true;
  for i := 2 to 1000000 do
  	if not Bl[i] th
    	for j := 2 to 1000000 div i do
      	Bl[j * i] := true;
  //1
  for a := 2 to 9 do
		if not Bl[a] th
      if a >= n th
      be
      	Wln(a);
        exit;
      en;
  //3
  for b := 1 to 9 do
  	for a := 0 to 9 do
    	if not Bl[100 * b + 10 * a + b] th
        if 100 * b + 10 * a + b >= n th
        be
        	Wln(100 * b + 10 * a + b);
          exit;
        en;
  //5
  for c := 1 to 9 do
  	for b := 0 to 9 do
    	for a := 0 to 9 do
	    	if not Bl[10000 * c + 1000 * b + 100 * a + 10 * b + c] th
          if 10000 * c + 1000 * b + 100 * a + 10 * b + c >= n th
          be
          	Wln(10000 * c + 1000 * b + 100 * a + 10 * b + c);
            exit;
          en;
  Wln(1003001);
end.

