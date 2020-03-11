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

func Compare(A, B: Pointer): Long;
be
	if Long(A) > Long(B) th
  	exit(-1);
  if Long(A) = Long(B) th
  	exit(0);
  exit(1);
en;

var
	d: arr [0..100, 0..100] of Int64;

func C(n, r: Long): Int64;
var
	x: Int64;
be
	if (r = 0) or (r = n) th
  	x := 1
  el
  	x := C(n - 1, r - 1) + C(n - 1, r);
  if x > 0 th
  be
  	d[n, r] := x;
    d[n, n - r] := x;
  en;
 	exit(d[n, r]);
en;

var
	n, i, j, a, k: LongInt;
  x: Int64;
  L: TFPList;
  c1, c2: arr [1..100] of Long;

begin
	r(n);
  L := TFPList.Create;
  for i := 1 to n do
  be
  	L.Clear;
  	for j := 1 to 11 do
    be
    	r(a);
      L.Add(Pointer(a));
    en;
    L.Sort(@Compare);
    r(k);
    FillDWord(c1, 100, 0);
    FillDWord(c2, 100, 0);
    for j := 0 to 10 do
    	Inc(c1[Long(l[j])]);
    for j := 0 to k - 1 do
    	Inc(c2[Long(l[j])]);
    x := 1;
    for j := 1 to 100 do
    	if c2[j] < c1[j] th
	    	x := x * C(c1[j], c2[j]);
    Wln(x);
  en;
end.

