
#include "SimpleGrpcProxy.h"

#include <grpcpp/grpcpp.h>

int main()
{
  std::string target_address = "localhost:50051";
  SimpleGRPCProxy client(grpc::CreateChannel(target_address,grpc::InsecureChannelCredentials()));

  std::string user = "World";

  std::string reply = client.doSayHello(user);
  std::cout << "Server reply: " << reply << std::endl;

  return 0;
}
