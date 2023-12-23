#pragma once
#include<vector>
#include<string>
#include "MachineManifest.h"
#include "GroupsAndStates.hpp"

class CalibrationData {
private:
	std::vector<std::string> deactivatedFunctionGroups_;
	rapidjson::Document document;

public:
	CalibrationData();
	CalibrationData(std::string CalibrationDataPath);
	void parseCalibrationData();
	std::vector<std::string> GetDeactivatedFunctionGroups();

};
