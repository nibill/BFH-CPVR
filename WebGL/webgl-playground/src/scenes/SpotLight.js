const THREE = require('three');

let scene = new THREE.Scene();

let plane = new THREE.Mesh(
    new THREE.PlaneGeometry(20, 20, 0),
    new THREE.MeshPhongMaterial({side: THREE.DoubleSide, color: 0xffffff, specular: 0xffffff})
);

plane.position.set(0, 0, 0);
plane.rotation.set(Math.PI / 2, 0, 0);
plane.receiveShadow = true;
scene.add(plane);

let geometry = new THREE.BoxGeometry(2, 2, 2);
let material = new THREE.MeshPhongMaterial({color: 0x555555,
  specular: 0xffffff, shininess: 70, shading: THREE.SmoothShading});
let cube = new THREE.Mesh(geometry, material);
cube.position.y = 1;
cube.position.x = 1.1;
cube.castShadow = true;
scene.add(cube);

let cube1 = new THREE.Mesh(geometry, material);
cube1.position.y = 1;
cube1.position.x = -1.1;
cube1.castShadow = true;
scene.add(cube1);

let cube2 = new THREE.Mesh(geometry, material);
cube2.position.y = 3.1;
cube2.position.x = 0.1;
cube2.castShadow = true;
scene.add(cube2);

//scene.add(new THREE.AmbientLight(0xff0040));
scene.add(new THREE.AmbientLight(0x111111));

let spotLight = new THREE.SpotLight(0xffffff, 6, 40, Math.PI/10);
//spotLight.target.position.set(.5, .5, .5);
//spotLight.position.set(20,  5, 20);
spotLight.position.set(0,  10, 20);
spotLight.castShadow = true;
scene.add(spotLight);

let spotlighthelper = new THREE.SpotLightHelper(spotLight);
scene.add(spotlighthelper);

let axisHelper = new THREE.AxisHelper( 5 );
scene.add( axisHelper );

module.exports = scene;


