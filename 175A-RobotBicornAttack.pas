/*
	SubmissionId	:	5600856
	ContestId	:	175
	Index	:	A
	ProblemName	:	Robot Bicorn Attack
	ProblemTags	:	['brute force', 'implementation']
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

uses Classes, SysUtils, StrUtils, Math;

var
    s, ca, cb, cc: AnsiString;
  a, b, c: Long;
  L, sa, sb, sc: Int64;
    M: Int64;

begin
    Rln(s);
  L := Length(s);
  if l < 3 th
  be
    Wln(-1);
    exit;
  en;
  if s = '000' th
  be
    Wln(0);
    exit;
  en;
  {if s[1] = '0' th
  be
    Wln(-1);
    exit;
  en;}
  M := -1;
  for a := 1 to Min(7, L - 2) do
  be
    ca := Copy(s, 1, a);
    if ca <> '0' th
        if ca[1] = '0' th
        brk;
    sa := StrToInt(ca);
    if a = 7 th
        if sa > 1000000 th
        brk;
    for b := a + 1 to Min(a + 7, L - 1) do
    be
        cb := Copy(s, a + 1, b - (a + 1) + 1);
        if cb <> '0' th
        if cb[1] = '0' th
            brk;
      sb := StrToInt(cb);
      if Length(cb) = 7 th
        if sb > 1000000 th
                brk;
      //
        cc := Copy(s, b + 1, l);
        //W(a, ' ', b, ': ');
        //Wln(ca, ' ', cb, ' ', cc);
        if cc <> '0' th
            if cc[1] = '0' th
            continue;
        if Length(cc) > 7 th
            continue;
        sc := StrToInt(cc);
        if Length(cc) = 7 th
          if sc > 1000000 th
            continue;
        M := Max(M, sa + sb + sc);
    en;
    en;
  Wln(M);
end.