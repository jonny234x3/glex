#ifndef COMMON_H
#define COMMON_H

//////////////////////////////////////////////////////////////////////////////////
/// ApplicationMode denotes the global state of the application. There are three
/// global states for this application which loader the correct shaders to:
/// 1. Transform -- do a transformation of a simple asset.
/// 2. Rotate -- rotate a simple asset.
/// 3. Scale -- simple asset.
//////////////////////////////////////////////////////////////////////////////////

enum ApplicationMode {TRANSFORM, ROTATE, SCALE};
enum Input{ NILL , FORWARD, DOWN, LEFT, RIGHT, ASCEND, DESCEND};

#endif
