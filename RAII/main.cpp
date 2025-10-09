#include <iostream>
#include <fstream>

// Raii class manage file resources
class FileRAII
{
    std::ofstream file;

public:
    FileRAII(std::string_view fileName)
    {
        file.open(fileName.data());

        if (!file.is_open())
        {
            throw std::runtime_error(std::string("File can not be open ") + fileName.data());
        }

        std::clog << "File opened " << fileName.data() << std::endl;
    }

    void writeLine(std::string_view text)
    {
        file << text << "\n";
    }

    ~FileRAII()
    {
        if (file.is_open())
        {
            file.close();
            std::clog << "File closed." << std::endl;
        }
    }
};

// Raii class manage dynamic memory resources
class IntArrayRAII
{
    int *data{};
    std::size_t size{};

public:
    IntArrayRAII(std::size_t size_) : size(size_)
    {
        data = new int[size]{}; // all elements initialize to 0

        std::clog << "Memory allocated of size " << size << " integer" << std::endl;
    }

    int &operator[](std::size_t index)
    {
        return data[index];
    }

    ~IntArrayRAII()
    {
        delete[] data;

        std::clog << "Memory released." << std::endl;
    }
};

int main(int argc, char *argv[])
{
    try
    {
        {
            FileRAII file("test.txt");
            file.writeLine("hello shiv");
            file.writeLine("bye bye.");
        }

        {
            IntArrayRAII array(5);

            for (std::size_t i = 0; i < 5; ++i)
            {
                array[i] = static_cast<int>(i * 10);
            }

            for (std::size_t i = 0; i < 5; ++i)
            {
                std::clog << array[i] << std::endl;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::clog << "main exit." << std::endl;

    return 0;
}