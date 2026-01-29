#include "Doctor.h"
#include <fstream>

void Doctor::set_name(const string &n) {name = n;}

void Doctor::set_id(const string &i) {id = i;}

void Doctor::set_specialization(const string &s) {specialization = s;}

string Doctor::get_name() const {return name;}

string Doctor::get_id() const {return id;}

string Doctor::get_specialization() const {return specialization;}

void Doctor::input_doctor(vector <Doctor> &doctors)
{
    cout << "Enter doctor's ID: ";
    getline(cin, id);
    for (const auto &doc : doctors)
     {
        if (doc.get_id() == id) {
            cout << "This doctor is already added before." << endl; 
            return; }
     }
    
    cout << "Enter doctor's name: ";
    getline(cin, name);

    cout << "Enter doctor's specialization: ";
    getline(cin, specialization);
}

void Doctor::display_doctor() const
{
    cout << "Doctor Name: " << name << endl;
    cout << "Doctor ID: " << id << endl;
    cout << "Specialization: " << specialization << endl;
}

void Doctor::save_to_file(const vector<Doctor> &doctors, const string &filename)
{
    ofstream out(filename);
    if (!out) { cout << "Error opening file " << filename << "!\n"; return; }

    for (const auto& d : doctors)
    {
        out << d.get_id() << "\n";
        out << d.get_name() << "\n";
        out << d.get_specialization() << "\n";
        out << "----\n";
    }
    out.close();
}

void Doctor::load_from_file(vector<Doctor> &doctors, const string &filename)
{
    ifstream in(filename);
    if (!in) { cout << "No existing data for doctors.\n"; return; }

    doctors.clear();
    while (true)
    {
        string d_id, d_name, d_spec, separator;

        if (!getline(in, d_id)) break;
        getline(in, d_name);
        getline(in, d_spec);
        getline(in, separator);

        Doctor d;
        d.set_id(d_id);
        d.set_name(d_name);
        d.set_specialization(d_spec);

        doctors.push_back(d);
    }
    in.close();
}