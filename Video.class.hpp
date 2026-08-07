#ifndef VIDEO_CLASS_HPP
#define VIDEO_CLASS_HPP

# include <iostream>
# include <vector>
# include <string>
# include <thread>
# include <chrono>
# include <opencv2/opencv.hpp>

using t_frame = std::vector<std::string>;

class Video
{
    private:
        char        white;
        char        black;
        std::string filePath;

        void        clearScreen()
        {
            std::cout << "\033[H";
        };

        void        wait(double time)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(time)));
        }

        t_frame     renderFrame(const cv::Mat &cvframe)
        {
            t_frame  buffer;
            cv::Mat resized;
            cv::resize(cvframe, resized, cv::Size(120, 45));

            for (int y = 0; y < resized.rows; y++)
            {
                std::string line;

                for (int x = 0; x < resized.cols; x++)
                {
                    cv::Vec3b pixel = resized.at<cv::Vec3b>(y, x);
                    int brightness = pixel[0];

                    if (brightness > 127)
                        line += this->white;
                    else
                        line += this->black;
                }

                buffer.push_back(line);
            }

            return buffer;
        };
    public:
        Video(const std::string &filePath, const char whiteChar = '*', const char blackChar = ' ')
        {
            if (filePath.empty()
                || !filePath.ends_with(".mp4"))
                throw std::invalid_argument("File path cannot be empty.");


            this->filePath = filePath;
            this->white = whiteChar;
            this->black = blackChar;
        };
        ~Video() {};

        void play()
        {
            cv::VideoCapture cap(this->filePath);
            if (!cap.isOpened())
                throw std::runtime_error("Error opening video file.");

            double fps = cap.get(cv::CAP_PROP_FPS);
            cv::Mat frame;

            while (cap.read(frame))
            {
                t_frame renderedFrame = renderFrame(frame);
                clearScreen();

                for (const auto &line : renderedFrame)
                    std::cout << line << '\n';
                
                wait(1000 / fps);
            }

        };
};

#endif // VIDEO_CLASS_HPP
