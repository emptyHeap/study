window.onload = () => {
  stringField = document.getElementById('string');
  substringField = document.getElementById('substring');
  resultField = document.getElementById('result');

  naiveSearchButton = document.getElementById('naive-search');
  hashRabinKarpButton = document.getElementById('rabin-search');
  hashSummButton = document.getElementById('summ-search');
  powerSearchButton = document.getElementById('power-search');

  naiveSearchButton.onclick = () => {
    resultField.value = naiveSearch(stringField.value, substringField.value);
  }
  hashRabinKarpButton.onclick = () => {
    resultField.value = hashRabinKarpSearch(stringField.value, substringField.value);
  }
}


function naiveSearch(string, substring) {
  main_string_loop:
  for (i = 0; i < string.length - substring.length; i++) {
    for (j = 0; j < substring.length; j++) {
      if (string.charAt(i+j) !== substring.charAt(j)) {
        continue main_string_loop;
      }
    }
    return i;
  }
  return -1;
}

function hashRabinKarpSearch(string, substring) {
  if (string.length < substring.length) { return -1; }

  result = [];
  const p = 257;
  powers = [1];
  for (i = 1; i < string.length; i++) {
    powers[i] = powers[i-1] * p;
  }

  function prefixHashes(string) {
    hashes = [];
    hashes.push(string.charCodeAt(0));
    for (i = 1; i < string.length; i++) {
      hashes.push(hashes[i - 1] + powers[i] * string.charCodeAt(i));
    }
    return hashes;
  }

  function equals(substringHash, l, r, prefixHashes) {
    let tt = (prefixHashes[r] - (l === 0 ? 0 : prefixHashes[l]) );
    let ttt = substringHash * powers[l];
    console.log(tt, ttt);
    return substringHash * powers[l] === prefixHashes[r] - (l === 0 ? 0 : prefixHashes[l - 1])
  }

  substringHash = prefixHashes(substring)[substring.length - 1];
  superstringHashes = prefixHashes(string);

  for (l = 0; l <= string.length - substring.length; l++) {
    let r = l + substring.length - 1;
    if (equals(substringHash, l, r, superstringHashes)) {
      console.log(l,r);
      result.push(l);
    }
  }

  return result;
}
