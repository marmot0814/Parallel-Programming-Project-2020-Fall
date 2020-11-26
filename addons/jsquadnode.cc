#include <napi.h>
#include <node.h>
#include <memory>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include "quadnode.h"
#include "utils.h"

using namespace std;

Napi::FunctionReference jsQuadNode::constructor;

jsQuadNode::jsQuadNode(const Napi::CallbackInfo& info) : Napi::ObjectWrap<jsQuadNode>(info) {

  Napi::Object jsbound = info[0].ToObject();
  Quad bound(Double(jsbound.Get("minx")),
             Double(jsbound.Get("miny")),
             Double(jsbound.Get("maxx")),
             Double(jsbound.Get("maxy")));
  quadnode = new QuadNode(bound);
}

Napi::Object jsQuadNode::Init(Napi::Env env, Napi::Object exports) {
	Napi::HandleScope scope(env);
  Napi::Function func = DefineClass(env, "QuadNode", {
		InstanceMethod("check", &jsQuadNode::Check)
	});

	constructor = Napi::Persistent(func);
	constructor.SuppressDestruct();
	exports.Set("QuadNode", func);
	return exports;
}

Napi::Value jsQuadNode::Check(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object ret = Napi::Object::New(env);
  ret.Set("halfWidth", this->quadnode->halfWidth);
  ret.Set("halfHeight", this->quadnode->halfHeight);

  return ret;
}
