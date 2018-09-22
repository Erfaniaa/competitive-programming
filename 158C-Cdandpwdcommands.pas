/*
	SubmissionId	:	5600811
	ContestId	:	158
	Index	:	C
	ProblemName	:	Cd and pwd commands
	ProblemTags	:	['*special', 'data structures', 'implementation']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

{$MACRO ON}
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
    S: Ansi;
    i, n, j, p, len, k: Long;
    w: arr [1..200] of string;
    Path: arr [1..50 * 110] of string;

begin
    Rln(n);
    for i := 1 to n do
    begin
        Readln(S);
        if S = 'pwd' th
        be
            for k := 1 to len do
                write('/' + Path[k]);
            Wln('/');
            continue;
        en;
        delete(S, 1, 3);
        if S[1] = '/' th
        be
            w[1] := '/';
            Len := 0;
            delete(S, 1, 1);
        en;
        j := 0;
        while (true) do
        be
            p := Pos('/', s);
            if p = 0 th
                brk;
            Inc(j);
            w[j] := Copy(S, 1, p - 1);
            delete(S, 1, p);
        en;
        Inc(j);
        w[j] := S;
        S := '';
        for k := 1 to j do
        begin
            if w[k] = '/' th
            be
                len := 0;
                continue;
            en;
            if w[k] = '..' th
            be
                Dec(len);
                continue;
            en;
            Inc(Len);
            Path[Len] := w[k];
        end;
    end;
end.