#include <node.h>
#include "v8json.h"

namespace ___V8JSON___ {
  
  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::HandleScope;
  using v8::MaybeLocal;
  using v8::Local;
  using v8::String;
  using v8::Exception;
  using v8::FunctionTemplate;
  using v8::JSON;
  using v8::Object;
  using v8::Value;

  v8json::v8json(){

  }

  v8json::~v8json(){

  }

  void v8json::Initialize(Local<Object> target) {
    Nan::HandleScope scope;

    Local<Object> result = Nan::New<Object>();
    Nan::SetMethod(result, "parse", v8json::parse);
    Nan::SetMethod(result, "stringify", v8json::stringify);

    target->Set(Nan::New<String>("v8json").ToLocalChecked(), result);
  }

  NAN_METHOD(v8json::parse) {
    if (!info[0]->IsString()) {
      Nan::ThrowError("Param is Not String!");
      return;
    }

    Nan::JSON NanJSON;
    Nan::MaybeLocal<Value> json = NanJSON.Parse(info[0]->ToString());
    if (json.IsEmpty()) {
      Nan::ThrowError("Param is Not JSON String!");
      return;
    }

    Local<Value> value = json.ToLocalChecked();
    info.GetReturnValue().Set(value);
  }

  NAN_METHOD(v8json::stringify) {
    if (!info[0]->IsObject()) {
      Nan::ThrowError("Param is Not Object!");
      return;
    }

    Nan::JSON NanJSON;
    Nan::MaybeLocal<String> str = NanJSON.Stringify(info[0]->ToObject());
    Local<String> value = str.ToLocalChecked();
    info.GetReturnValue().Set(value);
  }

}