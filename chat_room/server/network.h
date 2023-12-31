#ifndef NETWORK_H
#define NETWORK_H
#include <netinet/in.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct sockaddr* SP;

typedef struct NetWork
{
	int type;		//通信协议
	int sock_fd;	//socket对象
	struct sockaddr_in addr;	//通信地址
	socklen_t addrlen;	//通信地址结构体字节数
	bool is_svr;	//是否为服务器
}NetWork;

//分配内存、创建socket、初始化地址、绑定、监听、连接
NetWork* init_nw(int type, uint16_t port, const char* ip, bool is_svr);

//等待连接、只能tcp的服务器执行
NetWork* accept_nw(NetWork* svr_nw);

//发送函数send/sendto
int send_nw(NetWork* nw,const void* buf, size_t len);

//接收函数recv/recvfrom
int recv_nw(NetWork* nw, void* buf, size_t len);

//关闭socket且释放内存
void close_nw(NetWork* nw);

#endif//NETWORK_H
