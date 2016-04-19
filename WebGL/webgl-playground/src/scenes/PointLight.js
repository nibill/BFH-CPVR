const THREE = require('three');

let scene = new THREE.Scene();

let width = 960;
let height = 500;

let camera = new THREE.PerspectiveCamera(25, width/height, 0.1, 1000);

let renderer = new THREE.WebGLRenderer();
renderer.setSize(width, height);

let geometry = new THREE.BoxGeometry(15, 15, 15);
let material = new THREE.MeshPhongMaterial({color: 0x555555,
  specular: 0xffffff, shininess: 50, shading: THREE.SmoothShading});
let cube = new THREE.Mesh(geometry, material);
scene.add(cube);
scene.add(new THREE.AmbientLight(0xff0040));


let light = new THREE.PointLight( 0xff0000, 1, 100 );
light.position.set( 50, 20, 30 );
scene.add( light );

let sphereSize = 1;
let pointLightHelper = new THREE.PointLightHelper( light, sphereSize );
scene.add( pointLightHelper );

module.exports = scene;
