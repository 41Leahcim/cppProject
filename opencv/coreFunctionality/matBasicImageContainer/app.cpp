#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

void pause(){
    std::cout << "\nPress enter to continue...";
    std::string wasted;
    std::getline(std::cin, wasted);
    std::cout << "\n";
}

void mat(const char **args){
    // creates just the header parts
    cv::Mat a, c;

    // read the image for the method used (allocates the matrix)
    a = cv::imread(args[1], cv::IMREAD_COLOR);

    // copy the image to b (image data won't be copied, only the image pointer and headers)
    cv::Mat b(a);

    // assign the image to c
    c = a;

    // select a part of the image using a rectangle
    cv::Mat d(a, cv::Rect(10, 10, 100, 100));

    // select a part of the image using row and column boundaries
    cv::Mat e = a(cv::Range::all(), cv::Range(1, 3));

    // create 2 copies of the entire image (including data)
    cv::Mat f = a.clone();
    cv::Mat g;
    a.copyTo(g);
}

void creatingMatObjectExplicitly(){
    // create a 2 by 2 matrix filled with (0, 0, 255) and display it
    // type is defined as CV_[bits per item][Signed or Unsigned][type prefix][channel number]
    // CV_8UC3 = 8 bit unsigned char, 3 of these (3 channels) per pixel
    cv::Mat m(2, 2, CV_8UC3, cv::Scalar(0, 0, 255));
    std::cout << "M =\n" << m << "\n\n";

    // create an array consisting of 3 integers and use it to create a new matrix
    // specify the dimension of the array and pass the array, the values will be used as size for each dimension
    int sz[3] = {2, 2, 2};
    cv::Mat l(3, sz, CV_8UC(1), cv::Scalar::all(0));

    // matrix l, can't be displayed

    // resize matrix m and display it
    // only reallocates if the new matrix doesn't fit into the old one (which is the case here)
    // you can't initialize the matrix with this construction
    m.create(2, 2, CV_8UC(2));
    std::cout << "M =\n" << m << "\n\n";

    // create a 4 by 4 matrix 64-bit floats
    // filled with zeroes, except for a diagonal line top left to bottom right of ones
    cv::Mat e = cv::Mat::eye(4, 4, CV_64F);
    std::cout << "E =\n" << e << "\n\n";

    // create a 2 by 2 matrix 32-bit floats filled with ones
    cv::Mat o = cv::Mat::ones(2, 2, CV_32F);
    std::cout << "O =\n" << o << "\n\n";

    // create a 3 by 3 matrix of 8-bit unsigned chars filled with zeroes
    cv::Mat z = cv::Mat::zeros(3, 3, CV_8UC1);
    std::cout << "Z =\n" << z << "\n";

    // comma seperated initializer
    cv::Mat c = (cv::Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1.1, 0.5, -1, 0);
    std::cout << "C =\n" << c << "\n\n";

    // initializer list
    c = (cv::Mat_<double>({0, -1, 0, -1, 5, -1.1, 0.5, -1, 0})).reshape(3);
    std::cout << "C =\n" << c << "\n\n";

    // create new header for existing Matrix object and clone or copyTo it
    cv::Mat rowClone = c.row(1).clone();
    std::cout << "RowClone =\n" << rowClone << "\n\n";

    // fill matrix with random values
    cv::Mat r = cv::Mat(3, 2, CV_8UC3);
    cv::randu(r, cv::Scalar::all(0), cv::Scalar::all(255));
}

// next: output formatting
void outputFormatting(){
    // fill matrix with random values
    cv::Mat r = cv::Mat(3, 2, CV_8UC3);
    cv::randu(r, cv::Scalar::all(0), cv::Scalar::all(255));

    // display R with all of the different formats
    std::cout << "R (Default) =\n" << r << "\n\n";
    std::cout << "R (Python) =\n" << cv::format(r, cv::Formatter::FMT_PYTHON) << "\n\n";
    std::cout << "R (Csv) =\n" << cv::format(r, cv::Formatter::FMT_CSV) << "\n\n";
    std::cout << "R (Numpy) =\n" << cv::format(r, cv::Formatter::FMT_NUMPY) << "\n\n";
    std::cout << "R (C) =\n" << cv::format(r, cv::Formatter::FMT_C) << "\n\n";
    std::cout << "R (Matlab) =\n" << cv::format(r, cv::Formatter::FMT_MATLAB) << "\n\n";
}

void outputOtherComponents(){
    // create and display the coordinates a point in 2D space
    cv::Point2f p2(5, 1);
    std::cout << "Point (2D) = " << p2 << "\n\n";

    // create and display the coordinates a point in 3D space
    cv::Point3f p3(2, 6, 7);
    std::cout << "Point (3D) = " << p3 << "\n\n";

    // create a vector and display it as a Matrix
    std::vector<float> floatVector = {(float)CV_PI, 2, 3.01f};
    std::cout << "Vector of floats via Mat = " << cv::Mat(floatVector) << "\n\n";

    // create and display a vector of points
    std::vector<cv::Point2f> point2fVector(20);
    for(size_t i = 0;i < point2fVector.size();i++){
        point2fVector.emplace_back(i * 5.0f, float(i % 7));
    }
    std::cout << "A vector of 2D points = " << point2fVector << "\n\n";
}

int main(int argc, const char **args){
    if(argc >= 2){
        mat(args);
        pause();
    }
    creatingMatObjectExplicitly();
    pause();
    outputFormatting();
    pause();
}
