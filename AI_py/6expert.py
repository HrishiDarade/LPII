class Symptom:
    def __init__(self, name):
        self.name = name
        self.present = False

class Disease:
    def __init__(self, name, symptoms):
        self.name = name
        self.symptoms = symptoms

def ask_symptom(symptom_name):
    response = input(f"Is the symptom '{symptom_name}' present? (yes/no): ")
    return response.lower() == 'yes'

def diagnose_disease(symptoms, diseases):
    for disease in diseases:
        disease_present = True
        for symptom in disease.symptoms:
            if not symptoms[symptom].present:
                disease_present = False
                break
        if disease_present:
            return disease.name
    return "Unknown"

def main():
    # Define the symptoms
    symptoms = {
        'fever': Symptom('fever'),
        'cough': Symptom('cough'),
        'headache': Symptom('headache'),
        'fatigue': Symptom('fatigue'),
        'nausea': Symptom('nausea')
    }

    # Define the diseases and their associated symptoms
    diseases = [
        Disease('Common Cold', ['fever', 'cough', 'headache']),
        Disease('Flu', ['fever', 'cough', 'fatigue']),
        Disease('Migraine', ['headache', 'nausea']),
        Disease('COVID-19', ['fever', 'cough', 'fatigue', 'nausea'])
    ]

    # Ask for symptoms and update their presence
    for symptom in symptoms.values():
        symptom.present = ask_symptom(symptom.name)

    # Diagnose the disease based on symptoms
    diagnosis = diagnose_disease(symptoms, diseases)

    print(f"\nDiagnosis: {diagnosis}")

if __name__ == '__main__':
    main()
