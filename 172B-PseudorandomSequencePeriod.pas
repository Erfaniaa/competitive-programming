/*
	SubmissionId	:	5600833
	ContestId	:	172
	Index	:	B
	ProblemName	:	Pseudorandom Sequence Period
	ProblemTags	:	['implementation', 'number theory']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

var
    R: array [0..500000] of QWord;
  A, B, M, x: QWord;
  i: LongInt;
begin
    read(A, B, M, R[0]);
  A := A mod M;
  B := B Mod M;
  R[0] := R[0] mod M;
  for i := 1 to 500000 do
        R[i] := (A * R[i - 1] + B) mod M;
  x := R[250000];
  for i := 250001 to 500000 do
    if R[i] = x then
    begin
        Writeln(i - 250000);
      exit;
    end;
  Writeln(0);
end.