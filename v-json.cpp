#include <node.h>

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

  void parse(const FunctionCallbackInfo<Value>& args){
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    if (!args[0]->IsString()){
      isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Param is Not String!")));
      return;
    }
  
    MaybeLocal<Value> json = JSON::Parse(isolate,args[0]->ToString());
    if (json.IsEmpty()){
      isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Param is Not JSON String!")));
      return;
    }
    Local<Value> value = json.ToLocalChecked();
    args.GetReturnValue().Set(value);
  }

  void stringify(const FunctionCallbackInfo<Value>& args){
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    if (!args[0]->IsObject()){
      isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Param is Not Object!")));
      return;
    }
    MaybeLocal<String> str = JSON::Stringify(Isolate::GetCurrent()->GetCurrentContext(),args[0]->ToObject());
    Local<String> value = str.ToLocalChecked();
    args.GetReturnValue().Set(value);
  }

  void Init(Local<Object> exports, Local<Object> module){
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    Local<FunctionTemplate> p = FunctionTemplate::New(isolate, parse);
    Local<FunctionTemplate> s = FunctionTemplate::New(isolate, stringify);
    exports->Set(String::NewFromUtf8(isolate,"parse"), p->GetFunction());
    exports->Set(String::NewFromUtf8(isolate,"stringify"), s->GetFunction());
  }

  NODE_MODULE(vjson, Init);

};