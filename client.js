var net = require('net');

var HOST = 'localhost';
var PORT = 1234;

var client = new net.Socket();

client.connect(PORT, HOST, function() {
    console.log('Client connected to: ' + HOST + ':' + PORT);
    // Write a message to the socket as soon as the client is connected, the server will receive it as message from the client
    client.write('Hello World!');

    // var stdin = process.openStdin();

    process.stdin.setEncoding('utf8');

    process.stdin.on('readable', () => {
      const chunk = process.stdin.read();
      if (chunk !== null) {
        // process.stdout.write(`data: ${chunk}`);
        client.write(chunk.toString().trim());
      }
    });
});

client.on('data', function(data) {
    console.log('Client received: ' + data);
     if (data.toString().endsWith('exit')) {
       client.destroy();
       process.exit();
    }
});

// Add a 'close' event handler for the client socket
client.on('close', function() {
    console.log('Client closed');
});

client.on('error', function(err) {
    console.error(err);
});
