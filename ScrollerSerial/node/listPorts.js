// With help from:
// https://itp.nyu.edu/physcomp/labs/labs-serial-communication/lab-serial-communication-with-node-js/

var serialport = require('serialport');
var SerialPort = serialport.SerialPort;
 
serialport.list(function (err, ports) {
  ports.forEach(function(port) {
    console.log(port.comName);
  });
});
