#include "Patient.h"
#include <fstream>

void Patient::set_name(const string &n) {name = n;}

void Patient::set_id(const string &i) {id = i;}

void Patient::set_age(int a) {age = a;}

void Patient::set_gender(const string &g) {gender = g;}

void Patient::set_diagnosis(const string &d) {diagnosis = d;}

string Patient::get_name() const {return name;}

string Patient::get_id() const {return id;}

int Patient::get_age() const {return age;}

string Patient::get_gender() const {return gender;}

string Patient::get_diagnosis() const {return diagnosis;}

void Patient::input_patient(vector <Patient> &patients)
{
    cout << "Enter patient's ID: ";
    getline(cin, id);
    for (const auto &pat : patients)
     {
        if (pat.get_id() == id) {
            cout << "This patient is already added before." << endl; 
            return; }
     }

    cout << "Enter patient's Name: ";
    getline(cin, name);

    cout << "Enter patient's Age: ";
    cin >> age;
    while (age < 0)
     {
        cout << "Invalid input! Please enter again." << endl;
        cin >> age;
     }
    cin.ignore();

    cout << "Enter gender (male or female): ";
    getline (cin , gender);
    while (gender != "male" && gender != "female")
     {
        cout << "Invalid input! Please enter 'male' or 'female' only." << endl;
        getline (cin , gender);
     }

    cout << "Enter patient's diagnosis: ";
    getline(cin, diagnosis);
}

void Patient::display_patient() const
{
    cout << "Patient Name: " << name << endl;
    cout << "Patient ID: " << id << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Diagnosis: " << diagnosis << endl;
}

void Patient::save_to_file(const vector<Patient> &patients, const string &filename)
{
    ofstream out(filename);
    if (!out) { cout << "Error opening file " << filename << "!\n"; return; }

    for (const auto& p : patients)
    {
        out << p.get_id() << "\n";
        out << p.get_name() << "\n";
        out << p.get_age() << "\n";
        out << p.get_gender() << "\n";
        out << p.get_diagnosis() << "\n";
        out << "----\n"; // الفاصل اللي كنتِ بتستخدميه
    }
    out.close();
}

void Patient::load_from_file(vector<Patient> &patients, const string &filename)
{
    ifstream in(filename);
    if (!in) { cout << "No existing data for patients. Starting fresh.\n"; return; }

    patients.clear();
    while (true)
    {
        string p_id, p_name, p_gender, p_diag, separator;
        int p_age;

        if (!getline(in, p_id)) break;
        getline(in, p_name);
        in >> p_age;
        in.ignore();
        getline(in, p_gender);
        getline(in, p_diag);
        getline(in, separator);

        Patient p;
        p.set_id(p_id);
        p.set_name(p_name);
        p.set_age(p_age);
        p.set_gender(p_gender);
        p.set_diagnosis(p_diag);

        patients.push_back(p);
    }
    in.close();
}