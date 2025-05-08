#include "stdafx.h"

#include <boost/program_options.hpp>

#include <iostream>

int main(int argc,char* argv[])
{
  int result = 0;

  //简单示例
  boost::program_options::options_description simple_description("For Simple Case");
  simple_description.add_options()
      ("single_command,s",boost::program_options::value<std::string>(),"单项参数:string");
  //高级示例
  boost::program_options::options_description advance_description("For Advance Case");
  advance_description.add_options()
      ("default_value,d",boost::program_options::value<std::string>()->default_value("default_value"),"单项参数:string(默认值:default_value)")
      ("multi_command,m",boost::program_options::value<std::vector<std::string>>()->multitoken(),"多项参数:vector<string>")
      ("enable_flag,e","隐式参数:无需赋值");
  //
  boost::program_options::options_description description_global("Allowed options");
  description_global.add_options()
      ("help,h","打印此帮助信息");
  description_global.add(simple_description);
  description_global.add(advance_description);

  boost::program_options::variables_map map_variables;
  try
  {
    boost::program_options::store(boost::program_options::command_line_parser(argc,argv).options(description_global).run(),map_variables);
    boost::program_options::notify(map_variables);

    if(argc > 1 && !map_variables.count("help"))
    {
      if(map_variables.count("single_command"))
      {
        const std::string single_command = map_variables["single_command"].as<std::string>();
        std::cout << "using single_command:" << single_command << std::endl;
      }

      const std::string default_value = map_variables["default_value"].as<std::string>();
      std::cout << "using default_value:" << default_value << std::endl;

      if(map_variables.count("multi_command"))
      {
        const std::vector<std::string> multi_command = map_variables["multi_command"].as<std::vector<std::string>>();
        std::for_each(multi_command.begin(),multi_command.end(),[&](const std::string current_argument)
        {
          std::cout << "using multi_command:" << current_argument << std::endl;
        });
      }

      std::cout << (map_variables.count("enable_flag") ? "used" : "not used") << " enable_flag" << std::endl;
    }
    else
    {
      description_global.print(std::cout,'f');
    }
  }
  catch(boost::program_options::error& error)
  {
    std::cout << error.what() << std::endl;
  }
  catch(...)
  {
    std::cout << "Unknown error!" << std::endl;
  }

  return result;
}
