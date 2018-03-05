var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var numsStr = input.split(' ');
var nums = [];

numsStr.map((x) => {
	if (parseInt(x) != 'NaN')
		nums.push(parseInt(x));
});

console.log(Math.max.apply(null, nums).toString() + ' eh o maior');

