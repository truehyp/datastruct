/*
 *说明：需要现在当前目录下建立名为student.dat teacher.dat staff.dat三个文件，否则会出现错误
  *相比题目1的程序，，成功实现了删除和修改已存数据的功能
  */
#include <iostream>
#include "school_system.h"
#include <cstring>
#include <fstream>

using namespace std;
char filename1[] = "student.dat";
char filename2[] = "teacher.dat";
char filename3[] = "staff.dat";

//和第一题一样，用全局的变量来储存从文件读来的数据
/*Base    tmp_base;
Student tmp_student;
Teacher tmp_teacher;
Staff   tmp_staff;
*/
/*
 *学生类
 */
 void Student::Output()
 {
     cout <<"学生姓名："<<name<<endl;
     cout <<"年龄："<<age<<endl;
     cout <<"身份证号码："<<id<<endl;
     cout <<"年级："<<grade<<endl;
     cout <<"学费："<<tuition<<"元"<<endl;
 }

 void Student::Input()
 {
     cout <<"输入学生姓名：";
     cin  >>name;
     cout <<"年龄：";
     cin  >>age;
     cout <<"身份证号码：";
     cin  >>id;
     cout <<"年级：";
     cin  >>grade;
     cout <<"学费：";
     cin  >>tuition;
 }
 Student::Student(char *tmp_name, int tmp_age, char *tmp_id, int tmp_grade, float tmp_tuition)
 {
     strcpy (name, tmp_name);
     age = tmp_age;
     strcpy (id, tmp_id);
     grade = tmp_grade;
     tuition = tmp_tuition;
     num = 1;
 }

 void Student::Change()
 {
     char c;
    cout <<"学生姓名:"<<name<<endl;
    cout <<"修改为：";
//    if ((c = getchar()) != '\n')
        cin  >>name;
 //  if ((c = getchar()) != '\n')
 //       ;
    cout <<"年龄："<<age<<endl;
    cout <<"修改为：";
 //   if ((c = getchar()) != '\n')
        cin >>age;
 //   if ((c = getchar()) != '\n')
//        ;
    cout <<"身份证号码："<<id<<endl;
    cout <<"修改为：";
 //   if ((c = getchar()) != '\n')
        cin >>id;
 //   if ((c = getchar()) != '\n')
 //        ;
    cout <<"年级："<<grade<<endl;
    cout <<"修改为：";
 //   if ((c = getchar()) != '\n')
        cin >>grade;
 //   if ((c = getchar()) != '\n')
 //       ;
    cout <<"学费："<<tuition<<"元"<<endl;
    cout <<"修改为：";
 //   if ((c = getchar()) != '\n')
        cin >>tuition;
    cout <<endl;
 }

 void Student::Delete()
 {
    num = 0;
 }


 /*
  *老师类
  */
  void Teacher::Output()
  {
     cout <<"老师姓名："<<name<<endl;
     cout <<"年龄："<<age<<endl;
     cout <<"身份证号码："<<id<<endl;
     cout <<"课时："<<class_t<<endl;
     cout <<"课时费："<<class_cost<<"元"<<endl;
  }

  void Teacher::Input()
  {
     char c;
     cout <<"输入老师姓名：";
     cin  >>name;
     cout <<"年龄：";
     cin  >>age;
     cout <<"身份证号码：";
     cin  >>id;
     cout <<"课时：";
     cin  >>class_t;
     cout <<"课时费：";
     cin  >>class_cost;
  }

  Teacher::Teacher(char *tmp_name, int tmp_age, char *tmp_id, int tmp_class_t, float tmp_class_cost)
  {
      strcpy(name, tmp_name);
      age = tmp_age;
      strcpy(id, tmp_id);
      class_t = tmp_class_t;
      class_cost = tmp_class_cost;
      num = 2;
  }

  void Teacher::Change()
  {
    char c;
    cout <<"老师姓名："<<name<<endl;
    cout <<"修改为：";
 //   if ((c = getchar()) != '\n')
        cin >>name;
    cout <<endl;
    cout <<"年龄："<<age<<endl;
    cout <<"修改为：";
 //   if ((c = getchar()) != '\n')
        cin >>age;
    cout <<endl;
    cout <<"身份证号码："<<id<<endl;
    cout <<"修改为：";
 //   if ((c = getchar()) != '\n')
        cin >>id;
    cout <<endl;
    cout <<"课时："<<class_t<<endl;
    cout <<"修改为：";
 //   if ((c = getchar()) != '\n')
        cin >>class_t;
    cout <<endl;
    cout <<"课时费："<<class_cost<<"元"<<endl;
    cout <<"修改为：";
 //   if ((c = getchar()) != '\n')
        cin >>class_t;
    cout <<endl;
  }


  void Teacher::Delete()
  {
    num = 0;
  }
  /*
   *员工类
   */
 void Staff::Output()
 {
     cout <<"员工姓名："<<name<<endl;
     cout <<"年龄："<<age<<endl;
     cout <<"身份证号码："<<id<<endl;
     cout <<"月工资："<<salary<<"元"<<endl;
 }

 void Staff::Input()
 {
     cout <<"输入员工姓名：";
     cin  >>name;
     cout <<"年龄：";
     cin  >>age;
     cout <<"身份证号码：";
     cout <<"月工资：";
     cin  >>salary;
 }

 Staff::Staff(char *tmp_name, int tmp_age, char *tmp_id, float tmp_salary)
 {
     strcpy (name, tmp_name);
     age = tmp_age;
     strcpy(id, tmp_id);
     salary = tmp_salary;
     num = 3; //
 }

 void Staff::Change()
 {
    char c;
    cout <<"员工姓名："<<name<<endl;
    cout <<"修改为：";
  //  if ((c = getchar()) != '\n')
        cin >>name;
 //   if ((c = getchar()) != '\n')
//        ;
    cout <<endl;
    cout <<"年龄："<<age<<endl;
    cout <<"修改为：";
 //   if ((c = getchar()) != '\n')
        cin >>age;
 //   if ((c = getchar()) != '\n')
 //       ;
    cout <<endl;
    cout <<"身份证号码："<<id<<endl;
    cout <<"修改为：";
//    if ((c = getchar()) != '\n')
        cin >>id;
   // if ((c = getchar()) != '\n')
 //       ;
    cout <<endl;
    cout <<"月工资 :"<<salary<<"元"<<endl;
    cout <<"修改为：";
  //  if ((c = getchar()) != '\n')
        cin >>salary;
  //  if ((c = getchar()) != '\n')
 //       ;
    cout <<endl;
 }

 void Staff::Delete()
 {
    num =0;
 }

 /*
  *系统控制类
  */
  void System::Change_member(int tmp_num, char *name)
  {
    long int p_file;
    int num;
    char c;
    switch (tmp_num)
    {
    case 1:
        {
        fstream datafile(filename1, ios::in|ios::out|ios::binary);
        datafile.read((char *)&tmp_student, sizeof(Student));
        while (!datafile.eof())
        {
            if((strcmp(name, tmp_student.Get_name())) == 0 && (num = tmp_student.Get_num()) != 0)//
            {
                if ((c = getchar()) != '\n')
                    ;
                tmp_student.Change();
              //  tmp_student.Delete();
                p_file = datafile.tellp();
                datafile.seekp(-1*(int)sizeof(class Student), ios::cur);
              //  datafile.seekp(ios::end);
                datafile.write((char*)&tmp_student, sizeof(Student));
                datafile.seekp(p_file);
            }
            datafile.read((char *)&tmp_student, sizeof(Student));
        }
        datafile.close();
        datafile.clear();
        break;
        }
    case 2:
        {
        fstream datafile(filename2, ios::in|ios::out|ios::binary);
        datafile.read((char *)&tmp_teacher, sizeof(Teacher));
        while (!datafile.eof())
        {
            if((strcmp(name, tmp_teacher.Get_name())) == 0 && (num =tmp_teacher.Get_num()) != 0)
            {
                tmp_teacher.Change();
             //   tmp_teacher.Delete();
                p_file = datafile.tellp();
                datafile.seekp(-1*(int)sizeof(class Teacher), ios::cur);
              //  datafile.seekp(ios::end);
                datafile.write((char*)&tmp_teacher, sizeof(Teacher));
                datafile.seekp(p_file);
            }
            datafile.read((char*)&tmp_teacher, sizeof(Teacher));
        }
        datafile.close();
        datafile.clear();
        break;
        }
    case 3:
        {
        fstream datafile(filename3, ios::in|ios::out|ios::binary);
        datafile.read((char *)&tmp_staff, sizeof(Staff));
        while (!datafile.eof())
        {
            if((strcmp(name, tmp_staff.Get_name())) ==0 && (num = tmp_staff.Get_num()) != 0)
                {
                    tmp_staff.Change();
                  //  tmp_staff.Delete();
                    p_file = datafile.tellp();
                    datafile.seekp(-1*(int)sizeof(class Staff), ios::cur);
                  //  datafile.seekp(ios::end);
                    datafile.write((char*)&tmp_staff, sizeof(Staff));
                    datafile.seekp(p_file);
                }
            datafile.read((char*)&tmp_teacher, sizeof(Teacher));
        }
        datafile.close();
        datafile.clear();
        }
    }
  }


  void System::Delete_member(int tmp_num, char *name)
  {
    long int p_file;
    int num;
    switch (tmp_num)
    {
    case 1:
        {
        fstream datafile(filename1, ios::in|ios::out|ios::binary);
        datafile.read((char *)&tmp_student, sizeof(Student));
        while (!datafile.eof())
        {
            if((strcmp(name, tmp_student.Get_name())) == 0 && (num = tmp_student.Get_num()) != 0)//
            {
               // tmp_student.Change();
                tmp_student.Delete();
                p_file = datafile.tellp();
                datafile.seekp(-1*(int)sizeof(class Student), ios::cur);
              //  datafile.seekp(ios::end);
                datafile.write((char*)&tmp_student, sizeof(Student));
                datafile.seekp(p_file);
                cout <<"删除了"<<tmp_student.Get_name()<<endl;
            }
            datafile.read((char *)&tmp_student, sizeof(Student));
        }
        datafile.close();
        datafile.clear();
        break;
        }
    case 2:
        {
        fstream datafile(filename2, ios::in|ios::out|ios::binary);
        datafile.read((char *)&tmp_teacher, sizeof(Teacher));
        while (!datafile.eof())
        {
            if((strcmp(name, tmp_teacher.Get_name())) == 0 && (num =tmp_teacher.Get_num()) != 0)
            {
              //  tmp_teacher.Change();
                tmp_teacher.Delete();
                p_file = datafile.tellp();
                datafile.seekp(-1*(int)sizeof(class Teacher), ios::cur);
              //  datafile.seekp(ios::end);
                datafile.write((char*)&tmp_teacher, sizeof(Teacher));
                datafile.seekp(p_file);
                cout <<"删除了"<<tmp_teacher.Get_name()<<endl;
            }
            datafile.read((char*)&tmp_teacher, sizeof(Teacher));
        }
        datafile.close();
        datafile.clear();
        break;
        }
    case 3:
        {
        fstream datafile(filename3, ios::in|ios::out|ios::binary);
        datafile.read((char *)&tmp_staff, sizeof(Staff));
        while (!datafile.eof())
        {
            if((strcmp(name, tmp_staff.Get_name())) == 0 && (num = tmp_staff.Get_num()) != 0)
                {
                   // tmp_staff.Change();
                    tmp_staff.Delete();
                    p_file = datafile.tellp();
                    datafile.seekp(-1*(int)sizeof(class Staff), ios::cur);
                  //  datafile.seekp(ios::end);
                    datafile.write((char*)&tmp_staff, sizeof(Staff));
                    datafile.seekp(p_file);
                    cout <<"删除了"<<tmp_staff.Get_name()<<endl;
                }
            datafile.read((char*)&tmp_teacher, sizeof(Teacher));
        }
        datafile.close();
        datafile.clear();
        }
    }

  }

  void System::Input_member(int tmp_num)
  {
      switch(tmp_num)
      {
      case 1:
          {
          tmp_student.Input();
          fstream datafile(filename1, ios::in|ios::out|ios::binary);
          datafile.seekp(0,ios::end);
          datafile.write((char *)&tmp_student, sizeof(Student));
          datafile.close();
          break;
          }
      case 2:
        {
            tmp_teacher.Input();
            fstream datafile(filename2, ios::in|ios::out|ios::binary);
            datafile.seekp(0,ios::end);
            datafile.write((char *)&tmp_teacher, sizeof(Teacher));
            datafile.close();
            break;
        }
      case 3:
        {
            tmp_staff.Input();
            fstream datafile(filename3, ios::in|ios::out|ios::binary);
            datafile.seekp(0,ios::end);
            datafile.write((char *)&tmp_staff, sizeof(Staff));
            datafile.close();
        }
      }


  }

  void System::Show_member(int tmp_num, char *name)
  {
    int num;
    switch (tmp_num)
    {
    case 1:
        {
        fstream datafile(filename1, ios::in|ios::out|ios::binary);
        datafile.read((char *)&tmp_student, sizeof(Student));
        while (!datafile.eof())
        {
            if((strcmp(name, tmp_student.Get_name())) == 0 && (num = tmp_student.Get_num())!=0)
                tmp_student.Output();
            datafile.read((char *)&tmp_student, sizeof(Student));
        }
        datafile.close();
        datafile.clear();
        break;
        }
    case 2:
        {
        fstream datafile(filename2, ios::in|ios::out|ios::binary);
        datafile.read((char *)&tmp_teacher, sizeof(Teacher));
        while (!datafile.eof())
        {
            if((strcmp(name, tmp_teacher.Get_name())) == 0 && (num = tmp_teacher.Get_num())!=0)
                tmp_teacher.Output();
            datafile.read((char *)&tmp_teacher, sizeof(Teacher));
        }
        datafile.close();
        datafile.clear();
        break;
        }
    case 3:
        {
        fstream datafile(filename3, ios::in|ios::out|ios::binary);
        datafile.read((char *)&tmp_staff, sizeof(Staff));
        while (!datafile.eof())
        {
            if((strcmp(name, tmp_staff.Get_name())) == 0 && (num = tmp_staff.Get_num())!=0)
                tmp_staff.Output();
            datafile.read((char *)&tmp_staff, sizeof(Staff));
        }
        datafile.close();
        datafile.clear();
        }
    }

  }

  void System::Welcome()
  {
    cout<<"\n\n\n";
    cout<<"\t\t ***************欢迎使用******************"<<endl;
    cout<<"\t\t ************高校信息管理系统**************"<<endl;
    cout<<"\t\t   1, 输入人员信息"<<endl;
    cout<<"\t\t   2, 查询人员信息并显示"<<endl;
    cout<<"\t\t   3, 修改人员信息"<<endl;
    cout<<"\t\t   4, 删除人员信息"<<endl;
    cout<<"\t\t   5, 退出"<<endl;
    cout<<"\t\t   请选择(1-5):";
  }
  void System::Welcome2()
  {
    cout<<"\n\n\n";
    cout<<"\t\t ********************************************"<<endl;
    cout<<"\t\t ************人员类别**************"<<endl;
    cout<<"\t\t   1, 学生"<<endl;
    cout<<"\t\t   2, 老师"<<endl;
    cout<<"\t\t   3, 员工"<<endl;
    cout<<"\t\t   4, 退出"<<endl;
    cout<<"\t\t   请选择(1-4):";
  }
 int main(void)
 {
     System system;
     int n1, n2;
     char tmp_name[MAX_NAME];
     system.Welcome();
     cin >>n1;
     while (n1 > 0 && n1 <5)
     {
         system.Welcome2();
         cin >>n2;
         if (n2 < 1 && n2 > 4)
            break;
         switch(n1)
         {
         case 1:
             system.Input_member(n2);
             break;
         case 2:
             cout <<"输入姓名查询：";
             cin >> tmp_name;
             cout <<"********************"<<endl;
             system.Show_member(n2, tmp_name);
             break;
         case 3:
             cout <<"输入姓名查询：";
             cin >> tmp_name;
             cout <<"********************"<<endl;
             system.Change_member(n2, tmp_name);
             break;
         case 4:
             cout <<"输入姓名查询：";
             cin >> tmp_name;
             cout <<"********************"<<endl;
             system.Delete_member(n2, tmp_name);

         }
         system.Welcome();
         cin >>n1;
     }
     return 0;
 }
