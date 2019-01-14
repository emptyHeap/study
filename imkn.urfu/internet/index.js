const express = require('express');
const fs = require('fs-extra');
const {stripIndents} = require('common-tags');
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: true}));
app.use((req, res, next) => {
  console.log(req.originalUrl);
  console.log(req.method);
  console.log(req.params);
  console.log(req.query);
  console.log(req.body);

  next();
});

// http://localhost:8000/kakoy-tp/put?name=something&color=red
//
// GET /kakoy-tp/put?name=something&color=red HTTP/1.1
//
// Host:localhost:8000
// Content-Type: Application/text
//
// {
//  "chtoto": "toto"
// }
app.post('/cats', async(req, res) => {
  const {name, age, weight, color} = req.body;
  const fileName = `cats/${name}`;

  if (await fs.exists(fileName)) {
    res.send(409);
  } else {
    await fs.writeFile(fileName, stripIndents`
      name: ${name}
      age: ${age}
      weight: ${weight}
      color: ${color}
    `);

    res.send(200);
  }

});

app.get('/cats', async(req, res) => {
  const {name} = req.query;
  const fileName = `cats/${name}`;

  if (!fileName) {
    const files = await fs.readdir();
    const result = {};

    for (let file of files) {
      const data = await fs.readFile(file);
      result[file] = data;
    }

    res.send(200, result);
  } else if (!await fs.exists(fileName)) {
    res.send(404);
  } else {
    const info = await fs.readFile(fileName);

    res.send(200, info);
  }
});


app.use(express.static('public'));

app.listen(8000, () => console.log('server started'));
