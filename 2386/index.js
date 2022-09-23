const input = require('fs').readFileSync('stdin', 'utf8');
const lines = input.split('\n').map(n => Number(n));

const areaTelescopio = lines.shift();
const FOTONS_PERCEBIDOS_CEREBRO = 40000000

lines.shift();

console.log(lines.reduce((countEstrelasPercebidas, fotonsDaEstrela) => fotonsDaEstrela * (areaTelescopio) >= FOTONS_PERCEBIDOS_CEREBRO ? countEstrelasPercebidas + 1 : countEstrelasPercebidas, 0))