#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/ml/ml.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

using namespace cv;
using namespace std;

//int left_sample = 1869;
//int left_mid_sample = 1247;
//int mid_sample = 1260;
//int right_mid_sample = 1341;
//int right_sample = 1721;

int left_sample = 1000;
int left_mid_sample = 1000;
int mid_sample = 1000;
int right_sample = 1000;
int right_mid_sample = 1000;

const string dir = "/Users/khuongnguyen/Desktop/New_SVM/";
int main()
{
    int num_files = left_sample + left_mid_sample + mid_sample + right_sample + right_mid_sample;
    int img_area = 320*240;
    Mat img_mat;
    int ii = 0;
    int counter = 0;
    Mat training_mat(num_files,img_area,CV_32FC1);
    Mat labels(num_files,1,CV_32FC1);
    
    //Construct trainning matrix for left region
    chdir("/Users/khuongnguyen/Desktop/New_SVM/Capture_Images_Left");
    for(int n = 0; n < left_sample; n++){
        const string file = to_string(n) + ".jpg";
        img_mat = imread(file,1); // I used 0 for greyscale
        cvtColor( img_mat, img_mat, CV_BGR2GRAY );
        GaussianBlur(img_mat, img_mat, Size(7,7), 1.5, 1.5);
        Canny(img_mat, img_mat, 0, 30, 3);
        resize(img_mat, img_mat, Size(320, 240), 0, 0, INTER_LINEAR);
        imwrite( dir + "Edge_Left/" + file, img_mat );
        ii = 0; // Current column in training_mat
        for (int i = 0; i<img_mat.rows; i++) {
            for (int j = 0; j < img_mat.cols; j++) {
                training_mat.at<float>(counter,ii++) = img_mat.at<uchar>(i,j);
            }
        }
        labels.at<float>(counter,0)=0;
        counter++;
    }
    
    //Construct trainning matrix for left_mid region
    chdir("/Users/khuongnguyen/Desktop/New_SVM/Capture_Images_Left_Mid");
    for(int n = 0; n < left_mid_sample; n++){
        const string file = to_string(n) + ".jpg";
        img_mat = imread(file,1); // I used 0 for greyscale
        cvtColor( img_mat, img_mat, CV_BGR2GRAY );
        GaussianBlur(img_mat, img_mat, Size(7,7), 1.5, 1.5);
        Canny(img_mat, img_mat, 0, 30, 3);
        resize(img_mat, img_mat, Size(320, 240), 0, 0, INTER_LINEAR);
        imwrite( dir + "Edge_Left_Mid/" + file, img_mat );
        ii = 0; // Current column in training_mat
        for (int i = 0; i<img_mat.rows; i++) {
            for (int j = 0; j < img_mat.cols; j++) {
                training_mat.at<float>(counter,ii++) = img_mat.at<uchar>(i,j);
            }
        }
        labels.at<float>(counter,0)=1;
        counter++;
    }
    
    //Construct trainning matrix for middle region
    chdir("/Users/khuongnguyen/Desktop/New_SVM/Capture_Images_Mid");
    for(int n = 0; n < mid_sample; n++){
        const string file = to_string(n) + ".jpg";
        img_mat = imread(file,1); // I used 0 for greyscale
        cvtColor( img_mat, img_mat, CV_BGR2GRAY );
        GaussianBlur(img_mat, img_mat, Size(7,7), 1.5, 1.5);
        Canny(img_mat, img_mat, 0, 30, 3);
        resize(img_mat, img_mat, Size(320, 240), 0, 0, INTER_LINEAR);
        imwrite( dir + "Edge_Mid/" + file, img_mat );
        ii = 0; // Current column in training_mat
        for (int i = 0; i<img_mat.rows; i++) {
            for (int j = 0; j < img_mat.cols; j++) {
                training_mat.at<float>(counter,ii++) = img_mat.at<uchar>(i,j);
            }
        }
        labels.at<float>(counter,0)=2;
        counter++;
    }
    
    //Construct trainning matrix for right_mid region
    chdir("/Users/khuongnguyen/Desktop/New_SVM/Capture_Images_Right_Mid");
    for(int n = 0; n < right_mid_sample; n++){
        const string file = to_string(n) + ".jpg";
        img_mat = imread(file,1); // I used 0 for greyscale
        cvtColor( img_mat, img_mat, CV_BGR2GRAY );
        GaussianBlur(img_mat, img_mat, Size(7,7), 1.5, 1.5);
        Canny(img_mat, img_mat, 0, 30, 3);
        resize(img_mat, img_mat, Size(320, 240), 0, 0, INTER_LINEAR);
        imwrite( dir + "Edge_Right_Mid/" + file, img_mat );
        ii = 0; // Current column in training_mat
        for (int i = 0; i<img_mat.rows; i++) {
            for (int j = 0; j < img_mat.cols; j++) {
                training_mat.at<float>(counter,ii++) = img_mat.at<uchar>(i,j);
            }
        }
        labels.at<float>(counter,0)=3;
        counter++;
    }
    
    //Construct trainning matrix for right region
    chdir("/Users/khuongnguyen/Desktop/New_SVM/Capture_Images_Right");
    for(int n = 0; n < right_sample; n++){
        const string file = to_string(n) + ".jpg";
        img_mat = imread(file,1); // I used 0 for greyscale
        cvtColor( img_mat, img_mat, CV_BGR2GRAY );
        GaussianBlur(img_mat, img_mat, Size(7,7), 1.5, 1.5);
        Canny(img_mat, img_mat, 0, 30, 3);
        resize(img_mat, img_mat, Size(320, 240), 0, 0, INTER_LINEAR);
        imwrite( dir + "Edge_Right/" + file, img_mat );
        ii = 0; // Current column in training_mat
        for (int i = 0; i<img_mat.rows; i++) {
            for (int j = 0; j < img_mat.cols; j++) {
                training_mat.at<float>(counter,ii++) = img_mat.at<uchar>(i,j);
            }
        }
        labels.at<float>(counter,0)=4;
        counter++;
    }
    
    CvSVMParams params;
    params.svm_type = CvSVM::C_SVC;
    params.kernel_type = CvSVM::POLY;
    params.gamma=3;
    params.degree=2;
    params.term_crit =cvTermCriteria(CV_TERMCRIT_ITER, 100, 1e-6);
    
    CvSVM svm;
    svm.train(training_mat, labels, Mat(), Mat(), params);
    
    chdir("/Users/khuongnguyen/Desktop/New_SVM/");
    svm.save("learned_lib");
    
    return 0;
}
