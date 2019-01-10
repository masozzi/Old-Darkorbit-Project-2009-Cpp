project (
  'old-darkorbit',
  'cpp',
  version: '0.0.1',
  default_options: [
  	'werror=true',
  	'cpp_std=c++17'
  ]
)

sources = [
  'src/BonusBox.cpp',
  'src/DBGetter.cpp',
  'src/GameServer.cpp',
  'src/Ore.cpp',
  'src/PolicyServer.cpp',
  'src/Collectable.cpp',
  'src/DBUpdater.cpp',
  'src/Main.cpp',
  'src/PacketComposer.cpp',
  'src/ResourceBox.cpp',
  'src/Color.cpp',
  'src/Defines.cpp',
  'src/Map.cpp',
  'src/Packeter.cpp',
  'src/Session.cpp',
  'src/DamageManager.cpp',
  'src/FileReader.cpp',
  'src/Mob.cpp',
  'src/PlayerHandler.cpp',
  'src/SessionsManager.cpp',
  'src/DatabaseUtils.cpp',
  'src/FileWriter.cpp',
  'src/MovementManager.cpp',
  'src/PolicyHandler.cpp'
]

inc = include_directories('/usr/include/mysql')

executable (
  'darkorbit',
  sources,
  include_directories: inc
)
