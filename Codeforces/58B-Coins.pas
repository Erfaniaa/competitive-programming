/*
	SubmissionId	:	5600719
	ContestId	:	58
	Index	:	B
	ProblemName	:	Coins
	ProblemTags	:	['greedy']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

var
    m, n: LongInt;
begin
    read(n);
    write(n, ' ');
    while n <> 1 do
    begin
        for m := n div 2 downto 1 do
            if n mod m = 0 then
            begin
                n := m;
                write(m, ' ');
            end;
    end;
end.