#include <string>
#include <iostream>

#include "http_filter.h"

#include "envoy/server/filter_config.h"
#include "dw/libDw.h"
//#include <ctime>

namespace Envoy {
namespace Http {

HttpSampleDecoderFilterConfig::HttpSampleDecoderFilterConfig(
    const sample::Decoder& proto_config)
    : key_(proto_config.key()), val_(proto_config.val()) {}

HttpSampleDecoderFilter::HttpSampleDecoderFilter(HttpSampleDecoderFilterConfigSharedPtr config)
    : config_(config) {}

HttpSampleDecoderFilter::~HttpSampleDecoderFilter() {}

void HttpSampleDecoderFilter::onDestroy() {}

const LowerCaseString HttpSampleDecoderFilter::headerKey() const {
  return LowerCaseString(config_->key());
}

const std::string HttpSampleDecoderFilter::headerValue() const {
//  clock_t begin = clock();
//  char script[] = "output application/json --- { root: 123 }";
  graal_create_isolate_params_t isolate_params = {};
  graal_isolate_t* isolate;
  graal_isolatethread_t* thread;
  if (graal_create_isolate(&isolate_params, &isolate, &thread)) {
    std::cout << "\n\n\nerroooor\n\n\n" << std::endl;
    return "erroooor";
  }
  std::string str = config_->val();
  char *cstr = new char[str.length() + 1];
  strcpy(cstr, str.c_str());
  char* foo = runDW(thread, cstr);
//  std::cout << "\n\n\n" << foo << "\n\n\n" << std::endl;
//  clock_t end = clock();
//  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
//  std::cout << "\n\n\nTIEMPO: " << elapsed_secs << "\n\n\n" << std::endl;
  return foo;
}

FilterHeadersStatus HttpSampleDecoderFilter::decodeHeaders(HeaderMap& headers, bool) {
  // add a header
  headers.addCopy(headerKey(), headerValue());

  return FilterHeadersStatus::Continue;
}

FilterDataStatus HttpSampleDecoderFilter::decodeData(Buffer::Instance&, bool) {
  return FilterDataStatus::Continue;
}

FilterTrailersStatus HttpSampleDecoderFilter::decodeTrailers(HeaderMap&) {
  return FilterTrailersStatus::Continue;
}

void HttpSampleDecoderFilter::setDecoderFilterCallbacks(StreamDecoderFilterCallbacks& callbacks) {
  decoder_callbacks_ = &callbacks;
}

} // namespace Http
} // namespace Envoy
