class Nodo {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
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
}

var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');