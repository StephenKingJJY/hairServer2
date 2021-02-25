#define HTTPSERVER_IMPL
#include "httpserver.h"

// void handle_request(struct http_request_s* request) {
//   http_request_connection(request, HTTP_AUTOMATIC);
//   struct http_response_s* response = http_response_init();
  
//   http_string_t url = http_request_target(request);
//   http_string_t body = http_request_body(request);
//   http_string_t ua = http_request_header(request, "Host");

//   const char res[]="<span style='color:red'>wahhh</span>";
//   hairserver(res);

//   http_response_status(response, 200);
//   http_response_header(response, "Content-Type", "text/html; charset=utf-8");
//   http_response_body(response, res, sizeof(res)-1);

//   http_respond(request, response);
// }

void transformstring(const void* word_pointer, const char* word) {
  printf("%s\n",word);
  // printf("%s\n", *word_pointer);
}


void startup(int port, void* handle_request) {
  const void* a;
  transformstring(a,"s妇女节");
  struct http_server_s* server;
  server = http_server_init(port, handle_request);
  http_server_listen(server);
}

void default_request(struct http_request_s* request) {
  http_request_connection(request, HTTP_AUTOMATIC);
  struct http_response_s* response = http_response_init();
  http_response_status(response, 200);
  http_string_t url = http_request_target(request);
  http_string_t body = http_request_body(request);
  http_string_t ua = http_request_header(request, "Host");
  http_response_header(response, "Content-Type", "text/plain");
  http_response_body(response, url.buf, url.len);
  http_respond(request, response);
}

int main(){
  startup(8080,default_request);
}