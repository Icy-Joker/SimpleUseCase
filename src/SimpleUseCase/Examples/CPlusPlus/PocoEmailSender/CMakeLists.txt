#
set(BOOST_MODULE_LIST "thread;system;filesystem;date_time;program_options;regex;atomic;chrono;")#配置Boost模块
#
#set(QT_MODULE_LIST "Core;Gui;Widgets;")#配置Qt模块
#
set(THIRD_LIBRARY_LIST "icu4c;Poco;OpenSSL;")#配置其他三方库
#
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED "ON")

generateExecutableProgram()#生成可执行程序
#
#target_compile_definitions("${CURRENT_TARGET}" PRIVATE "")#添加预处理宏
#
#target_link_libraries("${CURRENT_TARGET}" PRIVATE "")#添加依赖库
target_link_libraries("${CURRENT_TARGET}" PRIVATE "PocoFoundation;PocoNet;PocoNetSSL;")#
if(UNIX)
  target_link_libraries("${CURRENT_TARGET}" PRIVATE "OpenSSL::SSL;OpenSSL::Crypto;")#
else()
  target_link_libraries("${CURRENT_TARGET}" PRIVATE "libssl;libcrypto;")#
endif()
#
install(TARGETS ${CURRENT_TARGET} RUNTIME DESTINATION "test/bin" LIBRARY DESTINATION "test/bin")
