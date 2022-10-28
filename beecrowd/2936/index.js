var input = require('fs').readFileSync('stdin', 'utf8');
const [curupira, boitata, boto, mapinguari, iara] = input.split('\n').map(number => Number(number));

console.log((curupira * 300) + (boitata * 1500) + (boto * 600) + (mapinguari * 1000) + (iara * 150) + 225);
