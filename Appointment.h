#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Appointment
{
    string patient_id;
    string doctor_id;
    string appointment_date;

public:
    // Setters
    void set_patient_id(const string &p_id);
    void set_doctor_id(const string &d_id);
    void set_date(const string &date);

    // Getters
    string get_patient_id() const;
    string get_doctor_id() const;
    string get_date() const;

    void display_appointment() const;

    void save_to_file(const vector<Appointment> &appointments, const string &filename);
    void load_from_file(vector<Appointment> &appointments, const string &filename);
};