// Document Object Model

async function addCat() {
  const addCatForm = document.getElementById('add-cat-form');

  const catName = addCatForm.children.name.value;
  const catWeight = addCatForm.children.weight.value;
  const catAge = addCatForm.children.age.value;
  const catColor = addCatForm.children.color.value;

  const catInfo = {
    name: catName,
    weight: catWeight,
    age: catAge,
    color: catColor,
  };

  const Info = await sendRequest('POST', '/cats', catInfo);

  alert(Info);
}

async function getCat() {
  const getCatForm = document.getElementById('get-cat-form');

  const catName = getCatForm.children.name.value;
  const catInfo = await sendRequest('GET', `/cats?name=${catName}`);

  //alert(catInfo);
  document.getElementById('cat-info').innerText = catInfo;
}

////////////////////////////////////////////////////////////////////////
function sendRequest(method, path, data) {
  const promise = new Promise((resolve, reject) => {
    const xmlRequest = new XMLHttpRequest();

    xmlRequest.onreadystatechange = function() {
      if (this.readyState == 4) {
        if (this.status === 200) {
          resolve(xmlRequest.responseText);
        } else {
          reject(this.status);
        }
      }
    }

    xmlRequest.open(method, path, true);
    xmlRequest.setRequestHeader('Content-Type', 'application/json');
    xmlRequest.send(JSON.stringify(data));
  });

  return promise;
}
