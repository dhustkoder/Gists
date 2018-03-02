var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const n = parseInt(lines[0]);

console.log(parseInt(n / (60 * 60)) + ':' + parseInt((n / 60) % 60)  +  ':' + parseInt(n % 60));

