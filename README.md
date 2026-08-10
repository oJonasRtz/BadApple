# Bad Apple Terminal Player

A simple C++ ASCII video player that converts a video into terminal frames using OpenCV.

This player opens an input MP4 with OpenCV, extracts each frame, converts pixel RGB values to ASCII characters (mapping brightness/color to a character set), assembles ASCII frames, and displays them in the terminal at playback speed.

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
yt-dlp -o video.mp4 "https://youtu.be/FtutLA63Cp8?si=lOEWFApOsyWXAurB"
```
Place your downloaded video file in the project root (the same directory as the source files and `Makefile`). You may use any filename.

### Build

Run on your terminal:
```bash
make
```
then:
```
./player
```

### Usage

The player requires an MP4 video file as input. Place an `.mp4` file in the project root, build the project with `make`, and run `./badApple`.

EX:
```
./player BadApple.mp4 
```