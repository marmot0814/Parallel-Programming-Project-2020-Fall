#ifndef UTILS_H
#define UTILS_H

#include <napi.h>
#include "quadnode.h"

double Double(Napi::Value value) {
  return value.ToNumber().DoubleValue();
}

#endif
