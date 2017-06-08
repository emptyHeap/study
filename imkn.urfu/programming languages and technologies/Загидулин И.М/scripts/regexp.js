function read(fileName)
{
	var fso = new ActiveXObject('Scripting.FileSystemObject');
	var stream = fso.OpenTextFile(fileName);

	var s = stream.ReadAll();
	
	stream.close();
	return s;
}

function write(fileName, str)
{
	var fso = new ActiveXObject("Scripting.FileSystemObject");
    var stream = fso.OpenTextFile(fileName, 2, true);

	var s = stream.Write(str);
	
	stream.close();
}


function findImages()
{
	var content = read("wiki.html");
	
	var re = /<img src="(.*?)"/gm;

	var arr = null;
	
	// global search
	while ((arr = re.exec(content)) != null)
	{
		// print result properties except 'input'
		for (var i in arr)
		{
			if (i == "input")
				continue;

			WSH.echo(i, ":", arr[i]);
		}
	}
}

function deleteAllTags()
{
	// replace any whitespace character with 'space'
	var content = read("wiki.html").replace(/\s+/gm, " ");

	// remove all script-tags
	content = content.replace(/<script.*?>.*?<\/script>/igm, "");

	// find body-tag
	var bodyStart = content.search(/<body.*?>.*?<\/body>/igm);

	WSH.echo(bodyStart);

	// extract body content
	var body = content.substring(bodyStart, RegExp.lastIndex);

	WSH.echo(body);

	// remove all tags from body
	var text = body.replace(/<.*?>/gm, " ");

	write("out.txt", text);
}


function snake_case_toCamelCase(str)
{
	function toUpperCamelCase(match)
	{
		return match.substring(1).toUpperCase();
	}

	return str.replace(/_./g, toUpperCamelCase);
}

function styleHyphenFormat(propertyName)
{
	function upperToHyphenLower(match)
	{
		return '-' + match.toLowerCase();
	}
	
	return propertyName.replace(/[A-Z]/g, upperToHyphenLower);
}

function splitByNumbers(str)
{
	var re = /\d+/g;

	var startIndex = 0;

	while (true)
	{
		var arr = re.exec(str);

		if (arr == null)
			break;

		WSH.echo(">", str.substring(startIndex, RegExp.index));
		WSH.echo(">", arr[0]);

		startIndex = RegExp.lastIndex;
	}

	WSH.echo(">", RegExp.rightContext);
}

findImages();

// deleteAllTags();

// WSH.echo(snake_case_toCamelCase("very_long_56_variable_name01"));

// WSH.echo(styleHyphenFormat("veryLongVariableName"));

// WSH.echo("123abc345def".split(/(\d+)));

// WSH.echo('Привет 1 мир. Предложение номер 2.'.split(/(\d+)/));

// splitByNumbers("xyz123abc345def");