/*
 * Master.cpp
 *
 *  Created on: Oct 29, 2012
 *      Author: Steffen Radegast, Teena Hassan
 */

#include "GUIComponents/GUIComponents.hpp"

int main( int argc, char* argv[] ) {
	GUIComponentsNS::GUIComponents* guiComp = GUIComponentsNS::GUIComponents::getInstance();
	guiComp->showParamWindow();
}
