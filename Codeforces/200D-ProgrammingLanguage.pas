/*
	SubmissionId	:	1828537
	ContestId	:	200
	Index	:	D
	ProblemName	:	Programming Language
	ProblemTags	:	['binary search', 'brute force', 'expression parsing', 'implementation']
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

type
	TProc = record
  	S: string;
    P: arr [1..1000] of string;
    PCount: Long;
  en;
  TVar = record
  	S: string;
    T: string;
  en;

var
	n, i, WC, m, o, k, j, Count: LongInt;
  S: Ansi;
  B: Bool;
  Procs: arr [1..1000] of TProc;
  Proc2: TProc;
  Vars: arr [1..1000] of TVar;

func TypeOf(s: string): string;
var
	L: Long;
be
	for L := 1 to m do
  	if Vars[L].s = s th
    	exit(Vars[L].T);
en;

begin
	rln(n);
  for i := 1 to n do
  be
    Rln(S);
    Procs[i].S := ExtractWord(2, S, StdWordDelims);
    WC := WordCount(S, StdWordDelims) - 2;
    for j := 1 to WC do
    	Procs[i].P[j] := ExtractWord(j + 2, S, StdWordDelims);
    Procs[i].PCount := WC;	
    //Wln(Procs[i].S);
    //for j := 1 to WC do
    //	Wln(Procs[i].P[j]);
  en;
  rln(m);
  for i := 1 to m do
  be
  	Rln(S);
    Vars[i].T := ExtractWord(1, S, StdWordDelims);
    Vars[i].S := ExtractWord(2, S, StdWordDelims);
    //Wln(Vars[i].T, ' ', Vars[i].S);
  en;
  Rln(o);
  //Wln(o);
  for i := 1 to o do
  be
  	//Wln(i);
  	Rln(S);
	  Proc2.S := ExtractWord(1, S, StdWordDelims);
    Proc2.PCount := WordCount(S, StdWordDelims) - 1;
    for j := 1 to Proc2.PCount do
    	Proc2.P[j] := TypeOf(ExtractWord(j + 1, S, StdWordDelims));
    //Wln(Proc2.S);
    //Wln(Proc2.PCount);
    //for j := 1 to Proc2.PCount do
    //	Wln(Proc2.P[j]);
    Count := 0;
    for j := 1 to n do
    be
    	B := true;
      //Wln(Procs[j].S);
    	if Proc2.S = Procs[j].S th
      be
      	if Proc2.PCount = Procs[j].PCount th
        be
        	for k := 1 to Proc2.PCount do
          	if not ((Proc2.P[k] = Procs[j].P[k]) or (Procs[j].P[k] = 'T')) th
            be
            	//Wln('Err: ', Procs[j].P[k]);
            	B := false;
              brk;
            en;
					if B th
		      	Inc(Count);
        en;
      en;
    en;
    Wln(Count);
  en;
end.