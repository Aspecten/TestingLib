#include <iostream>
#include <fstream>
// Указать путь к json.hpp
#include "C:\Users\fanto\Desktop\testing\Testing\task3\task3\json.hpp"

using json = nlohmann::json;
using namespace std;

void fillValues(json& tests, const json& values_map) {
    if (tests.contains("id")) {
        int id = tests["id"];
        if (values_map.contains(to_string(id))) {
            tests["value"] = values_map.at(to_string(id));
        }
    }

    if (tests.contains("values")) {
        for (auto& subtest : tests["values"]) {
            fillValues(subtest, values_map);
        }
    }
}

int main() {
    // Указание путей к файлам 
    string testsFilePath = "C:\\Users\\fanto\\Desktop\\testing\\Testing\\task3\\task3\\tests.json";
    string valuesFilePath = "C:\\Users\\fanto\\Desktop\\testing\\Testing\\task3\\task3\\values.json";
    string reportFilePath = "C:\\Users\\fanto\\Desktop\\testing\\Testing\\task3\\task3\\report.json";

    ifstream valuesFile(valuesFilePath);
    if (!valuesFile.is_open()) {
        cerr << "Fall: can not open values.json." << endl;
        return 1;
    }

    json valuesJson;
    valuesFile >> valuesJson;
    valuesFile.close();

    json values_map;
    for (const auto& item : valuesJson["values"]) {
        values_map[to_string(item["id"].get<int>())] = item["value"];
    }

    ifstream testsFile(testsFilePath);
    if (!testsFile.is_open()) {
        cerr << "Fall: can not open tests.json." << endl;
        return 1;
    }

    json testsJson;
    testsFile >> testsJson;
    testsFile.close();

    for (auto& test : testsJson["tests"]) {
        fillValues(test, values_map);
    }

    ofstream reportFile(reportFilePath);
    if (!reportFile.is_open()) {
        cerr << "Fall: can not report.json for record." << endl;
        return 1;
    }

    reportFile << testsJson.dump(4); 
    reportFile.close();

    cout << "Succes:  " << reportFilePath << endl;

    return 0;
}