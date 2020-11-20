#include <napi.h>
#include <node.h>
#include <memory>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include "quadnode.h"

using namespace Napi;
using namespace std; //Don't if you're in a header-file

double Double(Napi::Value value) {
  return value.ToNumber().DoubleValue();
}

Napi::FunctionReference QuadNode::constructor;

QuadNode::QuadNode(const Napi::CallbackInfo& info) : Napi::ObjectWrap<QuadNode>(info) {

  Napi::Object bound = info[0].ToObject();

  this->bound.minx = Double(bound.Get("minx"));
  this->bound.miny = Double(bound.Get("miny"));
  this->bound.maxx = Double(bound.Get("maxx"));
  this->bound.maxy = Double(bound.Get("maxy"));
  this->halfWidth = (this->bound.maxx - this->bound.minx) / 2;
  this->halfHeight = (this->bound.maxy - this->bound.miny) / 2;
  this->bound.cx = this->bound.minx + this->halfWidth;
  this->bound.cy = this->bound.miny + this->halfHeight;
}

Napi::Object QuadNode::Init(Napi::Env env, Napi::Object exports) {
	Napi::HandleScope scope(env);
  Napi::Function func = DefineClass(env, "QuadNode", {
		InstanceMethod("check", &QuadNode::Check)
	});

	constructor = Napi::Persistent(func);
	constructor.SuppressDestruct();
	exports.Set("QuadNode", func);
	return exports;
}

Napi::Value QuadNode::Check(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Object ret = Object::New(env);
  ret.Set("halfWidth", this->halfWidth);
  ret.Set("halfHeight", this->halfHeight);

  return ret;
}
