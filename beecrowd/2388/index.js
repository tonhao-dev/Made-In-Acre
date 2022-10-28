var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

lines.shift();

console.log(lines.reduce((total, line) => {
  if (line.length === 0) return total

  const [intervalo, velocidade] = line.split(' ');
  return Number(intervalo) * Number(velocidade) + total
}, 0))