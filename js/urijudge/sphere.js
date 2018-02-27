var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const r3 = Math.pow(parseFloat(lines[0]), 3);
console.log('VOLUME =', ((4/3.0) * Math.PI * r3).toFixed(3));

