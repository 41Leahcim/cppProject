#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

// the efficient way
cv::Mat& scanImageAndReduceC(cv::Mat& image, const uchar* const table){
    // accept only char type matrices
    CV_Assert(image.depth() == CV_8U);

    // retrieve image information
    int channels = image.channels();
    int numberRows = image.rows;
    int numberCols = image.cols * channels;

    // if the image is continuous, we can just iterate through the image as 1 row
    if(image.isContinuous()){
        numberCols *= numberRows;
        numberRows = 1;
    }

    // reduce the image
    int i, j;
    uchar *p;
    for(i = 0;i < numberRows;i++){
        p = image.ptr<uchar>(i);
        for(j = 0;j < numberCols;j++){
            p[j] = table[p[j]];
        }
    }
    return image;
}

cv::Mat& scanImageAndReduceIterator(cv::Mat& image, const uchar* const table){
    // accept only char type matrices
    CV_Assert(image.depth() == CV_8U);

    // get the number of channels in the image
    const int channels = image.channels();

    // reduce the image
    switch(channels){
        case 1:
            {
                cv::MatIterator_<uchar> it;
                cv::MatIterator_<uchar> end = image.end<uchar>();
                for(it = image.begin<uchar>();it != end;it++){
                    *it = table[*it];
                }
                break;
            }
        case 3:
            {
                cv::MatIterator_<cv::Vec3b> it;
                cv::MatIterator_<cv::Vec3b> end = image.end<cv::Vec3b>();
                for(it = image.begin<cv::Vec3b>();it != end;it++){
                    (*it)[0] = table[(*it)[0]];
                    (*it)[1] = table[(*it)[1]];
                    (*it)[2] = table[(*it)[2]];
                }
                break;
            }
    }
    return image;
}

// on-the-fly address calculation with reference returning
cv::Mat& scanImageAndReduceRandomAccess(cv::Mat& image, const uchar* const table){
    // accept only char type matrices
    CV_Assert(image.depth() == CV_8U);

    const int channels = image.channels();
    switch(channels){
        case 1:
            {
                for(int y = 0;y < image.rows;y++){
                    for(int x = 0;x < image.cols;x++){
                        image.at<uchar>(y, x) = table[image.at<uchar>(y, x)];
                    }
                }
                break;
            }
        case 3:
            {
                cv::Mat_<cv::Vec3b> image2 = image;
                for(int y = 0;y < image.rows;y++){
                    for(int x = 0;x < image.cols;x++){
                        image2(y, x)[0] = table[image2(y, x)[0]];
                        image2(y, x)[1] = table[image2(y, x)[1]];
                        image2(y, x)[2] = table[image2(y, x)[2]];
                    }
                }
                image = image2;
                break;
            }
    }
    return image;
}

void test(int argc, const char **args, cv::Mat& image, cv::Mat& (*function)(cv::Mat&, const uchar* const)){
    // return if there are not enough arguments
    if(argc < 3){
        std::cout << "ERROR: Not enough arguments!\n";
        return;
    }

    // convert the input string
    int divideWidth = 0;
    std::stringstream string;
    string << args[2];
    string >> divideWidth;
    
    // return if the number is invalid for the division
    if(!(string && divideWidth)){
        std::cout << "ERROR: Invalid number entered for dividing.\n";
        return;
    }

    uchar table[256];
    for(uint i = 0;i < 256;i++){
        table[i] = (uchar)(divideWidth * (i / divideWidth));
    }

    cv::Mat lookUpTable(1, 256, CV_8U);
    uchar *p = lookUpTable.ptr();
    for(int i = 0;i < 256;i++){
        p[i] = table[i];
    }

    // start the time measurement
    double time = (double)cv::getTickCount();

    if(function == NULL){
        cv::Mat copy;
        image.copyTo(copy);
        cv::LUT(copy, lookUpTable, image);
    }else{
        // do something
        function(image, table);
    }

    // calculate and display the elapsed time
    time = ((double)cv::getTickCount() - time) / cv::getTickFrequency();
    std::cout << "Time passed in seconds: " << time << "\n";
}

void testCase(int argc, const char **args, std::string savePrefix, cv::Mat& (*function)(cv::Mat&, const uchar* const)){
    cv::Mat image = cv::imread(args[1], cv::IMREAD_COLOR);
    test(argc, args, image, function);
    cv::imwrite(savePrefix + args[1], image);
}

void testCase(int argc, const char **args, cv::Mat& (*function)(cv::Mat&, const uchar* const)){
    cv::Mat image = cv::imread(args[1], cv::IMREAD_COLOR);
    test(argc, args, image, function);
}

int main(int argc, const char **args){
    testCase(argc, args, "reduceC", scanImageAndReduceC);
    testCase(argc, args, scanImageAndReduceIterator);
    testCase(argc, args, "ra", scanImageAndReduceRandomAccess);
    testCase(argc, args, NULL);
}
