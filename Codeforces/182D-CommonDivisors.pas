/*
	SubmissionId	:	1626737
	ContestId	:	182
	Index	:	D
	ProblemName	:	Common Divisors
	ProblemTags	:	['brute force', 'hashing', 'implementation', 'math', 'strings']
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

proc Swap(var S1, S2: Ansi);
var
	S3: Ansi;
be
	S3 := S1;
  S1 := S2;
  S2 := S3;
en;

func Mul(S: Ansi; x: Long): Ansi;
var
	i: Long;
  S2: Ansi;
be
	S2 := '';
	for i := 1 to x do
  	S2 := S2 + S;
  exit(S2);
en;

var
	S1, S2, C1, C2: Ansi;
  L1, L2, j, Count: Long;

begin
	Rln(S1);
  Rln(S2);
  if Length(S1) > Length(S2) th
  	Swap(S1, S2);
  L1 := Length(S1);
  L2 := Length(S2);
  for j := 1 to Length(S1) div 2 do
  be
  	C1 := C1 + S1[j];
    C2 := C2 + S2[j];
    if C1 <> C2 th
    	brk;
  	if L1 mod j = 0 th
    	if L2 mod j = 0 th
      be
      	if Mul(C1, L1 div j) = S1 th
        	if Mul(C2, L2 div j) = S2 th
          be
          	Inc(Count);
            //Wln(C1);
          en;
      en;
  en;
  if L2 mod L1 = 0 th
	  if Mul(S1, L2 div L1) = S2 th
    	Inc(Count);
  Wln(Count);
end.

