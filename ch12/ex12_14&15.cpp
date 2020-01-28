/*
 * @Author: liyunfang
 * @Date: 2020-01-28 17:24:24
 * @LastEditTime : 2020-01-28 18:07:35
 * @Description: 
 */
#include <iostream>
#include <string>
#include <memory>

struct destination
{
    std::string ip;
    int port;
    destination(std::string const &ip_, int const &port_): ip(ip_), port(port_) {}
};

struct connection
{
    std::string ip;
    int port;
    connection(std::string const &ip_, int const &port_): ip(ip_), port(port_) {}
};

auto connect(destination *pDest)
{
    auto pConn = std::make_shared<connection>(pDest->ip, pDest->port);
    std::cout << "Creating connection(" << pConn.use_count() << ")" <<std::endl;
    return *pConn;
}

auto disconnect(connection pConn)
{
    std::cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << std::endl;
}

auto end_connection(connection *pConn)
{
    disconnect(*pConn);
}

auto f(destination &d)
{
    auto c = connect(&d);
    // std::shared_ptr<connection> p(&c, end_connection);
    std::shared_ptr<connection> p(&c, [](connection *pConn){ disconnect(*pConn); });
    std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

int main()
{
    destination dest("202.118.176.67", 3316);
    f(dest);
}