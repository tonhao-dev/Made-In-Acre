var input = require("fs").readFileSync("/dev/stdin", "utf8");
var lines = input.split("\n");

let soma = 0;
const dict = {
    0: 4,
    1: 2,
    2: 1,
};

while (lines.length > 0) {
    const piscada = lines.shift();

    if (piscada === "caw caw") {
        console.log(soma);
        soma = 0;
        continue;
    }

    for (var i = 0; i < piscada.length; i++) {
        if (piscada[i] !== "*") continue;
        soma += dict[i];
    }
}
