var QuadNode = require("./addons/addon")

console.log("hello");

var bound = {};
bound.minx = 1;
bound.miny = 2;
bound.maxx = 3;
bound.maxy = 4;

console.log(QuadNode);
var quadnode = new QuadNode.QuadNode(bound)
console.log("check: " + quadnode.check().halfWidth)
