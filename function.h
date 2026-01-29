#pragma once
#include <iostream>
#include <vector>
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"
using namespace std;

void wait_for_enter();
void menu (vector <Patient> &patients, vector <Doctor> &doctors, vector <Appointment> &appointments);

void add_patient (vector <Patient> &patients);
void add_doctor (vector <Doctor> &doctors);

void appointment_booking (vector <Patient> &patients , vector <Doctor> &doctors , vector <Appointment> &appointments);

void display_patients (const vector <Patient> &patients);
void display_doctors (const vector <Doctor> &doctors);

void search_patient (const vector <Patient> &patients);
void search_doctor_specialization(const vector<Doctor> &doctors);

void delete_patient (vector <Patient> &patients);
void delete_doctor (vector<Doctor> &doctors);

void countـnumberـofـpatients (const vector <Patient> &patients);

void modify_patient(vector<Patient> &patients);
void modify_doctor(vector<Doctor> &doctors);

void save_all_data(const vector<Patient> &patients, const vector<Doctor> &doctors, const vector<Appointment> &appointments);
void load_all_data(vector<Patient> &patients, vector<Doctor> &doctors, vector<Appointment> &appointments);