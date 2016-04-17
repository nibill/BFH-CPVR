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

let geometry = new THREE.BoxGeometry(5, 5, 5);
let material = new THREE.MeshPhongMaterial({ambient: 0x555555, color: 0x555555,
  specular: 0xffffff, shininess: 70, shading: THREE.SmoothShading});
let cube = new THREE.Mesh(geometry, material);
cube.position.y = 2.6
scene.add(cube);

scene.add(new THREE.AmbientLight(0xff0040));

let spotLight = new THREE.SpotLight(0xffffff, 6, 40, Math.PI/10);
//spotLight.target.position.set(.5, .5, .5);
spotLight.position.set(20,  5, 20);
//spotlight.castShadow = true;
scene.add(spotLight);

// let spotLight = new THREE.SpotLight(0xdddddd, 3, 20, .2);
// spotLight.target.position.set(.5, .5, .5);
// spotLight.position.set(-5, 5, 5);
// spotLight.castShadow = true;
// scene.add(spotLight);


let spotlighthelper = new THREE.SpotLightHelper(spotLight);
scene.add(spotlighthelper);

let axisHelper = new THREE.AxisHelper( 5 );
scene.add( axisHelper );

module.exports = scene;


