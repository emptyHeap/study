const http = require('http');
const url = require('url');
const StringDecoder = require('string_decoder').StringDecoder;
const config = require('./config')

const endpoints = {};

const server = http.createServer(function(req, res) {

  // Get url and parse it
  const parsedUrl = url.parse(req.url, true);

  // Get path from url
  const path = parsedUrl.pathname;
  const {query} = parsedUrl;
  const trimedPath = path.replace(/^\/+|\/+$/g, '');
  const method = req.method.toLowerCase();
  const {headers} = req;

  const decoder = new StringDecoder('utf-8');
  var buffer = '';
  req.on('data', function(chunck) {
    buffer += decoder.write(chunck);
  })
  req.on('end', function() {
    buffer += decoder.end();

    const handler = !!router[trimedPath] ? router[trimedPath] : handlers.notFound;
    const data = {
      trimedPath,
      query,
      method,
      headers,
      payload: buffer
    };

    // Send response
    handler(data, function(statusCode = 200, payload = '') {
      const stringPayload = JSON.stringify(payload);

      res.setHeader('ContentType', 'application/json');
      res.statusCode = statusCode;
      res.end(stringPayload);

      console.log(`
        Return ${statusCode} code
        and ${stringPayload}
      `);
    });

    // Log some requirest info
    console.log(`
      User request received for path ${trimedPath}
      method ${method}
      with query ${JSON.stringify(query)}
      and headers ${JSON.stringify(headers)}
      and body ${buffer}
    `);
  });
});

server.listen(config.port, function() {
  console.log(`
    server is listening on ${config.port} port
    environment is ${config.envName}
  `);
});

// Define the handlers
class handlers {
  static sample(data, callback) {
    callback(418, {name: 'sample handler'});
  }

  static notFound(data, callback) {
    callback(404);
  }
}

// Define a request router
const router = {
  'sample': handlers.sample
}
