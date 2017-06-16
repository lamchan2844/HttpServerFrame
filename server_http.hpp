/*
 * server_http.h
 * http 服务器
 * create by chenlin
 * email:chenlin2844@hotmail.com
 */


#ifndef SERVER_HTTP_H
#define SERVER_HTTP_H

#include "server_base.hpp"
namespace webX{
	typedef boost::asio::ip::tcp::socket HTTP;
	template<>
		class Server<HTTP>:public ServerBase<HTTP>{
			public:
				Server(unsigned int port, size_t num_threads=1):
					ServerBase<HTTP>::ServerBase(port,num_threads){};
			private:
				//accept方法
				void accept(){
					auto socket = std::make_shared<HTTP>(m_io_service);
					acceptor.async_accept(*socket, [this,socket](const boost::system::error_code & ec){
						accept();//立即启动并接受一个连接
						if(!ec){
							process_request_and_respond(socket);
						}
					});
				}
		};
}

#endif /*SERVER_HTTP_HPP*/
