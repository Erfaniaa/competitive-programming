uses Math;

var
	t, n, i: LongInt;
begin
	read(t);
	for i := 1 to t do
	begin
		read(n);
		Writeln(Trunc(sqrt(n)));
	end;
end.
