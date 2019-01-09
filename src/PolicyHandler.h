
#ifndef POLICYHANDLER_H
#define POLICYHANDLER_H
#include <iostream>
#include <boost/asio.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include "FileReader.h"
#include "Defines.h"
#include "Constants.h"

//////////////////////////////////////////////////////////
//		Class PolicyHandler
//////////////////////////////////////////////////////////

typedef boost::asio::ip::tcp tcp_t;

// This class is derived from boost.org and some help of stackoverflow
class CPolicyHandler :
	public std::enable_shared_from_this<CPolicyHandler>
{
	// Represents the socket
	tcp_t::socket m_socket;
	//text to write
	std::string m_sendstring; // send
						 //received text
	std::string m_information;
	char buf[1024]; // received

	boost::asio::streambuf m_buffer;

	unsigned short m_port;
public:
	// Keeping it short
	typedef std::shared_ptr<CPolicyHandler> tcppointer;

	// Creates a smart connection pointer to an object of this type.
	static tcppointer createConnection(boost::asio::io_service& io_service, unsigned short port);

	// Returns the socket
	tcp_t::socket& getSocket();

	// Starting to asynchrounously write data
	void start();

	~CPolicyHandler();
private:
	// We are going to use the ctor of our socket member
	CPolicyHandler(boost::asio::io_service& io_service, unsigned short& port) : m_socket(io_service), buf{ 0 } { m_port = port; }

	void handle_write(const boost::system::error_code& ec, size_t bytes);

	void readData();
	void send();
	void disconnectUser();

	void handle_read(const boost::system::error_code & ec, size_t bytes);


};
#endif
