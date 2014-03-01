/*
 *˵������Ҫ���ڵ�ǰĿ¼�½�����Ϊstudent.dat teacher.dat staff.dat�����ļ����������ִ���
  *�����Ŀ1�ĳ��򣬣��ɹ�ʵ����ɾ�����޸��Ѵ����ݵĹ���
  */
#include <iostream>
#include "school_system.h"
#include <cstring>
#include <fstream>

using namespace std;
char filename1[] = "student.dat";
char filename2[] = "teacher.dat";
char filename3[] = "staff.dat";

//�͵�һ��һ������ȫ�ֵı�����������ļ�����������
/*Base    tmp_base;
Student tmp_student;
Teacher tmp_teacher;
Staff   tmp_staff;
*/
/*
 *ѧ����
 */
 void Student::Output()
 {
     cout <<"ѧ��������"<<name<<endl;
     cout <<"���䣺"<<age<<endl;
     cout <<"���֤���룺"<<id<<endl;
     cout <<"�꼶��"<<grade<<endl;
     cout <<"ѧ�ѣ�"<<tuition<<"Ԫ"<<endl;
 }

 void Student::Input()
 {
     cout <<"����ѧ��������";
     cin  >>name;
     cout <<"���䣺";
     cin  >>age;
     cout <<"���֤���룺";
     cin  >>id;
     cout <<"�꼶��";
     cin  >>grade;
     cout <<"ѧ�ѣ�";
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
    cout <<"ѧ������:"<<name<<endl;
    cout <<"�޸�Ϊ��";
//    if ((c = getchar()) != '\n')
        cin  >>name;
 //  if ((c = getchar()) != '\n')
 //       ;
    cout <<"���䣺"<<age<<endl;
    cout <<"�޸�Ϊ��";
 //   if ((c = getchar()) != '\n')
        cin >>age;
 //   if ((c = getchar()) != '\n')
//        ;
    cout <<"���֤���룺"<<id<<endl;
    cout <<"�޸�Ϊ��";
 //   if ((c = getchar()) != '\n')
        cin >>id;
 //   if ((c = getchar()) != '\n')
 //        ;
    cout <<"�꼶��"<<grade<<endl;
    cout <<"�޸�Ϊ��";
 //   if ((c = getchar()) != '\n')
        cin >>grade;
 //   if ((c = getchar()) != '\n')
 //       ;
    cout <<"ѧ�ѣ�"<<tuition<<"Ԫ"<<endl;
    cout <<"�޸�Ϊ��";
 //   if ((c = getchar()) != '\n')
        cin >>tuition;
    cout <<endl;
 }

 void Student::Delete()
 {
    num = 0;
 }


 /*
  *��ʦ��
  */
  void Teacher::Output()
  {
     cout <<"��ʦ������"<<name<<endl;
     cout <<"���䣺"<<age<<endl;
     cout <<"���֤���룺"<<id<<endl;
     cout <<"��ʱ��"<<class_t<<endl;
     cout <<"��ʱ�ѣ�"<<class_cost<<"Ԫ"<<endl;
  }

  void Teacher::Input()
  {
     char c;
     cout <<"������ʦ������";
     cin  >>name;
     cout <<"���䣺";
     cin  >>age;
     cout <<"���֤���룺";
     cin  >>id;
     cout <<"��ʱ��";
     cin  >>class_t;
     cout <<"��ʱ�ѣ�";
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
    cout <<"��ʦ������"<<name<<endl;
    cout <<"�޸�Ϊ��";
 //   if ((c = getchar()) != '\n')
        cin >>name;
    cout <<endl;
    cout <<"���䣺"<<age<<endl;
    cout <<"�޸�Ϊ��";
 //   if ((c = getchar()) != '\n')
        cin >>age;
    cout <<endl;
    cout <<"���֤���룺"<<id<<endl;
    cout <<"�޸�Ϊ��";
 //   if ((c = getchar()) != '\n')
        cin >>id;
    cout <<endl;
    cout <<"��ʱ��"<<class_t<<endl;
    cout <<"�޸�Ϊ��";
 //   if ((c = getchar()) != '\n')
        cin >>class_t;
    cout <<endl;
    cout <<"��ʱ�ѣ�"<<class_cost<<"Ԫ"<<endl;
    cout <<"�޸�Ϊ��";
 //   if ((c = getchar()) != '\n')
        cin >>class_t;
    cout <<endl;
  }


  void Teacher::Delete()
  {
    num = 0;
  }
  /*
   *Ա����
   */
 void Staff::Output()
 {
     cout <<"Ա��������"<<name<<endl;
     cout <<"���䣺"<<age<<endl;
     cout <<"���֤���룺"<<id<<endl;
     cout <<"�¹��ʣ�"<<salary<<"Ԫ"<<endl;
 }

 void Staff::Input()
 {
     cout <<"����Ա��������";
     cin  >>name;
     cout <<"���䣺";
     cin  >>age;
     cout <<"���֤���룺";
     cout <<"�¹��ʣ�";
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
    cout <<"Ա��������"<<name<<endl;
    cout <<"�޸�Ϊ��";
  //  if ((c = getchar()) != '\n')
        cin >>name;
 //   if ((c = getchar()) != '\n')
//        ;
    cout <<endl;
    cout <<"���䣺"<<age<<endl;
    cout <<"�޸�Ϊ��";
 //   if ((c = getchar()) != '\n')
        cin >>age;
 //   if ((c = getchar()) != '\n')
 //       ;
    cout <<endl;
    cout <<"���֤���룺"<<id<<endl;
    cout <<"�޸�Ϊ��";
//    if ((c = getchar()) != '\n')
        cin >>id;
   // if ((c = getchar()) != '\n')
 //       ;
    cout <<endl;
    cout <<"�¹��� :"<<salary<<"Ԫ"<<endl;
    cout <<"�޸�Ϊ��";
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
  *ϵͳ������
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
                cout <<"ɾ����"<<tmp_student.Get_name()<<endl;
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
                cout <<"ɾ����"<<tmp_teacher.Get_name()<<endl;
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
                    cout <<"ɾ����"<<tmp_staff.Get_name()<<endl;
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
    cout<<"\t\t ***************��ӭʹ��******************"<<endl;
    cout<<"\t\t ************��У��Ϣ����ϵͳ**************"<<endl;
    cout<<"\t\t   1, ������Ա��Ϣ"<<endl;
    cout<<"\t\t   2, ��ѯ��Ա��Ϣ����ʾ"<<endl;
    cout<<"\t\t   3, �޸���Ա��Ϣ"<<endl;
    cout<<"\t\t   4, ɾ����Ա��Ϣ"<<endl;
    cout<<"\t\t   5, �˳�"<<endl;
    cout<<"\t\t   ��ѡ��(1-5):";
  }
  void System::Welcome2()
  {
    cout<<"\n\n\n";
    cout<<"\t\t ********************************************"<<endl;
    cout<<"\t\t ************��Ա���**************"<<endl;
    cout<<"\t\t   1, ѧ��"<<endl;
    cout<<"\t\t   2, ��ʦ"<<endl;
    cout<<"\t\t   3, Ա��"<<endl;
    cout<<"\t\t   4, �˳�"<<endl;
    cout<<"\t\t   ��ѡ��(1-4):";
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
             cout <<"����������ѯ��";
             cin >> tmp_name;
             cout <<"********************"<<endl;
             system.Show_member(n2, tmp_name);
             break;
         case 3:
             cout <<"����������ѯ��";
             cin >> tmp_name;
             cout <<"********************"<<endl;
             system.Change_member(n2, tmp_name);
             break;
         case 4:
             cout <<"����������ѯ��";
             cin >> tmp_name;
             cout <<"********************"<<endl;
             system.Delete_member(n2, tmp_name);

         }
         system.Welcome();
         cin >>n1;
     }
     return 0;
 }
