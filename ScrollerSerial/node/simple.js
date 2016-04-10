var handleRequest = function (request, response) {
  response.writeHead(200, {'Content-Type': 'text/plain'});
  response.end('Hello World\n');
};

var http = require('http');
var server = http.createServer(handleRequest);
server.listen(8080);
