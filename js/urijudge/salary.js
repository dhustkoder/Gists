var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const number = parseInt(lines[0]);
const salaryPerHour = parseInt(lines[1]);
const workedHours = parseFloat(lines[2]);

console.log('NUMBER =', number);
console.log('SALARY = U$', (salaryPerHour * workedHours).toFixed(2));


