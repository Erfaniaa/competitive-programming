/*
	SubmissionId	:	5600753
	ContestId	:	131
	Index	:	B
	ProblemName	:	Opposites Attract
	ProblemTags	:	['implementation', 'math']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

var
    a, i, n: LongInt;
    S: QWord;
    C: array [-10..10] of QWord;
    
begin
    readln(n);
    for i := 1 to n do
    begin
        read(a);
        Inc(c[a]);
    end;
    for i := 1 to 10 do
    begin
        S := S + c[i] * c[-i];
        //Writeln(i, ' ', -i,': ', c[i], ' ', c[-i]);
    end;
    if c[0] > 0 then
        S := S + ((c[0] * (c[0] - 1)) div 2);
    Writeln(S);
end.