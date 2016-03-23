const THREE = require('three');

let scene = new THREE.Scene();

let vertices = [
  new THREE.Vector3(1.0, 0.0, 0.0),  // a: 0
  new THREE.Vector3(0.0, 1.0, 0.0),  // b: 1
  new THREE.Vector3(-1.0, 0.0, 0.0), // c: 2
  new THREE.Vector3(0.0, -1.0, 0.0), // d: 3
  new THREE.Vector3(0.5, 0.0, 1.0),  // e: 4
  new THREE.Vector3(0.5, 0.5, 1.0),  // f: 5
  new THREE.Vector3(-0.5, 0.0, 1.0), // g: 6
  new THREE.Vector3(0.5, -0.5, 1.0), // h: 7
];

let faces = [
  // a-b-c-d
  new THREE.Face3(0, 1, 2),
  new THREE.Face3(2, 3, 0),
  // a-e-h-d
  new THREE.Face3(0, 4, 7),
  new THREE.Face3(7, 3, 0),
  // d-h-g-c
  new THREE.Face3(3, 7, 6),
  new THREE.Face3(6, 2, 3),
  // c-b-f-g
  new THREE.Face3(2, 1, 5),
  new THREE.Face3(5, 6, 2),
  // b-a-e-f
  new THREE.Face3(1, 0, 4),
  new THREE.Face3(4, 5, 1),
  // e-f-g-h
  new THREE.Face3(4, 5, 6),
  new THREE.Face3(6, 7, 4),
];

let truncPyramidGeometry = new THREE.Geometry();
truncPyramidGeometry.vertices = vertices;
truncPyramidGeometry.faces = faces;

let wireframe = new THREE.MeshBasicMaterial({wireframe: true});
let brown = new THREE.MeshBasicMaterial({color: 0xD47629});

let truncPyramid = new THREE.Mesh(truncPyramidGeometry, wireframe);
let truncPyramidPink = new THREE.Mesh(truncPyramidGeometry, brown);
cubePink.translateZ(2);

scene.add(truncPyramid);
scene.add(truncPyramidPink);

let axes = new THREE.AxisHelper(1.5);
scene.add(axes);

module.exports = scene;
