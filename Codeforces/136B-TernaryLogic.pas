/*
	SubmissionId	:	5600702
	ContestId	:	136
	Index	:	B
	ProblemName	:	Ternary Logic
	ProblemTags	:	['implementation', 'math']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

uses StrUtils;

var
    a, b, i, k: LongInt;
    S1, S2, S3: string;
    
begin
    read(a, b);
    if a = b then
    begin
        Writeln(0);
        exit;
    end;
    S1 := Dec2Numb(a, 20, 3);
    S2 := Dec2Numb(b, 20, 3);
    SetLength(S3, 20);
    for i := 1 to 20 do
    begin
        k := Ord(S2[i]) - Ord(S1[i]);
        if k < 0 then
            k := k + 3;
        S3[i] := Chr(48 + k);
    end;
    Writeln(Numb2Dec(S3, 3));
end.