var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split(' ');

const hotdogs = parseInt(lines[0]);
const persons = parseInt(lines[1]);

console.log((hotdogs / persons).toFixed(2))


