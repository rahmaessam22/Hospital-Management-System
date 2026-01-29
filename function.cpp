#include "function.h"

void wait_for_enter() 
{
    cout << "Press Enter to return to menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void menu (vector <Patient> &patients, vector <Doctor> &doctors, vector <Appointment> &appointments)
{
  int choice;
  do {
    cout << "=============================" << endl;
    cout << "       Hospital System       " << endl;
    cout << "=============================" << endl;
    cout << "1. Add Patient." << endl;
    cout << "2. Add Doctor." << endl;
    cout << "3. Appointment booking." << endl;
    cout << "4. Display patients." << endl;
    cout << "5. Display doctors." << endl;
    cout << "6. Search patient." << endl;
    cout << "7. Search doctor." << endl;
    cout << "8. Delete patient." << endl;
    cout << "9. Delete doctor." << endl;
    cout << "10.Total number of patients." << endl;
    cout << "11. Modify Patient information." << endl; 
    cout << "12. Modify Doctor information." << endl;
    cout << "0. Exit." << endl;
    cout << "Enter number of choice: ";
    cin >> choice;
    cin.ignore();
    switch (choice) 
    {
        case 1: add_patient(patients); break;
        case 2: add_doctor(doctors); break;
        case 3: appointment_booking (patients, doctors, appointments); break;
        case 4: display_patients (patients); break;
        case 5: display_doctors (doctors); break;
        case 6: search_patient (patients); break;
        case 7: search_doctor_specialization(doctors); break;
        case 8: delete_patient (patients); break;
        case 9: delete_doctor (doctors); break;
        case 10: countـnumberـofـpatients (patients); break;
        case 11: modify_patient(patients); break;
        case 12: modify_doctor(doctors); break;
        case 0: cout << "Exiting..." << endl; break;
        default: cout << "Invalid choice! Try again.";
    }
   if (choice != 0) wait_for_enter();
  } while (choice != 0);
}

void add_patient(vector <Patient> &patients)
{
    Patient p;
    p.input_patient(patients);
    for (const auto &pat : patients)
    {
        if (pat.get_id() == p.get_id())
        {
            cout << "Patient with this ID already exists! Cannot add duplicate.\n";
            return;
        }
    }

    patients.push_back(p);
    cout << "Patient added successfully!\n";
}

void add_doctor(vector <Doctor> &doctors)
{
    Doctor d;
    d.input_doctor(doctors);
    for (const auto &doc : doctors)
    {
        if (doc.get_id() == d.get_id())
        {
            cout << "Doctors with this ID already exists! Cannot add duplicate.\n";
            return;
        }
    }

    doctors.push_back(d);
    cout << "Doctor added successfully!\n";
}

void appointment_booking(vector <Patient> &patients, vector <Doctor> &doctors, vector <Appointment> &appointments)
{
    string p_id, d_id, date;
    bool patient_found = false, doctor_found = false;

    cout << "Enter Patient ID: ";
    cin >> p_id;
    for (const auto &p : patients) {
        if (p.get_id() == p_id) {
            patient_found = true;
            break;
        }
    }

    if (!patient_found) {
        cout << "Error: Patient not found!" << endl;
        return;
    }

    cout << "Enter Doctor ID: ";
    cin >> d_id;
    for (const auto &d : doctors) {
        if (d.get_id() == d_id) {
            doctor_found = true;
            break;
        }
    }

    if (!doctor_found) {
        cout << "Error: Doctor not found!" << endl;
        return;
    }

    cout << "Enter Appointment Date (e.g., 2024-05-20): ";
    cin.ignore();
    getline(cin, date);

    Appointment new_app;
    new_app.set_patient_id(p_id);
    new_app.set_doctor_id(d_id);
    new_app.set_date(date);

    appointments.push_back(new_app);
    cout << "Appointment booked successfully!" << endl;
}

void display_patients(const vector <Patient> &patients)
{
    int count = 1;
    for (const auto &pat : patients)
      {
        cout << "Patient # " << count++ << endl;
        pat.display_patient();
        cout << "=========================" << endl;
      }
}

void display_doctors(const vector <Doctor> &doctors)
{
    int count = 1;
    for (const auto &doc : doctors)
      {
        cout << "Doctor # " << count++ << endl;
        doc.display_doctor();
        cout << "=========================" << endl;
      }
}

void search_patient(const vector <Patient> &patients)
{
    string id;
    cout << "Enter patient ID: ";
    cin >> id;
    bool flag = false;
    for (const auto &pat : patients) 
      {
        if (pat.get_id() == id) 
         {
        pat.display_patient();
        flag = true;
        break;
         }
      }
    if (!flag) cout << "This patient not found..." << endl;
}

void search_doctor_specialization(const vector<Doctor> &doctors)
{
    string spec;
    cout << "Enter specialization: ";
    cin.ignore();
    getline(cin, spec);

    bool flag = false;

    for (const auto &doc : doctors) {
        if (doc.get_specialization() == spec) {
            doc.display_doctor();
            flag = true;
        }
    }

    if (!flag) cout << "No doctors found with this specialization." << endl;
}

void delete_patient(vector <Patient> &patients)
{
    string id;
    cout << "Enter Patient ID to delete: ";
    cin >> id;
    bool found = false;
    for (auto it = patients.begin(); it != patients.end(); ++it) {
        if (it -> get_id() == id) {
            patients.erase(it);
            cout << "Patient deleted successfully.\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Patient not found!\n";

}

void delete_doctor(vector<Doctor> &doctors)
{
    string id;
    cout << "Enter Doctor ID to delete: ";
    cin >> id;

    bool found = false;

    for (auto it = doctors.begin(); it != doctors.end(); ++it) {
        if (it -> get_id() == id) {   
            doctors.erase(it);
            cout << "Doctor deleted successfully.\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Doctor not found!\n";
}

void countـnumberـofـpatients (const vector <Patient> &patients)
{
    cout << "Total number of patients: " << patients.size() << endl;
}

void modify_patient(vector<Patient> &patients) {
    string id;
    cout << "Enter Patient ID to search for modification: ";
    cin >> id;

    for (auto &pat : patients) {
        if (pat.get_id() == id) {
            int choice;
            cout << "\n--- Modify Patient Data ---" << endl;
            cout << "1. Name\n2. Age\n3. Gender\n4. Diagnosis\n5. Patient ID\nEnter choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1: {
                    string new_name;
                    cout << "Enter new name: ";
                    getline(cin, new_name);
                    pat.set_name(new_name);
                    cout << "Name updated successfully!\n";
                    break;
                }
                case 2: {
                    int new_age;
                    cout << "Enter new age: ";
                    cin >> new_age;
                    pat.set_age(new_age);
                    cout << "Age updated successfully!\n";
                    break;
                }
                case 3: {
                    string new_gender;
                    cout << "Enter new gender (male/female): ";
                    cin >> new_gender;
                    pat.set_gender(new_gender);
                    cout << "Gender updated successfully!\n";
                    break;
                }
                case 4: {
                    string new_diag;
                    cout << "Enter new diagnosis: ";
                    getline(cin, new_diag);
                    pat.set_diagnosis(new_diag);
                    cout << "Diagnosis updated successfully!\n";
                    break;
                }
                case 5: {
                    string new_id;
                    cout << "Enter new ID: ";
                    cin >> new_id;
                    // Check if the new ID already exists
                    bool exists = false;
                    for (const auto &p : patients) {
                        if (p.get_id() == new_id) {
                            exists = true;
                            break;
                        }
                    }
                    if (exists) {
                        cout << "Error: This ID already exists for another patient!\n";
                    } else {
                        pat.set_id(new_id);
                        cout << "ID updated successfully!\n";
                    }
                    break;
                }
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }
            return;  
        }
    }
    cout << "Patient not found!" << endl;
}

void modify_doctor(vector<Doctor> &doctors) {
    string id;
    cout << "Enter Doctor ID to search for modification: ";
    cin >> id;

    for (auto &doc : doctors) {
        if (doc.get_id() == id) {
            int choice;
            cout << "\n--- Modify Doctor Data ---" << endl;
            cout << "1. Name\n2. Specialization\n3. Doctor ID\nEnter choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1: {
                    string new_name;
                    cout << "Enter new name: ";
                    getline(cin, new_name);
                    doc.set_name(new_name);
                    cout << "Name updated successfully!\n";
                    break;
                }
                case 2: {
                    string new_spec;
                    cout << "Enter new specialization: ";
                    getline(cin, new_spec);
                    doc.set_specialization(new_spec);
                    cout << "Specialization updated successfully!\n";
                    break;
                }
                case 3: {
                    string new_id;
                    cout << "Enter new ID: ";
                    cin >> new_id;
                    // Check if the new ID already exists
                    bool exists = false;
                    for (const auto &d : doctors) {
                        if (d.get_id() == new_id) {
                            exists = true;
                            break;
                        }
                    }
                    if (exists) {
                        cout << "Error: This ID already exists for another doctor!\n";
                    } else {
                        doc.set_id(new_id);
                        cout << "ID updated successfully!\n";
                    }
                    break;
                }
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }
            return;
        }
    }
    cout << "Doctor not found!" << endl;
}

void save_all_data(const vector<Patient> &patients, const vector<Doctor> &doctors, const vector<Appointment> &appointments)
{
    Patient p;
    p.save_to_file(patients, "patients.txt");

    Doctor d;
    d.save_to_file(doctors, "doctors.txt");

    Appointment app;
    app.save_to_file(appointments, "appointments.txt");

    cout << "All data saved successfully!\n";
}

void load_all_data(vector<Patient> &patients, vector<Doctor> &doctors, vector<Appointment> &appointments)
{
    Patient p;
    p.load_from_file(patients, "patients.txt");

    Doctor d;
    d.load_from_file(doctors, "doctors.txt");

    Appointment app;
    app.load_from_file(appointments, "appointments.txt");

    cout << "All data loaded successfully!\n";
}