#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

int main(int argc, const char **args){
    // get the path to the image file
    std::string fileName;
    if(argc > 1){
        fileName = args[1];
    }else{
        std::cout << "Enter the path to the file: ";
        std::getline(std::cin, fileName);
    }

    // load the image
    cv::Mat colorImage = cv::imread(fileName);
    cv::Mat grayscaleImage = cv::imread(fileName, cv::IMREAD_GRAYSCALE);

    // display the intensity of pixel (y 1, x 1), and then (x 1, y 1)
    std::cout << "Pixel intensity (1, 1): " << (uint32_t)colorImage.at<uchar>(1, 1) << "\n";
    std::cout << "Pixel intensity (1, 1): " << (uint32_t)grayscaleImage.at<uchar>(cv::Point(1, 1)) << "\n\n";

    // display the seperate color values of pixel (y 1, x 1)
    cv::Vec3b intensity = colorImage.at<cv::Vec3b>(1, 1);
    std::cout << "BGR(" << (uint32_t)intensity.val[0] << ", " << (uint32_t)intensity.val[1] << ", " << (uint32_t)intensity.val[2] << ");\n";

    // display the floating color values of pixel (y 1, x 1)
    cv::Vec3f floatIntensity = colorImage.at<cv::Vec3b>(1, 1);
    std::cout << "BGR(" << floatIntensity.val[0] << ", " << floatIntensity.val[1] << ", " << floatIntensity.val[2] << ");\n";

    // change pixel intensity (y 1, x 1)
    colorImage.at<uchar>(1, 1) /= 2;

    // create a vector of points and create a matrix with it
    std::vector<cv::Point2f> points;
    cv::Mat pointsMat(points);

    if(pointsMat.dims == 2 && pointsMat.cols > 1 && pointsMat.rows > 1){
        cv::Point2f point = pointsMat.at<cv::Point2f>(1, 0);
        std::cout << point << "\n";
    }

    // create a vector of points, create a reshaped matrix with it
    std::vector<cv::Point3f> points2;
    cv::Mat pointsMat2 = cv::Mat(points).reshape(1);

    // clone the grayscale image
    cv::Mat grayscaleImage2 = grayscaleImage.clone();

    // apply a function to grayscaleImage2 and store the result in a new matrix
    cv::Mat sobelx;
    cv::Sobel(grayscaleImage2, sobelx, CV_32F, 1, 0);

    // turn grayscale image 2 black
    grayscaleImage2 = cv::Scalar(0);

    // select a region of interest
    cv::Rect r(10, 10, 100, 100);
    cv::Mat smallImage = colorImage(r);

    // convert the color image to grayscale
    cv::Mat gray;
    cv::cvtColor(colorImage, gray, cv::COLOR_BGR2GRAY);

    // change image type to 32FC1
    gray.convertTo(gray, CV_32F);

    // display an image an wait until the use presses a key
    cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
    cv::imshow("image", colorImage);
    cv::waitKey();

    // find and display the minimum and maximum intensity
    double minimumIntensity, maximumIntensity;
    cv::minMaxLoc(sobelx, &minimumIntensity, &maximumIntensity);
    std::cout << "Minimum intensity: " << minimumIntensity << "\n"
              << "Maximum intensity: " << maximumIntensity << "\n\n";
    
    // convert sobelx to an 8U type, so we can display it
    // cv::namedWindow is not needed here as we have already created the image window, and it is immediately followed by cv::imshow
    // It could still be used to change window properties or when using cv::createTrackbar
    sobelx.convertTo(sobelx, CV_8U, 255.0 / (maximumIntensity - minimumIntensity), -minimumIntensity * 255.0 / (maximumIntensity - minimumIntensity));
    cv::imshow("image", sobelx);
    cv::waitKey();

    // save the image
    cv::imwrite("out_" + fileName, colorImage);
    cv::imwrite("outGray_" + fileName, grayscaleImage);
}
