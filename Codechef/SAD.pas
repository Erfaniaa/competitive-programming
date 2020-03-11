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
	TArr = arr [1..100] of Long;

func GetMax(A: TArr; i, j: Long): Long;
be
	if i = j th
  	exit(A[i]);
  if j - i = 1 th
  	exit(Max(A[i], A[j]));
  if j - i = 2 th
  	exit(Max(A[i], Max(A[i + 1], A[i + 2])));
  exit(Max(GetMax(A, i, (i + j) div 2), GetMax(A, (i + j) div 2 + 1, j)));
en;

func GetMin(A: TArr; i, j: Long): Long;
be
	if i = j th
  	exit(A[i]);
  if j - i = 1 th
  	exit(Min(A[i], A[j]));
  if j - i = 2 th
  	exit(Min(A[i], Min(A[i + 1], A[i + 2])));
  exit(Min(GetMin(A, i, (i + j) div 2), GetMin(A, (i + j) div 2 + 1, j)));
en;

var
	m, n, i, j: LongInt;
  A, B: arr [1..100] of TArr;
  Mins, Maxs: Tarr;

begin
	r(m, n);
  for i := 1 to m do
  	for j := 1 to n do
    be
	  	r(A[i, j]);
      B[j, i] := A[i, j];
    en;
  for i := 1 to n do
  be
  	Maxs[i] := GetMax(B[i], 1, m);
    //Wln('Maxs ', i, ': ', Maxs[i]);
  en;
  for i := 1 to m do
  be
    Mins[i] := GetMin(A[i], 1, n);
    //Wln('Mins ', i, ': ', Mins[i]);
  en;
  for i := 1 to m do
  	for j := 1 to n do
    	if A[i, j] = Maxs[j] th
      	if A[i, j] = Mins[i] th
        be
        	Wln(A[i, j]);
          exit;
        en;
  Wln('GUESS');
end.