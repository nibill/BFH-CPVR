var camera, orbitControls, scene, renderer;

init();
animate();

function init()
{
  scene = new THREE.Scene();
  camera = new THREE.PerspectiveCamera(45, window.innerWidth, 0.1, 1000);

  camera.position.x = -10;
  camera.position.y = 10;
  camera.position.z = 10;

  // create a render and set the size
  renderer = new THREE.WebGLREnderer();
  render.setClearColor(0x000000);
  
}
