#ifndef V8JSON
#define V8JSON

#include "node.h"
#include "nan.h"

namespace ___V8JSON___ {
  
  class v8json {
    public:
      static void Initialize(v8::Local<v8::Object> target);
      static NAN_METHOD(parse);
      static NAN_METHOD(stringify);
    
    private:
      explicit v8json();
      ~v8json();
  };

}

#endif