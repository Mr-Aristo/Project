#include<iostream>
#include<fstream>
#include<iomanip>
#include<Windows.h>


using namespace std;



class student
{
private:
    int idnum;
   
    int physics, drawing, math, program, history;
    int result;
    void calculate();
    
public:
   char teacher [50];
   char spec[50];
   int numt;
   char name[50];
   

   virtual void search() { 
       cout << name << endl;

   }

    void getdata();
    void showdata() const;
    void show_tabular() const;
    int getIDNum() const;
};



void student::calculate()
{
	result = (physics + math + drawing + program + history) / 5;
	if (result >= 90) {
		cout << "* Perfect *";

	}
	else if (result >= 70 || result == 84) {
		cout << "* Good *" << endl;

	}
	else if (result >= 50) {

		cout << "* Not Bad* " << endl;

	}
	else
	{
		cout << " * Bad * " << endl;

	}


}

void student::getdata()
{
    cout << "\n> Enter The ID number of the student ";
    cin >> idnum;
    cout << "\n\n> Enter student's Name: ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\n> Enter student's physics grade: ";
    cin >> physics;
    cout << "\n> Enter student's math grade: ";
    cin >> math;
    cout << "\n> Enter student's drawing grade: ";
    cin >> drawing;
    cout << "\n> Enter student's programming  grade: ";
    cin >> program;
    cout << "\n> Enter student's history grade: ";
    cin >> history;
    calculate();
}

void student::showdata() const
{
    cout << "\n> ID Number: " << idnum;
    cout << "\n> Name: " << name;
    cout << "\n> Physics: " << physics;
    cout << "\n> Math: " << math;
    cout << "\n> Drawing: " << drawing;
    cout << "\n> Programming: " << program;
    cout << "\n> History: " << history;
    cout << "\n> Result: " << result;
    
 
}

void student::show_tabular() const
{
    cout << idnum << setw(8) << " " << name << setw(10) << physics << setw(6) << math << setw(6) << drawing << setw(6)
        << program << setw(6) << history << setw(10) << result <<  endl;
}

int  student::getIDNum() const
{
    return idnum;
}

//************* TEACHER CLASS*****************
class Teacher : public student {
public:

    void search() {
        cout << teacher << endl;

    }

    void getdata();
    void showdata() const;

    
};




void Teacher::getdata() {

    cout << "\n> Enter Number of Teacher ";
    cin >> numt;
    cout << "\n> Enter Name of Teacher ";
    cin.ignore();
    cin.getline (teacher,50);
    cout << "\n\n> Enter Section of Teacher: ";
    cin.ignore();
    cin.getline(spec, 50);


}


void Teacher::showdata() const 
{
    cout << "\n> ID Number of Teacher :  " << numt;
    cout << "\n> Name of Teacher :  " << teacher;
    cout << "\n> Section of teacher :  " << spec;
  
}



void SaveStudent();
void displayAll();
void Searchdisplay(int);
void modifyStudent(int);
void deleteStudent(int);
void DisplayClassResult();
void DisplayResult();
void intro();
void scStudent(char);
void scTeacher(char);

//******** TEACHER CLASS FONK.******
void write_teacher() {
    Teacher th;

    ofstream outfile;
    outfile.open("Teacher.dat", ios::binary | ios::app);
    th.getdata();
    outfile.write(reinterpret_cast<char*> (&th), sizeof(Teacher));
    outfile.close();
    cout << "\n\n< Teacher record Has Been Created >";
    cin.ignore();
    cin.get();
}

void display_teacher() {
    Teacher st;
    ifstream inFile;
    inFile.open("Teacher.dat", ios::binary);
    if (!inFile)
    {
        cout << "< File could not be open !! Press any Key... >";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    while (inFile.read(reinterpret_cast<char*> (&st), sizeof(Teacher)))
    {
        st.showdata();
        cout << "\n\n====================================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void deleteTeacher(int n) {
    Teacher st;
    ifstream inFile;
    inFile.open("Teacher.dat", ios::binary);
    if (!inFile)
    {
        cout << "< File could not be open !! Press any Key... >";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("Temp.dat", ios::out);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char*> (&st), sizeof(Teacher)))
    {
        if (st.getIDNum() != n)
        {
            outFile.write(reinterpret_cast<char*> (&st), sizeof(Teacher));
        }
    }
    outFile.close();
    inFile.close();
    remove("Teacher.dat");
    rename("Temp.dat", "Teacher.dat");
    cout << "\n\n\t< Record Deleted .. >";
    cin.ignore();
    cin.get();

}

//************** TEACHER CLASS END *********************

void scStudent(char n ) {
    student st;
    ifstream inFile;

   
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "< File could not be open !! Press any Key...  >";
        cin.ignore();
        cin.get();
        return;
    }
 
    while (inFile.read(reinterpret_cast<char*> (&st), sizeof(student)))
    {
        if (n == st.name[0]) {
            st.search();
        }
            

    }
    inFile.close();

    cin.ignore();
    cin.get();
       
   
}




void scTeacher(char n) {
    Teacher st; 
    ifstream inFile;


    inFile.open("Teacher.dat", ios::binary);
    if (!inFile)
    {
        cout << "< File could not be open !! Press any Key...  >";
        cin.ignore();
        cin.get();
        return;
    }
    
    while (inFile.read(reinterpret_cast<char*> (&st), sizeof(Teacher)))
    {
        if (n == st.teacher[0]) {
            st.search();
        }


    }
    inFile.close();
   
    cin.ignore();
    cin.get();

}

void write_student()
{
    student st;
    ofstream outFile;
    outFile.open("student.dat", ios::binary | ios::app);
    st.getdata();
    outFile.write(reinterpret_cast<char*> (&st), sizeof(student));
    outFile.close();
    cout << "\n\n< Student record Has Been Created >";
    cin.ignore();
    cin.get();
}



void display_all()
{
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "< File could not be open !! Press any Key... >";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    while (inFile.read(reinterpret_cast<char*> (&st), sizeof(student)))
    {
        st.showdata();
        cout << "\n\n====================================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}



void display_sp(int n)
{
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "< File could not be open !! Press any Key... :( >";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag = false;
    while (inFile.read(reinterpret_cast<char*> (&st), sizeof(student)))
    {
        
        if (st.getIDNum() == n)
        {
            st.showdata();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\n< record not exist ! !  >";
    cin.ignore();
    cin.get();
}


void modify_student(int n)
{
    bool found = false;
    student st;
    fstream File;
    File.open("student.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "< File could not be open !! Press any Key... :( >";
        cin.ignore();
        cin.get();
        return;
    }
    while (!File.eof() && found == false)
    {

        File.read(reinterpret_cast<char*> (&st), sizeof(student));
        if (st.getIDNum() == n)
        {
            st.showdata();
            cout << "\n\nPlease Enter The New Details of student" << endl;
            st.getdata();
            int pos = (-1) * static_cast<int>(sizeof(st));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char*> (&st), sizeof(student));
            cout << "\n\n\t<  Record Updated >";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n < Record Not Found :( >";
    cin.ignore();
    cin.get();
}



void delete_student(int n)
{
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "< File could not be open !! Press any Key... >";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("Temp.dat", ios::out);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char*> (&st), sizeof(student)))
    {
        if (st.getIDNum() != n)
        {
            outFile.write(reinterpret_cast<char*> (&st), sizeof(student));
        }
    }
    outFile.close();
    inFile.close();
    remove("student.dat");
    rename("Temp.dat", "student.dat");
    cout << "\n\n\t< Record Deleted .. >";
    cin.ignore();
    cin.get();
}


void class_result()
{
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "< File could not be open !! Press any Key... >";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\t\tALL STUDENTS RESULT \n\n";
    cout << "==========================================================\n";
    cout << "R.No     Name        PH    M     D    PR      H     Result" << endl;
    cout << "==========================================================\n";
    while (inFile.read(reinterpret_cast<char*> (&st), sizeof(student)))
    {
        st.show_tabular();
    }
    cin.ignore();
    cin.get();
    inFile.close();
}


void intro() {
    cout << "\n\t\t> > > Student Manager System < < < \n" << endl;
    cout<<"\t\t   * * * * * * * * * * * * * * *" <<endl;
    //cout<<"\t\t  * * * * * * * * * * * * * * *" <<endl;
    cout<<"\t\t   * * * * * * * * * * * * * * * \n" <<endl;
    
    cout<<"\t\t   Press any key for contuniue !!" <<endl;
    cin.get();
}



int main()
{
    student* st;
    Teacher th;
    st = &th;
    
    system("color 3");
    intro();
    char ch;
    int num;
    char letter;
    cout.setf(ios::fixed | ios::showpoint);
    cout << setprecision(2);
    do
    {
        system("cls");
        cout << "\t---------------------------------------------";
        cout << "\n\n\t*\t> 1.CREATE STUDENT RECORD";
        cout << "\n\n\t*\t> 2.DISPLAY ALL STUDENTS RECORDS";
        cout << "\n\n\t*\t> 3.SEARCH STUDENT RECORD ";
        cout << "\n\n\t*\t> 4.MODIFY STUDENT RECORD";
        cout << "\n\n\t*\t> 5.DELETE STUDENT RECORD";
        cout << "\n\n\t*\t> 6. DISPLAY CLASS RESULT";
        cout << "\n\n\t*\t> 7. ADD TEACHER ";
        cout << "\n\n\t*\t> 8. DISPLAY TEACHER LIST";
        cout << "\n\n\t*\t> 9. DELETE TEACHER ";
        cout << "\n\n\t*\t> s. SEARCH  ";
        cout << "\n\n\t*\t> 0. EXIT";
        cout << "\n\n\t----------------------------------------------";
        cout << "\n\n\tPlease Enter Your Choice (1-7): ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case '1':	write_student(); break;
        case '2':	display_all(); break;
        case '3':	cout << "\n\n\tPlease Enter Student's ID number: "; cin >> num;
            display_sp(num); break;
        case '4':	cout << "\n\n\tPlease Enter Student's ID number: "; cin >> num;
            modify_student(num); break; 
        case '5':	cout << "\n\n\tPlease Enter Student's ID number: "; cin >> num;
            delete_student(num); break;
        case '6':	class_result(); break;
        case '7':   write_teacher(); break;
        case '8':  display_teacher(); break;
        case '9':  cout << "\n\n\tPlease Enter Teacher's ID number: "; cin >> num;
            deleteTeacher(num); break;
        case's':cout << "\n\nPlease Enter Letter that you wanna search: "; cin >> letter; scStudent(letter); scTeacher(letter); break;
        case '0':	exit(0);
        default:	cout << "\a";

        }
    } while (ch != '0');

    return 0;
}