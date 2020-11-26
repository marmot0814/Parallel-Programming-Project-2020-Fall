#include <napi.h>
#include <node.h>
#include <memory>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include "quadnode.h"

// using namespace Napi;
using namespace std; //Don't if you're in a header-file

QuadNode::QuadNode(Quad _bound) {
  bound = _bound;

  halfWidth = (bound.maxx - bound.minx) / 2;
  halfHeight = (bound.maxy - bound.miny) / 2;
  bound.cx = bound.minx + halfWidth;
  bound.cy = bound.miny + halfHeight;
}
