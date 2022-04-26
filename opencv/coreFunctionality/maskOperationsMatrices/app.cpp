#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

static void help(const char *programName){
    std::cout << "This program shows how to filter images with a mask: the write it yourself and the filter2d way.\n"
              << "Usage:\n" << programName << " [image_path -- default lena.jpg] [G -- grayscale]\n\n"; 
}

void Sharpen(const cv::Mat& image, cv::Mat& result);

int main(int argc, const char **args){
    help(args[0]);
    const char *fileName = argc >= 2 ? args[1] : "lena.jpg";

    cv::Mat src, dst0, dst1;

    if(argc >= 3 && strcmp("G", args[2]) == 0){
        src = cv::imread(cv::samples::findFile(fileName), cv::IMREAD_GRAYSCALE);
    }else{
        src = cv::imread(cv::samples::findFile(fileName), cv::IMREAD_COLOR);
    }

    if(src.empty()){
        std::cerr << "Can't open image [" << fileName << "]\n";
        return EXIT_FAILURE;
    }

    cv::namedWindow("Input", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Output", cv::WINDOW_AUTOSIZE);

    cv::imshow("Input", src);
    double t = static_cast<double>(cv::getTickCount());
    
    Sharpen(src, dst0);

    t = (static_cast<double>(cv::getTickCount()) - t) / cv::getTickFrequency();
    std::cout << "Hand written function time passed in seconds: " << t << "\n";

    cv::imshow("Output", dst0);
    cv::waitKey();

    cv::Mat kernel = (cv::Mat_<char>(3, 3) <<  0, -1,  0,
                                              -1,  5, -1,
                                               0, -1,  0);

    t = static_cast<double>(cv::getTickCount());

    cv::filter2D(src, dst1, src.depth(), kernel);
    t = (static_cast<double>(cv::getTickCount()) - t) / cv::getTickFrequency();

    std::cout << "Built-in filter2D time passed in seconds: " << t << "\n";

    cv::imshow("Output", dst1);

    cv::waitKey();
    return EXIT_SUCCESS;
}

void Sharpen(const cv::Mat& image, cv::Mat& result){
    CV_Assert(image.depth() == CV_8U); // accept only uchar images

    const int nChannels = image.channels();
    result.create(image.size(), image.type());

    for(int x = 1;x < image.rows - 1;x++){
        const uchar *previous = image.ptr<uchar>(x - 1);
        const uchar *current  = image.ptr<uchar>(x);
        const uchar *next     = image.ptr<uchar>(x + 1);

        uchar *output = result.ptr<uchar>(x);
        for(int i = nChannels;i < nChannels * (image.cols - 1);i++){
            *(output++) = cv::saturate_cast<uchar>(5 * current[i] - current[i - nChannels] - current[i + nChannels] - previous[i] - next[i]);
        }
    }

    result.row(0).setTo(cv::Scalar(0));
    result.row(result.rows - 1).setTo(cv::Scalar(0));
    result.col(0).setTo(cv::Scalar(0));
    result.col(result.cols - 1).setTo(cv::Scalar(0));
}
