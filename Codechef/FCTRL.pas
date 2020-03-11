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

var
	n, i, a, b, x: LongInt;

begin
	r(n);
  for i := 1 to n do
	be
    r(a);
    b := 0;
    x := 5;
    while x <= a do
    be
    	b := b + a div x;
      x := x * 5;
    en;
  	Wln(b);
  en;
end.