/*
 * GUIComponents.hpp
 *
 *  Created on: Oct 30, 2012
 *      Author: Steffen Radegast, Teena Hassan
 */

#ifndef GUICOMPONENTS_HPP_
#define GUICOMPONENTS_HPP_

#include <iostream>
#include <opencv2/opencv.hpp>

#define MAX_THRESHOLD 255
#define MAX_FILTER_SIZE 479
#define MAX_GRAYSCALE_INTENSITY 255
#define MIN_FILTER_SIZE 3
#define ASCII_ESC 27
#define DEFAULT_THRESHOLD_VALUE 64
#define DEFAULT_GRAYSCALE_INTENSITY 100
#define IMAGE_DEFAULT_SIZE_HEIGHT 1
#define IMAGE_DEFAULT_SIZE_WIDTH 640

using namespace cv;
using namespace std;

namespace GUIComponentsNS {

extern const string parameterSelectionWindow;
extern const string thresholdTrackbar;
extern const string thresholdLowTrackbar;
extern const string filterSizeTrackbar;
extern const string grayscaleIntensityTrackbar;

void pChanged( int, void* );

class GUIComponents {

private:
	static GUIComponents* instance;
	int thresholdValue;
	int thresholdValueLow;
	int filterSize;
	int grayscaleIntensity;
	Mat showingImage;

	GUIComponents() {
		thresholdValue = DEFAULT_THRESHOLD_VALUE;
		thresholdValueLow = DEFAULT_THRESHOLD_VALUE;
		filterSize = MIN_FILTER_SIZE;
		grayscaleIntensity = DEFAULT_GRAYSCALE_INTENSITY;
		showingImage = Mat::zeros( IMAGE_DEFAULT_SIZE_HEIGHT, IMAGE_DEFAULT_SIZE_WIDTH, CV_8UC3 );
	}

	GUIComponents( const GUIComponents & ); //disabled copy constructor

	GUIComponents& operator=( const GUIComponents & ); //disabled assignment operator

	void createParamWindow();

public:

	static GUIComponents* getInstance() {
		if ( instance == NULL ){
			cout << "Creating instance of GUIComponents..." << endl;
			instance = new GUIComponents();
		}
		return instance;
	}

	int getThresholdValue();

	int getThresholdValueLow();

	int getFilterSize();

	int getGrayscaleIntensity();

	void checkFilterSize();

	void displayParameters();

	void showParamWindow();

	~GUIComponents() {
		delete GUIComponents::instance;
	}

};

} //end of namespace GUIComponentsNS


#endif /* GUICOMPONENTS_HPP_ */
