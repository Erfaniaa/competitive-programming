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

type
	TBigNum = arr [1..200] of Int;

var
	Dy: arr [1..100] of TBigNum;

proc Add(var A: TBigNum; B: TBigNum);
var
	i: Int;
be
	for i := 1 to 160 do
  	A[i] := A[i] + B[i];
  for i := 2 to 160 do
  be
  	A[i] := A[i] + (A[i - 1] div 10);
    A[i - 1] := A[i - 1] mod 10;
  en;
en;

proc Multiply(var A: TBigNum; B: Int);
var
	i, ALen, x, j, Digit: Int;
  C, D: TBigNum;
be
	i := 160;
	while a[i] = 0 do
  	Dec(i);
  for j := 1 to 160 do
  be
   	C[j] := 0;
    D[j] := 0;
  en;
  ALen := i;
  for i := 1 to ALen do
  be
  	x := 1;
    J := 0;
  	while x <= b do
    be
    	Inc(j);
    	digit := (b div x) mod 10;
      C[i + j - 1] := Digit * A[i];
    	x := x * 10;
    en;
    Add(D, C);
    for j := 1 to 160 do
    	C[j] := 0;
  en;
  A := D;
en;

proc f(a: Int);
var
	X: TBigNum;
  i, j: Long;
be
	for j := 1 to 160 do
  	x[j] := 0;
	x[1] := 1;
	for i := 1 to a do
  be
  	Multiply(x, i);
    Dy[i] := x;
  en;
  i := 160;
  while x[i] = 0 do
  	Dec(i);
en;

var
	n, i, a, j, k: LongInt;
  x, y: TBigNum;

begin
	read(n);
  f(100);
  for i := 1 to n do
  be
  	r(a);
    j := 160;
    while Dy[a, j] = 0 do
    	Dec(j);
    for k := j downto 1 do
  		write(Dy[a, k]);
		Wln;
  en;
end.

