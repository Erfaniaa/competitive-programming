/*
	SubmissionId	:	5600760
	ContestId	:	148
	Index	:	C
	ProblemName	:	Terse princess
	ProblemTags	:	['constructive algorithms', 'greedy']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

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
    n, a, b, i, k: LongInt;
    S: QWord;
    Bl : Bool;

begin
    r(n, a, b);
    if (n > 1) then
    be
        if b = 0 then
        be
            if a + 2 > n then
                Bl := true;
        en
        el
            if a + b + 1 > n then
                Bl := true;
        if Bl then
        be
            Writeln(-1);
            exit;
        en;
    en;
    write('1 ');
    if n = 1 then
        exit;
    S := 1;
    if b = 0 then
    be
        write('1 ');
        k := 1;
    en;
    for i := 2 to b + 1 do
    be
        write(S + 1, ' ');
        S := S + (S + 1);
    en;
    S := S div 2 + 1;
    for i := 1 to a do
        write(S + i, ' ');
    for i := 1 to n - a - b - 1 - k do
        write('1 ');
    Writeln;
end.