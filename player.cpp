#include <iostream>
#include "Video.class.hpp"

static bool isValidFile(const std::string& filePath) {
    return !filePath.empty() && filePath.ends_with(".mp4");
}


int main(int ac, char** av) {
    if (ac != 2 || !isValidFile(av[1])) {
        std::cerr << "Usage: " << av[0] << " <video_file_path>" << std::endl;
        return 1;
    }

    try
    {
        Video video(av[1]);
        video.play();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
