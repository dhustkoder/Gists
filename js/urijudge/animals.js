var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');


const animalsMap = {
	'vertebrado': {
		'ave': {
			'carnivero': 'aguia',
			'onivoro': 'pomba'
		},
		'mamifero': {
			'onivoro': 'homem',
			'herbivero': 'vaca'
		}
	},
	'invertebrado': {
		'inseto': {
			'hematofago': 'pulga',
			'herbivoro': 'lagarta'
		},
		'anelideo': {
			'hematofago': 'sanguessuga',
			'onivoro': 'minhoca'
		}
	}
};


console.log(animalsMap[lines[0]][lines[1]][lines[2]]);

