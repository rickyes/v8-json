#ifndef V8JSON
#define V8JSON

#include <node.h>

namespace ___V8JSON___ {

  using v8::FunctionCallbackInfo;
  using v8::Value;
  
  class v8json {
    public:
      static void parse(const FunctionCallbackInfo<Value>& args);
      static void stringify(const FunctionCallbackInfo<Value>& args);
    
    private:
      explicit v8json();
      ~v8json();
  };

}

#endif