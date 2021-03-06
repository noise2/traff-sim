#ifndef SERVER_H
#define SERVER_H


#ifdef __unused
#   define __unused_bk __unused
#   undef __unused
#endif
// this should be after `stdafx.hpp` because contain a `__unused` var in it
//  which also defined in `stdafx.hpp` that causes a problem
#include <boost/asio.hpp>

#if defined(__unused_bk) && !defined(__unused)
#   define __unused __unused_bk
#   undef __unused_bk
#endif

#include "stdafx.hpp"
#include <unordered_map>

using boost::asio::ip::tcp;

typedef size_t SOCKET;
typedef shared_ptr<tcp::socket> socket_ptr;

class server
{
    /**
     * @brief _port the listening port
     */
    const size_t _port;
    /**
     * @brief _socket_count the number of socket that accepted
     */
    SOCKET _socket_count = 0;
    /**
     * @brief _io_service io server instance
     */
    boost::asio::io_service* _io_service;
    /**
     * @brief _sockets the accepted sockets packages
     */
    unordered_map<SOCKET, socket_ptr> _sockets;
public:
    ~server() noexcept { delete this->_io_service; }
    /**
     * @brief server ctor
     * @param port the listening port
     */
    server(size_t port) : _port(port), _io_service(new boost::asio::io_service()) { }
    /**
     * @brief accepts a new client
     * @return the client's handler
     */
    SOCKET accept();
    /**
     * @brief close closes a client
     * @param socket_id the client handler
     */
    void close(SOCKET handler);
    /**
     * @brief receives a message from a client until reaches EOF
     * @param handler the client handler
     * @param ec the error code output
     * @return the read message
     */
    string receive(SOCKET handler, boost::system::error_code& ec);
    /**
     * @brief receives a message from a client
     * @param handler the client handler
     * @param ec the error code output
     * @param until read termination flag
     * @return the read message
     */
    string receive(SOCKET handler, boost::system::error_code& ec, string until);
    /**
     * @brief receives a message from a client
     * @param handler the client handler
     * @param ec the error code output
     * @param size read max size of bytes
     * @return the read message
     */
    string receive(SOCKET handler, boost::system::error_code& ec, size_t& size);
    /**
     * @brief send sends a message to a client
     * @param handler the client handler
     * @param msg the message to be sent
     * @param ec the error code output
     * @return the number byte sent
     */
    inline size_t send(SOCKET handler, string msg, boost::system::error_code& ec) {
        return boost::asio::write(*this->get_socket(handler), boost::asio::buffer(msg), ec);
    }
    /**
     * @brief get_socket get a client's socket
     * @param handler the client's handler
     */
    inline socket_ptr get_socket(SOCKET handler) const {
        if(!this->_sockets.count(handler)) throw runtime_error("undefined socket id!");
        return this->_sockets.at(handler);
    }
    /**
     * @brief is_open check if a client's open
     * @param handler the client's handler
     */
    inline bool is_open(SOCKET handler) { return this->get_socket(handler)->is_open(); }
    /**
     * @brief operator [] access to a client
     * @param handler the client's handler
     */
    inline socket_ptr operator [](SOCKET handler) { return this->get_socket(handler); }
};

#endif // SERVERHOST_H
