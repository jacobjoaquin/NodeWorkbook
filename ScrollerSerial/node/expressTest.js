// From:
// http://stackoverflow.com/a/6913287

var express = require('express');
var app = express();

app.get('/', function(req, res){
	res.send('id: ' + req.query.id);
});

app.listen(3000);