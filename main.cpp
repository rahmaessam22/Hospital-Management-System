#include <iostream>
#include <vector>
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"
#include "function.h"

int main ()
{
    vector <Patient> patients;
    vector <Doctor> doctors;
    vector <Appointment> appointments;

    load_all_data(patients, doctors, appointments);

    menu (patients, doctors, appointments);

    save_all_data(patients, doctors, appointments);
}