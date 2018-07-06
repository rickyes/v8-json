#include <node.h>
#include "v8json.h"

namespace ___V8JSON___ {

  using v8::Isolate;
  using v8::HandleScope;
  using v8::Local;
  using v8::String;
  using v8::FunctionTemplate;
  using v8::Object;

  void Init(Local<Object> exports, Local<Object> module){
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    Local<FunctionTemplate> p = FunctionTemplate::New(isolate, v8json::parse);
    Local<FunctionTemplate> s = FunctionTemplate::New(isolate, v8json::stringify);
    exports->Set(String::NewFromUtf8(isolate,"parse"), p->GetFunction());
    exports->Set(String::NewFromUtf8(isolate,"stringify"), s->GetFunction());
  }

  NODE_MODULE(v8json, Init);

}