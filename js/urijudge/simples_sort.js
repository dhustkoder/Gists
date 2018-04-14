var input = require('fs').readFileSync('/dev/stdin', 'utf8').split(' ');
var nums = input.map(i => parseInt(i));
var sortedNums = nums.slice();

sortedNums.sort((x, y) => x > y).forEach(i => console.log(i));
console.log('\n');
nums.forEach(i => console.log(i));


