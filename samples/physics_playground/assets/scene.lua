-- Generated by: /home/godlike/src/anki/buildd/bin/gltf_importer physics_playground.gltf ../../ -rpath assets -texrpath assets
local scene = getSceneGraph()
local events = getEventManager()

node = scene:newGpuParticleEmitterNode("Cube.020", "assets/gpu_sparks.ankipart")
trf = Transform.new()
trf:setOrigin(Vec4.new(25.411236, 0.543148, 22.679190, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(0.500000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)

node = scene:newModelNode("Icosphere.001", "assets/Icosphere_walls.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(25.411236, 3.345554, 28.742823, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.912920)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Icosphere.001_cl", "assets/Icosphere.ankicl", trf)

node = scene:newModelNode("Icosphere", "assets/Icosphere_walls.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(25.411236, 3.316930, 22.637743, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.264235)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Icosphere_cl", "assets/Icosphere.ankicl", trf)

node = scene:newModelNode("Cube.019", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(30.798492, 2.376611, -6.000000, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.019_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.018", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(29.798492, 1.376611, -6.000000, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.018_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.017", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(28.798492, 0.376611, -6.000000, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.017_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.016", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(31.798492, 3.376611, -6.000000, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.016_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.015", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(32.798492, 4.376611, -6.000000, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.015_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.014", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(33.798492, 5.376611, -6.000000, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.014_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.013", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(39.798492, 6.376611, 0.000000, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.013_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.012", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(39.798492, 6.376611, -6.000000, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.012_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.011", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(39.798492, 6.376611, 6.000000, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.011_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.010", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(39.798492, 6.376611, 12.000000, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.010_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.009", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(42.271385, 2.886189, 0.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.009_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.008", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(42.271385, 2.886189, -6.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.008_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.007", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(42.271385, 2.886189, 6.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.007_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.006", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(42.271385, 2.886189, 12.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.006_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.005", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(37.271385, 2.886189, 12.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.005_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.004", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(37.271385, 2.886189, 6.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.004_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.003", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(37.271385, 2.886189, -6.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.003_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.002", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(37.271385, 2.886189, 0.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.002_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Suzanne", "assets/Suzanne_dynamic.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(179.044937, 9.701135, 0.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Suzanne_cl", "assets/Suzanne.ankicl", trf)

node = scene:newModelNode("Cube.001", "assets/walls_sky.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(0.000000, 9.109353, 0.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(10.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)

node = scene:newModelNode("Cube", "assets/floor_walls.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(0.000000, -5.068616, 0.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube_cl", "assets/floor.ankicl", trf)

node = scene:newDirectionalLightNode("Lamp_Orientation")
lcomp = node:getSceneNodeBase():getLightComponent()
lcomp:setDiffuseColor(Vec4.new(50.000000, 50.000000, 50.000000, 1))
lcomp:setShadowEnabled(1)
trf = Transform.new()
trf:setOrigin(Vec4.new(4.076245, 74.444725, -1.005454, 0))
rot = Mat3x4.new()
rot:setAll(0.649201, -0.658183, -0.381226, 0.000000, 0.506372, 0.000000, 0.862315, 0.000000, -0.567562, -0.752858, 0.333286, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)

node = scene:newPerspectiveCameraNode("Camera_Orientation")
scene:setActiveCameraNode(node:getSceneNodeBase())
frustumc = node:getSceneNodeBase():getFrustumComponent()
frustumc:setPerspective(0.100000, 500.000000, getMainRenderer():getAspectRatio() * 0.750416, 0.750416)
frustumc:setShadowCascadesDistancePower(1.5)
frustumc:setEffectiveShadowDistance(100.000000)
trf = Transform.new()
trf:setOrigin(Vec4.new(7.481132, 7.870111, 6.507640, 0))
rot = Mat3x4.new()
rot:setAll(0.685921, -0.324013, 0.651558, 0.000000, 0.000000, 0.895396, 0.445271, 0.000000, -0.727676, -0.305421, 0.614170, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)

node = scene:newModelNode("Cube.021", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(39.798492, 6.376611, -12.000000, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.021_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.022", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(42.271385, 2.886189, -12.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.022_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.023", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(37.271385, 2.886189, -12.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.023_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.024", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(39.798492, 6.376611, -18.000000, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.024_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.025", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(42.271385, 2.886189, -18.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.025_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.026", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(37.271385, 2.886189, -18.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.026_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.027", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(34.761005, 2.886189, -21.498241, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.027_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.028", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(44.761005, 2.886189, -21.498241, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.028_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.029", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(47.271385, 2.886189, -25.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.029_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.030", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(32.271385, 2.886189, -25.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.030_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.031", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(32.271385, 2.886189, -31.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.031_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.032", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(47.271385, 2.886189, -31.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.032_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.033", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(44.761005, 2.886189, -34.498241, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.033_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.034", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(38.761005, 2.886189, -34.498241, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.034_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.035", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(34.761005, 2.886189, -34.498241, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(0.995130)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.035_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.036", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(34.798492, 6.376611, -32.000000, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.036_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.038", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(34.798492, 6.376611, -24.000000, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.038_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.039", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(34.798492, 6.398044, -28.000000, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.039_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.037", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(44.798492, 6.376611, -32.000000, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.037_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.040", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(44.798492, 6.376611, -24.000000, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.040_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.041", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(44.798492, 6.398044, -28.000000, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.041_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.042", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(39.798492, 6.334259, -31.947594, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.042_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.043", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(39.798492, 6.334259, -23.947592, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.043_cl", "assets/wall.ankicl", trf)

node = scene:newModelNode("Cube.044", "assets/wall_walls.001.ankimdl")
trf = Transform.new()
trf:setOrigin(Vec4.new(39.798492, 6.355691, -27.947592, 0))
rot = Mat3x4.new()
rot:setAll(0.000000, 1.000000, 0.000000, 0.000000, -1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
node2 = scene:newStaticCollisionNode("Cube.044_cl", "assets/wall.ankicl", trf)

node = scene:newGlobalIlluminationProbeNode("refl_probe.002")
comp = node:getSceneNodeBase():getGlobalIlluminationProbeComponent()
comp:setBoundingBox(Vec4.new(-128.498062, -128.498062, -128.498062, 0), Vec4.new(128.498062, 128.498062, 128.498062, 0))
comp:setCellSize(32.000000)
trf = Transform.new()
trf:setOrigin(Vec4.new(-0.068372, 9.192602, -0.126609, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)

node = scene:newReflectionProbeNode("refl_probe", Vec4.new(-134.111938, -134.111938, -134.111938, 0), Vec4.new(134.111938, 134.111938, 134.111938, 0))
trf = Transform.new()
trf:setOrigin(Vec4.new(0.000000, 9.113202, 0.000000, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)

node = scene:newGlobalIlluminationProbeNode("Cube.045")
comp = node:getSceneNodeBase():getGlobalIlluminationProbeComponent()
comp:setBoundingBox(Vec4.new(-7.512932, -3.476489, -6.451754, 0), Vec4.new(7.512932, 3.476490, 6.451752, 0))
trf = Transform.new()
trf:setOrigin(Vec4.new(39.731613, 2.915391, -28.049887, 0))
rot = Mat3x4.new()
rot:setAll(1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000)
trf:setRotation(rot)
trf:setScale(1.000000)
node:getSceneNodeBase():getMoveComponent():setLocalTransform(trf)
