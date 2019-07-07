#pragma once
#include "udp_socket.hpp"

//C++ 11
#include<functional>
typedef  std::function<void (const std::string&, std::string* resp)> Handler;

class UdpServer{
public:
  UdpServer(){
    assert(sock_.Socket());
  }

  ~UdpServer(){
    sock_.Close();
  }

  bool Start(const std::string& ip, uint16_t port, Handler handler){
    //1,make socket
    //2,bind port
    bool ret = sock_.Bind(ip, port);
    if(!ret){
      return false;
    }
    //3,go to while
    for(; ;){
      //4,try to read plase
      std::string req;
      std::string remote_port = 0;
      bool ret = sock_.RecvFrom(&req, &remote_ip, &remote_port);
      if(!ret){
        continue;
      }
      std::string resp;
      //5,jisuan xiangying
      handler(req, &resp);
      //6,return kehuduan
      sock_.SendTo(resp, remote_ip, remote_port);
      printf("[%s:%d] req : %s\n", remote_ip.c_str(), remote_port,
            req.c_str(),resp.c_str());
    }
    sock_.Close();
    return true;
  }

private:
  UdpSocket sock_;
}
