#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

int main(){
    double alpha = 0.5;
    double beta;
    double input;
    
    cv::Mat src1, src2, dst;

    std::cout << "Simple Linear Blender\n"
              << "-------------------------\n"
              << " Enter alpha [0.0 - 1.0]: ";
    std::cin >> input;

    // We use the alpha provided by the user if it is between 0 and 1
    if(input >= 0 && input <= 1){
        alpha = input;
    }

    try{
        src1 = cv::imread(cv::samples::findFile("LinuxLogo.jpg"));
        src2 = cv::imread(cv::samples::findFile("WindowsLogo.jpg"));
    }catch(const cv::Exception& e){
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }catch(const std::exception& e){
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }

    beta = 1.0 - alpha;
    cv::addWeighted(src1, alpha, src2, beta, 0.0, dst);

    cv::imshow("Linear Blend", dst);
    cv::waitKey(0);

    return 0;
}
