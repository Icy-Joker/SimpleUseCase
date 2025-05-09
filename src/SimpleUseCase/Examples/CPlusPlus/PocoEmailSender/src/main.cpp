#include "stdafx.h"

#include <Poco/Net/SecureSMTPClientSession.h>
#include <Poco/Net/NetException.h>
#include <Poco/Net/MailMessage.h>
#include <Poco/Net/MailRecipient.h>
#include <Poco/Net/StringPartSource.h>
#include <Poco/Net/FilePartSource.h>
#include <Poco/Net/SSLManager.h>
#include <Poco/Net/Context.h>
#include <Poco/Net/PrivateKeyPassphraseHandler.h>
#include <Poco/Net/AcceptCertificateHandler.h>
#include <Poco/SharedPtr.h>

#include <iostream>

using namespace Poco;
using namespace Poco::Net;

int main(int argc,char* argv[])
{
  int result = 0;

  try
  {
    // 初始化 SSL（忽略证书验证）
    SharedPtr<InvalidCertificateHandler> certificate_handler = new AcceptCertificateHandler(false);
    //Context::Ptr context = new Context(Context::CLIENT_USE,"","","",Context::VERIFY_RELAXED,9,true);
    SSLManager::instance().initializeClient(nullptr,certificate_handler,nullptr);

    // 建立与 SMTP 服务器的连接（587 端口）
    SecureSMTPClientSession session("smtp.qq.com",587);
    // 建立 TCP 连接
    session.open();
    // 启用 STARTTLS 加密
    session.startTLS();
    // 登录 SMTP
    session.login(SMTPClientSession::AUTH_LOGIN,"790238255@qq.com","glfnnduoqpqmbbdb");

    // 构造邮件
    MailMessage message;
    message.setSender("790238255@qq.com");// 发件人
    message.addRecipient(MailRecipient(MailRecipient::PRIMARY_RECIPIENT,"3229321828@qq.com"));// 收件人
    message.setSubject("STARTTLS 测试邮件");// 邮件标题
    message.addContent(new StringPartSource("这是一封通过 STARTTLS 发送的测试邮件(带附件)。","text/plain"));// 邮件内容
    message.addAttachment("module.cmake",new FilePartSource("/Users/icy-joker/WorkSpace/SimpleUseCase/src/SimpleUseCase/module.cmake"));// 添加附件（指定文件路径）

    // 发送邮件
    session.sendMessage(message);

    session.close();

    std::cout << "邮件发送成功！" << std::endl;
  }
  catch(Poco::Exception& error)
  {
    std::cerr << "错误: " << error.displayText() << std::endl;
  }

  return result;
}
