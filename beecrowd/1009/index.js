var input = require("fs").readFileSync("entrada", "utf8");
var lines = input.split("\n");

const nome = lines.shift();
const salarioFixo = parseFloat(lines.shift());
const valorVenda = parseFloat(lines.shift());

const resultado = salarioFixo + (15 / 100) * valorVenda;

console.log(`TOTAL = R$ ${resultado.toFixed(2)}`);
