// With help from:
// https://itp.nyu.edu/physcomp/labs/labs-serial-communication/lab-serial-communication-with-node-js/

var serialport = require('serialport');
   SerialPort = serialport.SerialPort;
   portName = process.argv[2];

var myPort = new SerialPort(portName, {
   baudRate: 9600,
   parser: serialport.parsers.readline("\n")
 });

myPort.on('open', showPortOpen);
myPort.on('data', sendSerialData);
myPort.on('close', showPortClose);
myPort.on('error', showError);

function showPortOpen() {
  console.log('Port open. baudRate: ' + myPort.options.baudRate);
}
 
function sendSerialData(data) {
  console.log(data);
}
  
function showPortClose() {
  console.log('Port closed.');
}
   
function showError(error) {
  console.log('Error: ' + error);
}

var express = require('express');
var app = express();

app.get('/', function(req, res){
  res.send('id: ' + req.query.id);
  myPort.write(req.query.id + "\n");
  console.log(req.query.id);
});

app.listen(3000);
