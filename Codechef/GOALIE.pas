uses Math;

var
	t, n, i: LongInt;
begin
	read(t);
	for i := 1 to t do
	begin
		read(n);
		Writeln((n - (2 ** Trunc(log2(n)))) * 2 + 1);
	end;
end.
