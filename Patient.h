#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Patient
{
     string id;
     string name;
     int age;
     string gender;
     string diagnosis;

    public:
      //setters
     void set_name(const string &n);
     void set_id(const string &i);
     void set_age(int a);
     void set_gender(const string &g);
     void set_diagnosis(const string &d);

      //getters
     string get_name() const;
     string get_id() const;
     int get_age() const;
     string get_gender() const;
     string get_diagnosis() const;

     void input_patient(vector <Patient> &patients);
     void display_patient() const;

     void save_to_file(const vector<Patient> &patients, const string &filename);
     void load_from_file(vector<Patient> &patients, const string &filename);
};