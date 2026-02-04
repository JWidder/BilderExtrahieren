#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Usage: video_to_frames <video> <output_folder>\n";
        return 1;
    }

    std::string videoPath = argv[1];
    std::string outputFolder = argv[2];

    std::filesystem::create_directories(outputFolder);

    cv::VideoCapture cap(videoPath);
    if (!cap.isOpened()) {
        std::cerr << "Cannot open video: " << videoPath << "\n";
        return 1;
    }

    int frameIndex = 0;
    cv::Mat frame;

    while (cap.read(frame)) {
        std::string filename = outputFolder + "/frame_" + std::to_string(frameIndex) + ".png";
        cv::imwrite(filename, frame);
        frameIndex++;
    }

    std::cout << "Extracted " << frameIndex << " frames.\n";
    return 0;
}