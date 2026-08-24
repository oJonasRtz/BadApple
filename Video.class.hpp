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
                    // int brightness = pixel[0];
                    int brightness =
                        0.114 * pixel[0] +
                        0.587 * pixel[1] +
                        0.299 * pixel[2];

                    if (brightness > 127)
                        line += this->white;
                    else
                        line += this->black;
                }

                buffer.push_back(line);
            }

            return buffer;
        };

        void    draw_frame(const t_frame &frame)
        {
            clearScreen();
            for (const std::string &line : frame)
                std::cout << line << '\n';
        }

        std::chrono::steady_clock::time_point getCurrentTime()
        {
            return std::chrono::steady_clock::now();
        }

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
            double frameDelay = 1000.0 / fps;
            cv::Mat frame;

            while (cap.read(frame))
            {
                auto start = getCurrentTime();

                t_frame renderedFrame = renderFrame(frame);
                draw_frame(renderedFrame);
                
                auto end = getCurrentTime();
                std::chrono::duration<double, std::milli> elapsed = end - start;
                wait(frameDelay - elapsed.count());
            }

        };
};

#endif // VIDEO_CLASS_HPP
