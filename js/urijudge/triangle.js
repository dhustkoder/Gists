var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split(' ');

const a = parseFloat(lines[0]);
const b = parseFloat(lines[1]);
const c = parseFloat(lines[2]);
console.log('a: ', a, '\n', 'b: ', b, '\n', 'c: ', c, '\n');
const s = (a + b + c) / 2.0;
console.log('S: ', s, '\n');
const area = ((a + b) * c) * 0.5;
console.log('AREA: ', area);

