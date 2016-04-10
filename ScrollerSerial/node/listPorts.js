var serialport = require('serialport');
var SerialPort = serialport.SerialPort;
 
serialport.list(function (err, ports) {
  ports.forEach(function(port) {
    console.log(port.comName);
  });
});
