#ifndef SCHOOL_SYSTEM_H_INCLUDED
#define SCHOOL_SYSTEM_H_INCLUDED
#define MAX_NAME 20
/*
 *�����࣬����һЩ���еı���
  */
class Base{
    protected:
        int num;              //����ţ�ѧ�����Ϊ1����ʦΪ2��Ա��Ϊ3
        char name[MAX_NAME];  //����
        int age;              //���
        char id[MAX_NAME];    //���֤��
    public:
        int Get_num(){return num;}
        char *Get_name(){return name;}

    };
 /*
  *ѧ����
  */
class Student:public Base{
    private:
        int grade;            //�꼶
        float tuition;        //ѧ��
    public:
        void Output();        //�������
        void Input();         //��������
        void Change();        //��������
        void Delete();        //ɾ������
        Student(char *tmp_name = " ", int tmp_age = 0, char *tmp_id = " ", int tmp_grade = 0, float tmp_tuition = 0);
        ~Student(){}
    };

/*
 *��ʦ��
 */
 class Teacher:public Base{
    private:
        int class_t;           //��ʱ
        float class_cost;    //��ʱ��
    public:
        void Output();
        void Input();
        void Change();
        void Delete();
        Teacher(char *tmp_name = " ", int tmp_age = 0, char *tmp_id = " ", int tmp_class_t = 0, float tmp_class_cost = 0);
        ~Teacher(){}

    };

  /*
   *Ա����
   */
   class Staff:public Base{
    private:
        float salary;//����
    public:
        void Output();
        void Input();
        void Change();
        void Delete();
        Staff(char *tmp_name = " ", int age = 0, char *tmp_id = " ", float tmp_salary = 0);
        ~Staff(){}
    };

  /*
   *ϵͳ��
   */
   class System{
    private:
        //Base    tmp_base;
        Student tmp_student;
        Teacher tmp_teacher;
        Staff   tmp_staff;
    public:
        void Welcome();  //��ӭ���漴�˵�
        void Welcome2(); // ��Ա������
        void Input_member(int tmp_num);  //�����Ա ����
        void Change_member(int tmp_num, char *name);  //�ı��Ա ����
        void Delete_member(int tmp_num, char *name);  //ɾ����Ա ����
        void Show_member(int tmp_num, char *name);   //������Ա ����

   };

#endif // SCHOOL_SYSTEM_H_INCLUDED
