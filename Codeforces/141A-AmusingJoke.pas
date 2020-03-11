/*
	SubmissionId	:	5600755
	ContestId	:	141
	Index	:	A
	ProblemName	:	Amusing Joke
	ProblemTags	:	['implementation', 'sortings', 'strings']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

var
    S1, S2, S3: string;
    i: LongInt;
    B: Boolean;
    Ch, Ch2: array ['A'..'Z'] of LongInt;
    C: Char;
    
begin
    Readln(S1);
    Readln(S2);
    Readln(S3);
    for i := 1 to Length(S1) do
        Inc(Ch[S1[i]]);
    for i := 1 to Length(S2) do
        Inc(Ch[S2[i]]);
    for i := 1 to Length(S3) do
        Inc(Ch2[S3[i]]);
    for c := 'A' to 'Z' do
        if Ch2[c] <> Ch[c] then
        begin
            B := true;
            break;
        end;
    if not B then
        Writeln('YES')
    else
        Writeln('NO');
end.