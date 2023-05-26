#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Symptom {
public:
    string name;
    bool present;

    Symptom(const string& name) : name(name), present(false) {}
};

class Disease {
public:
    string name;
    vector<string> symptoms;

    Disease(const string& name, const vector<string>& symptoms)
        : name(name), symptoms(symptoms) {}
};

bool askSymptom(const string& symptomName) {
    string response;
    cout << "Is the symptom '" << symptomName << "' present? (yes/no): ";
    cin >> response;
    return response == "yes";
}

string diagnoseDisease(const map<string, Symptom>& symptoms, const vector<Disease>& diseases) {
    for (const auto& disease : diseases) {
        bool diseasePresent = true;
        for (const auto& symptom : disease.symptoms) {
            if (!symptoms.at(symptom).present) {
                diseasePresent = false;
                break;
            }
        }
        if (diseasePresent) {
            return disease.name;
        }
    }
    return "Unknown";
}

int main() {
    // Define the symptoms
    map<string, Symptom> symptoms = {
        {"fever", Symptom("fever")},
        {"cough", Symptom("cough")},
        {"headache", Symptom("headache")},
        {"fatigue", Symptom("fatigue")},
        {"nausea", Symptom("nausea")}
    };

    // Define the diseases and their associated symptoms
    vector<Disease> diseases = {
        Disease("Common Cold", {"fever", "cough", "headache"}),
        Disease("Flu", {"fever", "cough", "fatigue"}),
        Disease("Migraine", {"headache", "nausea"}),
        Disease("COVID-19", {"fever", "cough", "fatigue", "nausea"})
    };

    // Ask for symptoms and update their presence
    for (auto& symptom : symptoms) {
        symptom.second.present = askSymptom(symptom.second.name);
    }

    // Diagnose the disease based on symptoms
    string diagnosis = diagnoseDisease(symptoms, diseases);

    cout << "\nDiagnosis: " << diagnosis << endl;

    return 0;
}
