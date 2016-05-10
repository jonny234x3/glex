EXTRA_DIST = GameWorld.h GameAssetManager.h GameAsset.h Game.h CubeAsset.h FloorAsset.h PyramidAsset.h Camera.h BoundingBox.h PythonB.h

bin_PROGRAMS = shaderexample
shaderexample_SOURCES = main.cc
shaderexample_LDADD = liblink.la

lib_LTLIBRARIES = liblink.la
liblink_la_SOURCES = GameWorld.cc GameAssetManager.cc CubeAsset.cc FloorAsset.cc PyramidAsset.cc Camera.cc BoundingBox.cc GameAsset.cc Game.cc PythonB.cc

AM_CPPFLAGS = -DGL_GLEXT_PROTOTYPES -DGL3_PROTOTYPES
AM_CPPFLAGS += -std=c++11 -I/usr/include/python2.7
AM_CPPFLAGS += $(gl_CFLAGS) $(glew_CFLAGS) $(sdl2_CFLAGS) $(BOOST_CPPFLAGS)

LDFLAGS = -framework OpenGL -framework GLUT -lSDL2 -lboost_system -lboost_python -lpython2.7 -Wl,-rpath,'$$ORIGIN/.libs'
LIBS += $(gl_LIBS) $(glew_LIBS) $(sdl2_LIBS) $(BOOST_THREAD_LIBS) $(BOOST_PROGRAM_OPTIONS_LIBS)
