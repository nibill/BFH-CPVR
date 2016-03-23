const THREE = require('three');

let scene = new THREE.Scene();

//    h-------g
//   /|      /|
//  / |     / |
// e--|----f  |
// |  d----|--c
// | /     | /
// a-------b

let vertices = [
    new THREE.Vector3(0.0, 0.0, 0.0), // a: 0
    new THREE.Vector3(1.0, 0.0, 0.0), // b: 1
    new THREE.Vector3(1.0, 1.0, 0.0), // c: 2
    new THREE.Vector3(0.0, 1.0, 0.0), // d: 3
    new THREE.Vector3(0.0, 0.0, 1.0), // e: 4
    new THREE.Vector3(1.0, 0.0, 1.0), // f: 5
    new THREE.Vector3(1.0, 1.0, 1.0), // g: 6
    new THREE.Vector3(0.0, 1.0, 1.0), // h: 7
];
let faces = [
    // a-b-f-e
    new THREE.Face3(0, 1, 5),
    new THREE.Face3(0, 5, 4),
    // b-c-g-f
    new THREE.Face3(1, 2, 5),
    new THREE.Face3(5, 2, 6),
    // c-d-h-g
    new THREE.Face3(2, 3, 6),
    new THREE.Face3(7, 6, 3),
    // d-a-e-h
    new THREE.Face3(3, 0, 4),
    new THREE.Face3(3, 4, 7),
    // e-f-g-h
    new THREE.Face3(4, 5, 6),
    new THREE.Face3(4, 6, 7),
    // a-d-c-b
    new THREE.Face3(0, 3, 2),
    new THREE.Face3(0, 2, 1),
];

let cubeGeometry = new THREE.Geometry();
cubeGeometry.vertices = vertices;
cubeGeometry.faces = faces;

let wireframe = new THREE.MeshBasicMaterial({wireframe: true});
let brown = new THREE.MeshBasicMaterial({color: 0xD47629});

let cube = new THREE.Mesh(cubeGeometry, wireframe);
let cubePink = new THREE.Mesh(cubeGeometry, brown);
cubePink.translateZ(2);

scene.add(cube);
scene.add(cubePink);

let axes = new THREE.AxisHelper(1.5);
scene.add(axes);

module.exports = scene;
