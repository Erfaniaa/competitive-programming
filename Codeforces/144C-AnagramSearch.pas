/*
	SubmissionId	:	5600648
	ContestId	:	144
	Index	:	C
	ProblemName	:	Anagram Search
	ProblemTags	:	['implementation', 'strings']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

var
    S1, S2: AnsiString;
    i, j: LongInt;
    Count, L1, L2: QWord;
    b: Boolean;
    c1, c2: array ['a'..'z'] of QWord;
    ch: Char;
begin
    Readln(S1);
    Readln(S2);
    L1 := Length(S1);
    L2 := Length(S2);
    if L1 < L2 then
        Writeln(0)
    else
    begin
        for j := 1 to L2 do
        begin
            c2[S2[j]] := c2[S2[j]] + 1;
            if j <= L1 then
                if S1[j] <> '?' then
                    c1[S1[j]] := c1[S1[j]] + 1;
        end;
        b := true;
        for ch := 'a' to 'z' do
            if c1[ch] > c2[ch] then
            begin
                b := false;
                break;
            end;
        if b then
            Count := Count + 1;
        for i := 2 to L1 - L2 + 1 do
        begin
            if S1[i - 1] <> '?' then
                c1[S1[i - 1]] := c1[S1[i - 1]] - 1;
            if S1[i - 1 + L2] <> '?' then
                c1[S1[i - 1 + L2]] := c1[S1[i - 1 + L2]] + 1;
            b := true;
            for ch := 'a' to 'z' do
                if c1[ch] > c2[ch] then
                begin
                    b := false;
                    break;
                end;
            if b then
                Count := Count + 1;
        end;
        Writeln(Count);
    end;
end.