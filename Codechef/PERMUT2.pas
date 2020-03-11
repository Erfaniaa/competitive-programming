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
	n, i, a, j: LongInt;
  f: Bool;
  b: arr [1..100000] of Long;

begin
	while true do
	begin
		r(a);
    if a = 0 th
    	exit;
    for j := 1 to a do
    be
    	r(b[j]);
      if b[j] = 0 th
      	exit;
    en;
    f := true;
    for j := 1 to a do
    	if b[b[j]] <> j th
      be
      	f := false;
        brk;
      en;
    if f th
    	Wln('ambiguous')
    else
    	Wln('not ambiguous');
	end;
end.

