# Bad Apple Terminal Player

A simple C++ ASCII video player that converts a video into terminal frames using OpenCV.

## Requirements

- C++20 compiler (`g++`)
- OpenCV 4
- FFmpeg (required for video decoding support)

### Debian / Ubuntu

Install dependencies:

```bash
sudo apt update
sudo apt install g++ make libopencv-dev ffmpeg
```

### Download the video

This project does not include the video file. You need to download it separately.

The video used for testing was:
<a href="https://youtu.be/FtutLA63Cp8?si=lOEWFApOsyWXAurB">
Youtube link
</a>

You can download it using `yt-dlp`:
```bash
yt-dlp -o badApple.mp4 "https://youtu.be/FtutLA63Cp8?si=lOEWFApOsyWXAurB"
```
The file must be named: `badApple.mp4` and placed in the project `root`:
```
BadApple/
├── BadApple.mp4
├── badApple.cpp
├── Video.class.hpp
├── Makefile
└── README.md
```

### Build

Run on your terminal:
```bash
make
```
then:
```
./badApple
```