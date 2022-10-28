var input = require("fs").readFileSync("entrada", "utf8");
var lines = input.split("\n");

const a = Number.parseInt(lines[0]);
const b = Number.parseInt(lines[1]);

console.log("X =  ", a + b);
