#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Doctor
{
     string id;
     string name;
     string specialization;

    public:
      //setters
     void set_name(const string &n);
     void set_id(const string &i);
     void set_specialization(const string &s);

      //getters
     string get_name() const;
     string get_id() const;
     string get_specialization() const;

     void input_doctor(vector <Doctor> &doctors);
     void display_doctor() const;

     void save_to_file(const vector<Doctor> &doctors, const string &filename);
     void load_from_file(vector<Doctor> &doctors, const string &filename);
};