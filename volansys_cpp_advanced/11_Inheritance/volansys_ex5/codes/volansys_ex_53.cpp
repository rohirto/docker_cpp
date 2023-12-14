/**
 * @file volansys_ex_53.cpp
 * @author rohit S
 * @brief Extra Challenges of Inheritance Lesson of C++ Advance 
 * @version 0.1
 * @date 2023-12-13
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Extra Challenge 3
 * We want to calculate the total marks of each student of a class in Physics,Chemistry and Mathematics and the average marks of the class. 
 * The number of students in the class are entered by the user. Create a class named Marks with data members for roll number, name and marks. 
 * Create three other classes inheriting the Marks class, namely Physics, Chemistry and Mathematics, which are used to define marks in 
 * individual subject of each student. Roll number of each student will be generated automatically.
 * 
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;

class Marks{

protected:
    int roll_no;
    string name;
    double marks;

public:
    Marks(int roll,const string& nm, int mk): roll_no(roll), name(move(nm)), marks(mk){}  //Move is used there  to indicate that ownership 
                                                                                              //of a resource or object can be transferred from one 
                                                                                              //object to another efficiently, avoiding unnecessary copies. 

    virtual ~Marks() { }
    double get_marks(){return marks;}
    int get_roll(){return roll_no;}



};


class Physics: public Marks{
private:
   

public:
    Physics(int roll,const string& nm, int mk):Marks(roll,move(nm),mk){}
    void display() const 
    {
        cout << "Roll Number: " << roll_no << ", Name: " << name << ", Physics Marks: " << marks << std::endl;
    }

    


};

class Chemistry: public Marks{
private:
    
public:
    Chemistry(int roll,const string& nm, int mk):Marks(roll,move(nm),mk){}
    void display() const 
    {
        cout << "Roll Number: " << roll_no << ", Name: " << name << ",Chemistry Marks: " << marks << std::endl;
    }


};

class Mathematics: public Marks{
private:
    
public:
    Mathematics(int roll,const string& nm, int mk):Marks(roll,move(nm),mk){}

    void display() const 
    {
        cout << "Roll Number: " << roll_no << ", Name: " << name << ",Maths Marks: " << marks << std::endl;
    }


};



class ClassAverage {
private:
    vector<Physics*> phy_students;
    vector<Chemistry*> chem_students;
    vector<Mathematics*> math_students;

    double phy_tm()
    {
        double tm = 0.0;

        for( const auto& student: phy_students)
        {
            tm += student->get_marks();
        }

        return tm;

    }

    double chem_tm()
    {
        double tm = 0.0;

        for( const auto& student: chem_students)
        {
            tm += student->get_marks();
        }

        return tm;

    }

    double math_tm()
    {
        double tm = 0.0;

        for( const auto& student: math_students)
        {
            tm += student->get_marks();
        }

        return tm;

    }

public:
    void add_student(Marks *student)
    {
    //    students.push_back(student);
        if (Physics *phy_st = dynamic_cast<Physics *>(student))
        {
            phy_students.push_back(phy_st);
        }
        else if(Chemistry *chem_st = dynamic_cast<Chemistry *>(student))
        {
            chem_students.push_back(chem_st);
        }
        else if(Mathematics *math_st = dynamic_cast<Mathematics *>(student))
        {
            math_students.push_back(math_st);
        }
    }

    void total()
    {
        
        for(size_t i = 0; i < phy_students.size(); i++)
        {
            double student_marks = 0;
            student_marks += phy_students[i]->get_marks();
            student_marks += chem_students[i]->get_marks();
            student_marks += math_students[i]->get_marks();

            cout << "Total marks of student Roll no: " << i << " is: " << student_marks << endl;  
        }
        
    }


    void avg() 
    {
        double physics_tm = phy_tm();
        double chemistry_tm = chem_tm();
        double mathematics_tm = math_tm();

        if(!phy_students.empty())
        {
            double phyAverage = physics_tm/phy_students.size();
            cout << "Class Physics Average Marks: " << std::fixed << std::setprecision(2) << phyAverage << endl;
        }
        if(!chem_students.empty())
        {
            double ChemAverage = chemistry_tm/chem_students.size();
            cout << "Class Chemistry Average Marks: " << std::fixed << std::setprecision(2) << ChemAverage << endl;
        }
        if(!math_students.empty())
        {
            double MathAverage = mathematics_tm/math_students.size();
            cout << "Class Mathematics Average Marks: " << std::fixed << std::setprecision(2) << MathAverage << std::endl;
        }

        double clssavg = (physics_tm + chemistry_tm + mathematics_tm)/phy_students.size();
        cout << "Class Average Marks: " << std::fixed << std::setprecision(2) << clssavg << std::endl;

    }
};

int get_input()
{
    int a;
    cin >> a;
    while(!cin.good())
    {
        cout << "Invalid Input\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> a;
    }

    return a;
}

bool get_double(double& num)
{
	string input_msg {};
    getline(cin >> ws,input_msg);

	// Parse the input string
    istringstream iss(input_msg);

	while (!iss.eof())
	{
		if(isalpha(iss.peek()))
		{
			return false;
		}
		else
		{
			iss >> num;
		}
	}
	return true;
}


int main()
{

    int no_of_students;
    ClassAverage class_average;

    //Take the entry for no of students
    cout<< "Enter no of students: \n";
    no_of_students = get_input();


    for(int i = 0; i < no_of_students; i++)
    {
        double phy_m, chem_m, math_m;
        string st_name;

        cout << "Enter name of student: ";
        cin >> st_name;
        cout << "Enter Physics marks: ";
        while(!get_double(phy_m)){cout << "Invalid input!!\n";}
        cout << "Enter Chemistry marks: ";
        while(!get_double(chem_m)){cout << "Invalid input!!\n";}
        cout << "Enter Mathematics marks: ";
        while(!get_double(math_m)){cout << "Invalid input!!\n";}

        Physics* physics_student = new Physics(i,st_name, phy_m);
        Chemistry* chemistry_student = new Chemistry(i,st_name, chem_m);
        Mathematics* math_student = new Mathematics(i,st_name, math_m);

        class_average.add_student(physics_student);
        class_average.add_student(chemistry_student);
        class_average.add_student(math_student);
    }


    cout << "\nStudent Details:\n";
    class_average.total();
    cout << "\nClass Details:\n";
    class_average.avg();

    return 0;
}