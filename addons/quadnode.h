#ifndef QUADNODE_H
#define QUADNODE_H

//#include <node.h>
//#include <node_object_wrap.h>

#include <napi.h>
#include <bits/stdc++.h>
// #include <windows.h>
// typedef HANDLE HANDLE;
// #else
// #include <unistd.h>
// #include <sys/ipc.h>
// #include <sys/shm.h>
// #include <sys/mman.h>
// #include <sys/stat.h>        /* For mode constants */
// #include <fcntl.h>
// typedef key_t HANDLE;
// #endif

class QuadNode;

class Quad {
  public:
    double minx, miny, maxx, maxy;
    double cx, cy;
    Quad(){}
    Quad(double minx, double miny, double maxx, double maxy):
      minx(minx), miny(miny), maxx(maxx), maxy(maxy){}
    bool overlaps(Quad other) {
      return !(minx >= other.maxx || maxx <= other.minx
          || miny >= other.maxy || maxy <= other.miny);
    }
};

class Item {
  Napi::Object jsItem;
  QuadNode* quadNode;
  Item(Napi::Object& jsItem) : jsItem(jsItem) {};
};

class QuadNode {
  public:
    double halfWidth;
    double halfHeight;
    Quad bound;
    std::vector<QuadNode*> childNodes;
    std::vector<Item*> items;

    QuadNode(Quad);
};

class jsQuadNode : public Napi::ObjectWrap<jsQuadNode> {
  public:
		static Napi::Object Init(Napi::Env env, Napi::Object exports);
		jsQuadNode(const Napi::CallbackInfo& info);

		static Napi::FunctionReference constructor;
		Napi::Value Check(const Napi::CallbackInfo& info);

    QuadNode* quadnode;
};

#endif
