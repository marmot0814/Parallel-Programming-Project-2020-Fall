#ifndef NODE_SHARED_MEM_H
#define NODE_SHARED_MEM_H

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

struct Bound {
  double minx, miny, maxx, maxy;
  double cx, cy;
};

class Quad {
  double minx, miny, maxx, maxy;
  Quad(double minx, double miny, double maxx, double maxy):
    minx(minx), miny(miny), maxx(maxx), maxy(maxy){}
  bool overlaps(Quad other) {
    return !(minx >= other.maxx || maxx <= other.minx
        || miny >= other.maxy || maxy <= other.miny);
  }
};

class QuadNode : public Napi::ObjectWrap<QuadNode> {
  public:
		static Napi::Object Init(Napi::Env env, Napi::Object exports);
		QuadNode(const Napi::CallbackInfo& info);

	private:
		static Napi::FunctionReference constructor;
		Napi::Value Check(const Napi::CallbackInfo& info);

    double halfWidth;
    double halfHeight;
    Bound bound;
    std::vector<QuadNode> childNodes;
    std::vector<Napi::Object> items;
};

#endif
