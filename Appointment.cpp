#include "Appointment.h"
#include <fstream>

void Appointment::set_patient_id(const string &p_id) { patient_id = p_id; }
void Appointment::set_doctor_id(const string &d_id) { doctor_id = d_id; }
void Appointment::set_date(const string &date) { appointment_date = date; }

string Appointment::get_patient_id() const { return patient_id; }
string Appointment::get_doctor_id() const { return doctor_id; }
string Appointment::get_date() const { return appointment_date; }

void Appointment::display_appointment() const
{
    cout << "Patient ID: " << patient_id << endl;
    cout << "Doctor ID: " << doctor_id << endl;
    cout << "Date: " << appointment_date << endl;
}

void Appointment::save_to_file(const vector<Appointment> &appointments, const string &filename)
{
    ofstream out(filename);
    if (!out) { cout << "Error opening file " << filename << "!\n"; return; }

    for (const auto& app : appointments)
    {
        out << app.get_patient_id() << "\n";
        out << app.get_doctor_id() << "\n";
        out << app.get_date() << "\n";
        out << "----\n";
    }
    out.close();
}

void Appointment::load_from_file(vector<Appointment> &appointments, const string &filename)
{
    ifstream in(filename);
    if (!in) { return; } 

    appointments.clear();
    while (true)
    {
        string p_id, d_id, app_date, separator;

        if (!getline(in, p_id)) break;
        getline(in, d_id);
        getline(in, app_date);
        getline(in, separator);

        Appointment app;
        app.set_patient_id(p_id);
        app.set_doctor_id(d_id);
        app.set_date(app_date);

        appointments.push_back(app);
    }
    in.close();
}