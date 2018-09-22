/*
	SubmissionId	:	5600784
	ContestId	:	158
	Index	:	B
	ProblemName	:	Taxi
	ProblemTags	:	['greedy', 'implementation']
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
{$define th:=then}

var
    b: arr [1..4] of Long;
    n, i, a, m, j, k, num, mn, t: long;
    
be
    r(n);
    for i := 1 to n do
    be
        r(a);
        Inc(b[a]);
    en;
    for i := 1 to n + 1 do
    begin
        //Wln(b[1], ' ', b[2], ' ', b[3], ' ', b[4]);
        t := 0;
        if (b[1] = 0) th
            if (b[2] = 0) th
                if (b[3] = 0) th
                    if (b[4] = 0) th
                        break;
        for k := 1 to 4 do
        begin
            //Wln(b[1], ' ', b[2], ' ', b[3], ' ', b[4]);
            mn := 10;
            num := -1;
            for j := 4 downto 1 do
                if b[j] > 0 then
                begin
                    m := 4 - (t + j);
                    if m >= 0 then
                        if mn > m then
                        begin
                            mn := m;
                            num := j;
                            if m = 0 th
                                brk;
                        end;
                end;
            if num > 0 then
            begin
                //Wln(t, ' ', num);
                Inc(t, num);
                Dec(b[num]);
                if t = 4 then
                    break;
            end;
            //Wln(b[1], ' ', b[2], ' ', b[3], ' ', b[4]);
            //Wln(t);
        end;
        //Wln(b[1], ' ', b[2], ' ', b[3], ' ', b[4]);
        //Wln(t);
    end;
    Wln(i - 1);
    //Wln(b[1], ' ', b[2], ' ', b[3], ' ', b[4]);
en.