/*
	SubmissionId	:	5600715
	ContestId	:	131
	Index	:	A
	ProblemName	:	cAPS lOCK
	ProblemTags	:	['implementation', 'strings']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

var
    i: LongInt;
    S: Ansistring;
begin
    Readln(S);
    if (S = UpCase(S)) or ((S[1] = LowerCase(S[1])) and (Copy(S, 2, Length(S)) = UpCase(Copy(S, 2, Length(S))))) then
    begin
        for i := 1 to Length(S) do
            if LowerCase(S[i]) = S[i] then
                write(UpCase(S[i]))
            else
                write(LowerCase(s[i]));
        Writeln;
    end
    else
        Writeln(S);
end.