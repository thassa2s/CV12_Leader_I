/*
 * GUIComponents.cpp
 *
 *  Created on: Oct 29, 2012
 *      Author: Steffen Radegast, Teena Hassan
 */

#include "GUIComponents.hpp"

namespace GUIComponentsNS {

GUIComponents* GUIComponents::instance = NULL;

const string parameterSelectionWindow( "Parameter Selection" );
const string thresholdTrackbar( "Threshold Value: " );
const string thresholdLowTrackbar( "Threshold Value Low: " );
const string filterSizeTrackbar( "Filter Size: " );
const string grayscaleIntensityTrackbar( "Grayscale Intensity: " );


void GUIComponents::createParamWindow() {
	namedWindow( parameterSelectionWindow, CV_WINDOW_AUTOSIZE|CV_GUI_EXPANDED );
	createTrackbar( thresholdTrackbar, parameterSelectionWindow, &(this->thresholdValue), MAX_THRESHOLD, pChanged );
	createTrackbar( thresholdLowTrackbar, parameterSelectionWindow, &(this->thresholdValueLow), MAX_THRESHOLD, pChanged );
	createTrackbar( filterSizeTrackbar, parameterSelectionWindow, &(this->filterSize), MAX_FILTER_SIZE, pChanged );
	createTrackbar( grayscaleIntensityTrackbar, parameterSelectionWindow, &(this->grayscaleIntensity), MAX_GRAYSCALE_INTENSITY, pChanged );
}

int GUIComponents::getThresholdValue() {
	return thresholdValue;
}

int GUIComponents::getThresholdValueLow() {
	return thresholdValueLow;
}

int GUIComponents::getFilterSize() {
	return filterSize;
}

int GUIComponents::getGrayscaleIntensity() {
	return grayscaleIntensity;
}

void GUIComponents::checkFilterSize() {
	if ( this->filterSize % 2 == 0 ) {
		this->filterSize--;
	}
	if ( this->filterSize < MIN_FILTER_SIZE ) {
		this->filterSize = MIN_FILTER_SIZE;
	}
	setTrackbarPos( GUIComponentsNS::filterSizeTrackbar, GUIComponentsNS::parameterSelectionWindow, this->filterSize);
}

void GUIComponents::displayParameters() {
	cout << "********" << endl;
	cout << "Thresold Value: " << this->thresholdValue << endl;
	cout << "Thresold Value Low: " << this->thresholdValueLow << endl;
	cout << "Filter Size: " << this->filterSize << endl;
	cout << "Grayscale Intensity: " << this->grayscaleIntensity << endl;
	cout << "********" << endl;
}

void GUIComponents::showParamWindow() {
	this->createParamWindow();
	//Create a new thread to listen for events
	do{
		imshow( GUIComponentsNS::parameterSelectionWindow, this->showingImage );
	}while ( waitKey(0) != 27);
}

void pChanged( int, void* ) {
	GUIComponents* guiComp = GUIComponents::getInstance();
	guiComp->checkFilterSize();
	guiComp->displayParameters();
}

}
