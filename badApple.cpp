#include <iostream>
#include "Video.class.hpp"

int main() {
    try
    {
        Video video("BadApple.mp4");
        video.play();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
