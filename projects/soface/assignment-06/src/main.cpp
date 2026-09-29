// File for sandboxing and trying out code

// in the sandbox my comments will be less for calrification 
// and more to write down my understanding
// so a little more rambling

#include <fstream>
#include <vector>
#include <cstdint>
#include <iostream>

// prototype
std::vector<uint8_t> get_image(const std::string& filename);
void save_image(const std::string& filename, const std::vector<uint8_t>& data);

int main(int argc, char **argv)
{
    // for some reason I decided to implement the function
    // so my main takes a jpg name from the folder and copy it
    // while adding copy to the name

    // argc is irrelevant we only ever have one case

    std::string folder = "../";
    // needs to be adjusted for whatever path is required
    // alternatively can directly refer to it such as C:/folder1/folder2...
    // but for this assignment we are going to assume this structure where 
    // the image is in the folder that our current location is in

    std::string filename = argv[1];
    // format the filename

    try
    {
        std::string path = folder + filename;
        // combine them to make a string that has the relevant path

        std::vector<uint8_t> image = get_image(path);
        // use the function with the path

        // add copy to filename so we get the desired handle

        save_image(filename, image);
        // save image with new handle
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

std::vector<uint8_t> get_image(const std::string& filename)
{
    // open the file as binary
    // this avoids any sort of issue with transfering the data
    std::ifstream file(filename, std::ios::binary);

    // ifstream is opening to read

    // std check if file opened
    if (!file) {
        throw std::runtime_error("Could not open image file");
    }

    // move the read point to the end of the file
    file.seekg(0, std::ios::end);
    // call .tellg() to give us the location of our readpointer in relation to the start of the document
    size_t size = file.tellg();
    // move back to the front so we can read the file correctly
    file.seekg(0, std::ios::beg);

    // create vector with correct size
    // it allocates size amount of bytes which is equivalent to the amount of bytes
    // we read above
    std::vector<uint8_t> buffer(size);
    // this type of array is ideal for transferring binary

    // read file into vector
    // we need to typecast the buffer.data() since it returns uint8_t*
    // and read required char*
    file.read(reinterpret_cast<char*>(buffer.data()), size);

    return buffer;
}

void save_image(const std::string& filename, const std::vector<uint8_t>& data)
{
    // create handle
    std::string modification = "copy";
    std::string newhandle = modification + filename;
    std::string folder = "../";
    std::string path = folder + newhandle;

    // again we need to open a binary file this one will be empty
    std::ofstream file(path, std::ios::binary);
    // std::ios::binary has an implied std::ios::out which implies std::ios::trunc
    // for ofstream so when we open it even if there alreadt is a copyfilename.jpg
    // it will be deleted and the new will be put in its place

    // ofstream is opening to write

    // std check if file opened
    if (!file) {
        throw std::runtime_error("Could not open image file for writing");
    }

    // we need to typecast since write requires char* and data is uint8_t*
    file.write(reinterpret_cast<const char*>(data.data()), data.size());
    // we write data into our empty file
}