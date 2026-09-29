//
// client.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2019 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

#include <fstream>
// decided to use fstream for file handling
// alternatively could have used stdio

using boost::asio::ip::tcp;

constexpr size_t image_size = 100*100;

// Implement this:
void save_image(char* data, size_t len)
{
  // open file append write mode to accomodate datapackages
  std::ofstream file("copycat.jpg", std::ios::binary | std::ios::app);

  // for demonstration
  // Get-Item copycat.jpg
  // will make file bigger and bigger with each run

  // std check if file opened
  if (!file) {
      throw std::runtime_error("Could not open image file for writing");
  }

  // write the datapackage into the file
  file.write(data, len);
}

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Usage: client <host>" << std::endl;
      return 1;
    }

    boost::asio::io_context io_context;

    tcp::resolver resolver(io_context);
    tcp::resolver::results_type endpoints =
      resolver.resolve(argv[1], "daytime");

    tcp::socket socket(io_context);
    boost::asio::connect(socket, endpoints);

    while(true)
    {
      boost::array<char, image_size> buf;
      boost::system::error_code error;

      size_t len = socket.read_some(boost::asio::buffer(buf), error);

      if (error == boost::asio::error::eof)
        break;
      else if (error)
        throw boost::system::system_error(error);

      save_image(buf.data(), len);
    }
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}