uses StrUtils;

var
	m, n, i, j, c: LongInt;
  s: string;

begin
	read(n);
  for i := 1 to n do
  begin
		read(m);
    s := '';
    j := 0;
    c := 1;
    while j < m do
    begin
    	s := s + Chr(c + 96);
      Inc(c);
      if c = 27 then
      	c := 1;
      if (Length(s) > 1) then
      	if (s[Length(s)] > s[Length(s) - 1]) then
	      	Inc(j);
    end;
    Writeln(ReverseString(s));
  end;
end.