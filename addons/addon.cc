#include <napi.h>
#include "quadnode.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return QuadNode::Init(env, exports);
}

NODE_API_MODULE(quadnode, InitAll)
