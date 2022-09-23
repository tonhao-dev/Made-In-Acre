var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

const casos_teste = Number(lines.shift());

for (let i = 0; i < casos_teste; i++) {
  const no_inicio = Number(lines.shift());
  let grafo = {};

  const [vertices, arestas] = lines.shift().split(' ').map(n => Number(n));

  for (let j = 0; j < arestas; j++) {
    const [origem, destino] = lines.shift().split(' ').map(n => Number(n));

    if (!grafo.hasOwnProperty(origem)) {
      grafo[origem] = new Set([destino]);
    } else {
      grafo[origem].add(destino);
    }
    if (!grafo.hasOwnProperty(destino)) {
      grafo[destino] = new Set([origem]);
    } else {
      grafo[destino].add(origem);
    }
  }

  console.log(Object.values(grafo).reduce((total, set) => set.size + total, 0));
}