#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct connection
{
    string ip;
    int port;
    connection(string ip_, int port_) : ip(ip_), port(port_) {}
};
struct destination
{
    string ip;
    int port;
    destination(string ip_, int port_) : ip(ip_), port(port_) {}
};

connection connect(destination *pDest)
{
    shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
    cout << "creating connection(" << pConn.use_count() << ")"
         << endl;
    return *pConn;
}

void disconnect(connection pConn)
{
    cout << "connection close(" << pConn.ip << ":" << pConn.port << ")"
         << endl;
}

void end_connection(connection *pConn)
{
    disconnect(*pConn);
}

void f(destination &d)
{
    connection conn = connect(&d);
    // 使用智能指针管理的资源不是New分配的内存时，记住为其传递一个删除器
    // shared_ptr<connection> p(&conn, end_connection);

    shared_ptr<connection> p(&conn, [](connection *pConn) { disconnect(*pConn); });

    cout << "connecting now(" << p.use_count() << ")" << endl;
}

int main()
{
    destination dest("202.118.176.67", 3316);
    f(dest);
}