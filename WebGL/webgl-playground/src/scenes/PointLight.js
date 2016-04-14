const THREE = require('three');

let scene = new THREE.Scene();

//let material = new THREE.MeshLambertMaterial({color: 0xffffff});
//let geometry = new THREE.BoxBufferGeometry(1, 1, 1);
//let mesh = new THREE.Mesh(geometry, material);
let width = 960;
let height = 500;

let camera = new THREE.PerspectiveCamera(25, width/height, 0.1, 1000);

let renderer = new THREE.WebGLRenderer();
renderer.setSize(width, height);

let geometry = new THREE.BoxGeometry(1, 1, 1);
let material = new THREE.MeshPhongMaterial({ambient: 0x555555, color: 0x555555,
  specular: 0xffffff, shininess: 50, shading: THREE.SmoothShading});
let cube = new THREE.Mesh(geometry, material);
scene.add(cube);
scene.add(new THREE.AmbientLight(0xff0040));

let spotLight = new THREE.SpotLight(0xffffff, 6, 40);
spotLight.position.set(20, 20, 20);
scene.add(spotLight);

//let light = new THREE.AmbientLight(0x404040); // soft white light
//scene.add(light);
// define an animation loop



module.exports = scene;
