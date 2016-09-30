#include <node.h>

using namespace v8;

namespace heapstats {

	void Method(const FunctionCallbackInfo<Value>& args) {
		Isolate* isolate = args.GetIsolate();

		Local<Array> out = Array::New(isolate);
		HeapSpaceStatistics stats;
		for (size_t i = 0; i < isolate->NumberOfHeapSpaces(); ++i) {
			isolate->GetHeapSpaceStatistics(&stats, i);

			Local<Object> space = Object::New(isolate);
			space->Set(String::NewFromUtf8(isolate, "space_name"), String::NewFromUtf8(isolate, stats.space_name()));
			space->Set(String::NewFromUtf8(isolate, "space_size"), Number::New(isolate, stats.space_size()));
			space->Set(String::NewFromUtf8(isolate, "space_used_size"), Number::New(isolate, stats.space_used_size()));
			space->Set(String::NewFromUtf8(isolate, "space_available_size"), Number::New(isolate, stats.space_available_size()));
			space->Set(String::NewFromUtf8(isolate, "physical_space_size"), Number::New(isolate, stats.physical_space_size()));

			out->Set(i, space);
		}

		args.GetReturnValue().Set(out);
	}

	void init(Local<Object> exports) {
		NODE_SET_METHOD(exports, "get", Method);
	}

	NODE_MODULE(heapstats, init)
}