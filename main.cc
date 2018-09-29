#include "node.h"
#include "nan.h"
#include "v8json.h"

namespace ___V8JSON___ {

  void Init(v8::Local<v8::Object> target){
    Nan::HandleScope scope;

    v8json::Initialize(target);
  }

  NODE_MODULE(v8json, Init);

}