// https://www.beecrowd.com.br/judge/pt/problems/view/1466
// Arvore binaria de busca

class Node {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
    this.viewed = false;
  }
}

class BinarySearchTree {
  constructor() {
    this.root = null;
  }

  insert(data) {
    var newNode = new Node(data);

    this.root === null ? this.root = newNode : this.insertNode(this.root, newNode)
  }

  insertNode(node, newNode) {
    // if the data is less than the node
    // data move left of the tree
    if (newNode.data < node.data) {
      // if left is null insert node here
      if (node.left === null)
        node.left = newNode;
      else

      // if left is not null recur until
      // null is found
        this.insertNode(node.left, newNode);
    }

    // if the data is more than the node
    // data move right of the tree
    else {
      // if right is null insert node here
      if (node.right === null)
        node.right = newNode;
      else

      // if right is not null recur until
      // null is found
        this.insertNode(node.right, newNode);
    }
  }

  bsf(node) {
    const queue = [];
    const path = [];

    queue.push(node);

    while (queue.length > 0) {
      const currentNode = queue.shift();
      if (currentNode.viewed) continue;

      currentNode.viewed = true;
      path.push(currentNode.data);


      !!currentNode.left && queue.push(currentNode.left);
      !!currentNode.right && queue.push(currentNode.right);
    }

    return path;
  }
}

var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

const casosTeste = Number(lines.shift());

for (let i = 0; i < casosTeste; ++i) {
  const tree = new BinarySearchTree();
  const numNos = lines.shift();

  lines.shift().split(' ').forEach(no => tree.insert(Number(no)));

  console.log(`Case ${i + 1}:`);
  console.log(...tree.bsf(tree.root));
  i !== casosTeste - 1 && console.log();
}

console.log();