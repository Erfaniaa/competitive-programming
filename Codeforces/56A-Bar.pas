/*
	SubmissionId	:	5600694
	ContestId	:	56
	Index	:	A
	ProblemName	:	Bar
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	FPC
	Verdict	:	OK
*/

uses StrUtils, SysUtils;
const
    S2: string = ' ABSINTH BEER BRANDY CHAMPAGNE GIN RUM SAKE TEQUILA VODKA WHISKEY WINE';
var
    S: string;
    N, i, j: LongInt;
begin
    Readln(n);
    for i := 1 to n do
    begin
        Readln(S);
        if S[1] in ['0'..'9'] then
        begin
            S := AddChar('0', S, 2);
            //Writeln(S);
            if S < AddChar('0', '18', Length(S)) then
            begin
                Inc(j);
                //Writeln(AddChar('0', '18', Length(S)));
            end;
        end
        else
            if Pos(' ' + S, S2) > 0 then
                Inc(j);
        //Writeln(j);
    end;
    Writeln(j);
end.