#ifndef SCHOOL_SYSTEM_H_INCLUDED
#define SCHOOL_SYSTEM_H_INCLUDED
#define MAX_NAME 20
/*
 *基础类，包括一些共有的变量
  */
class Base{
    protected:
        int num;              //类别编号，学生编号为1，老师为2，员工为3
        char name[MAX_NAME];  //姓名
        int age;              //年纪
        char id[MAX_NAME];    //身份证号
    public:
        int Get_num(){return num;}
        char *Get_name(){return name;}

    };
 /*
  *学生类
  */
class Student:public Base{
    private:
        int grade;            //年级
        float tuition;        //学费
    public:
        void Output();        //输出数据
        void Input();         //输入数据
        void Change();        //更改数据
        void Delete();        //删除数据
        Student(char *tmp_name = " ", int tmp_age = 0, char *tmp_id = " ", int tmp_grade = 0, float tmp_tuition = 0);
        ~Student(){}
    };

/*
 *教师类
 */
 class Teacher:public Base{
    private:
        int class_t;           //课时
        float class_cost;    //课时费
    public:
        void Output();
        void Input();
        void Change();
        void Delete();
        Teacher(char *tmp_name = " ", int tmp_age = 0, char *tmp_id = " ", int tmp_class_t = 0, float tmp_class_cost = 0);
        ~Teacher(){}

    };

  /*
   *员工类
   */
   class Staff:public Base{
    private:
        float salary;//工资
    public:
        void Output();
        void Input();
        void Change();
        void Delete();
        Staff(char *tmp_name = " ", int age = 0, char *tmp_id = " ", float tmp_salary = 0);
        ~Staff(){}
    };

  /*
   *系统类
   */
   class System{
    private:
        //Base    tmp_base;
        Student tmp_student;
        Teacher tmp_teacher;
        Staff   tmp_staff;
    public:
        void Welcome();  //欢迎界面即菜单
        void Welcome2(); // 人员类别界面
        void Input_member(int tmp_num);  //输入成员 函数
        void Change_member(int tmp_num, char *name);  //改变成员 函数
        void Delete_member(int tmp_num, char *name);  //删除成员 函数
        void Show_member(int tmp_num, char *name);   //搜索成员 函数

   };

#endif // SCHOOL_SYSTEM_H_INCLUDED
