/*
 * main_http.cpp
 * http web server
 * create by chenlin
 * email:chenlin2844@hotmail.com
 */

#include "server_http.hpp"
#include "handler.hpp"

using namespace webX;
int main(){
	Server<HTTP> server(12345,4);
	start_server<Server<HTTP>>(server);
	return 0;
}
