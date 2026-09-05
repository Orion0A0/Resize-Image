#include <filesystem>
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>


/*
 * Purpose:      Resize every image in the given folder to a given size
 * 1st argument: width
 * 2nd argument: height
 * 3rd argument: absolute path to source folder (optional)
 * 4th argument: absolute path to destination  folder (optional)
 * Return:       in the given PATH or DEFAULT_DESTINATION
 */
#define DEFAULT_DESTINATION "/home/orion/Documents/src/processImg/destination"
#define DEFAULT_SOURCE "/home/orion/Documents/src/processImg/source"


void resizeAll(const std::filesystem::path& source, const std::filesystem::path& destination, const int width, const int height);


int main(const int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Invalid Argument. Need at least 2 arguments." << std::endl;
        return -1;
    }

    //  initializing
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    std::filesystem::path destination;
    std::filesystem::path source;

    if (width <= 0 || height <= 0)
    {
        std::cout << "invalid 1st or 2nd argument. Please enter integer only";
        return -2;
    }

    // set the path to default if it wasn't given
    if (argc < 4)
    {
        source = DEFAULT_SOURCE;
        destination = DEFAULT_DESTINATION;
    }
    else
        source = argv[3];

    // set path if destination was given
    if (argc == 4)
        destination = argv[4];

    if (!std::filesystem::exists(source))
        std::cout << "input source folder doesn't exist";

    resizeAll(source, destination, width, height);

    return 0;
}
void resizeAll(const std::filesystem::path& source, const std::filesystem::path& destination, const int width, const int height)
{
    // create a folder with the given path
    std::filesystem::create_directories(destination);
    cv::Mat src;
    cv::Mat dst;

    int file_count = 1;
    for (const auto& entry : std::filesystem::directory_iterator{source} )
    {
        if (!entry.exists())
        {
            std::cout << entry.path() << " does not exist" << std::endl;
            continue;
        }
        src =  cv::imread(entry.path());
        // check if imread successfully
        if (src.empty())
            continue;
        cv::resize(src, dst, cv::Size{width, height});
        cv::imwrite(destination.string() + "/" + std::to_string(file_count) + ".jpg", dst);
        std::cout << "Resized " << file_count++ << "th image.\n";
    }
}
