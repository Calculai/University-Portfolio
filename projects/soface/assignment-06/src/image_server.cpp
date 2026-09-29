//
// server.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2019 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <boost/asio.hpp>

#include <fstream>
// decided to use fstream for file handling
// alternatively could have used stdio

using boost::asio::ip::tcp;

// Implement this:
std::vector<uint8_t> get_image()
{
  // open file in read mode as binary 
  std::ifstream file("cat.jpg", std::ios::binary);

  // std check if file opened
  if (!file) {
    throw std::runtime_error("Could not open image file");
  }

  // using readpointer to determine filelength
  file.seekg(0, std::ios::end);
  size_t size = file.tellg();
  file.seekg(0, std::ios::beg);

  // create vector with correct size
  std::vector<uint8_t> buffer(size);

  // read file into vector
  // we typecast since .read(char*,int) and buffer.data() returns uint8_t*
  file.read(reinterpret_cast<char*>(buffer.data()), size);

  return buffer;
  
}

int main()
{
  try
  {
    boost::asio::io_context io_context;

    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 13));

    while (true)
    {
      tcp::socket socket(io_context);
      acceptor.accept(socket);

      auto message = get_image();

      boost::system::error_code ignored_error;
      boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
    }
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}