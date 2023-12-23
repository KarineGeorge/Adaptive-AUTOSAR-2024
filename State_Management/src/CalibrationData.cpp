#include"../inc/CalibirationData.hpp"

CalibrationData::CalibrationData()
{
}
CalibrationData::CalibrationData(std::string calibrationdatapath) {
	std::ifstream file(calibrationdatapath);
	if (!file) {
		std::cerr << "error opening file.\n";
		return;
	}
	std::ostringstream contentstream;
	contentstream << file.rdbuf();
	std::string jsonstring = contentstream.str();
	const char* json = jsonstring.c_str();
	document.Parse(json);
}
void CalibrationData::parseCalibrationData() {
	assert(document.HasMember("deactivated_function_groups"));
	assert(document["deactivated_function_groups"].IsArray());
	const rapidjson::Value& deactivated_function_groups = document["deactivated_function_groups"];
	for (rapidjson::Value::ConstValueIterator deactivated_function_group = deactivated_function_groups.Begin();
		deactivated_function_group != deactivated_function_groups.End(); deactivated_function_group++) {

		adp::sm::internal::GroupsAndStates functiongroupdeactivated;

		assert((*deactivated_function_group).HasMember("function_group"));
		assert((*deactivated_function_group)["function_group"].HasMember("name"));
		assert((*deactivated_function_group)["function_group"]["name"].IsString());
		functiongroupdeactivated.SetGroupName((*deactivated_function_group)["function_group"]["name"].GetString());
		deactivatedFunctionGroups_.push_back(functiongroupdeactivated.GetGroupName());
	}
}
std::vector<std::string> CalibrationData::GetDeactivatedFunctionGroups() {
	return this->deactivatedFunctionGroups_;
}
