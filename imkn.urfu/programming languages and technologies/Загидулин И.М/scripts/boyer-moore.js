var T = "abcdabc";
var m = T.length;

for (var l = 0; l < m; l++)
{
	var k = m - l - 1;

	var tail = T.substr(m - l, l);

	while (k > 0)
	{
		while (k > 0 && T.charAt(k - 1) == T.charAt(m - l - 1))
			k--;

		if (k < 1)
			break;
		
		if (T.substr(k, l) == tail)
			break;
		
		k--;
	}

	for (var i = 0; i < l; i++)
	{
		if (T.substr(0, l - i) == tail.substring(i, l))
			break;
	}

	k -= i;

	WSH.echo(l, "->", k + 1);
}