#include "SimpleGrpcServer.h"

#include <grpcpp/server_builder.h>

using grpc::Status;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::InsecureServerCredentials;

using SimpleGRPC::SimpleRequest;
using SimpleGRPC::SimpleResponse;

Status SimpleGRPCService::doSayHello(ServerContext* context,const SimpleRequest* request,SimpleResponse* response)
{
  std::string name = request->name();
  std::string message = "Hello " + name + "!";
  response->set_message(message);
  std::cout << "Received request from: " << name << std::endl;
  return grpc::Status::OK;
}

void SimpleGRPCService::run()
{
  grpc::EnableDefaultHealthCheckService(true);// 启用默认健康检查服务

  std::string server_address("0.0.0.0:50051");

  ServerBuilder builder;
  builder.AddListeningPort(server_address,InsecureServerCredentials());
  builder.RegisterService(this);

  std::unique_ptr<Server> server = builder.BuildAndStart();
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
}
