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

//let light = new THREE.AmbientLight(0x404040); // soft white light
//scene.add(light);

// set the camera
camera.position.z = 5;

let render = function () {
  requestAnimationFrame(render);

  // rotate the cube
  cube.rotation.x += 0.01;
  cube.rotation.y += 0.01;

  renderer.render(scene, camera);
};

render();

module.exports = scene;
