var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const pi = 3.14159;
const r3 = Math.pow(parseFloat(lines[0]), 3).toFixed(5);
console.log('VOLUME =', ((4.0/3.0) * pi * r3).toFixed(3));

