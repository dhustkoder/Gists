var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');
const pi = (Math.PI).toFixed(5);
const r = parseFloat(lines[0]).toFixed(2);
console.log('A=' + (Math.pow(r, 2) * pi).toFixed(4));

