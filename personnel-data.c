/*一个利用 多表 的数据结构例子。把信息分成了不同的域，每个域（除姓名外）都有一个索引表
 * 我利用双向链表来实现多表。
 */
#include <stdio.h>
#include <string.h>
#define MAX_STRING 25
//每个人的链表结构
typedef struct person *pperson;
typedef struct person 
{
	char person_name[MAX_STRING];
	int id;
	pperson r_id, l_id;
	char work[MAX_STRING];
	pperson r_work, l_work;
	char workplace[MAX_STRING];
	pperson  r_workplace, l_workplace;
} Person;

/*建立索引的数据结构
 */
//typedef struct reference *preference;
typedef struct reference {
	char mark_string[MAX_STRING];
	pperson r_links ;
        pperson l_person;	
} Reference;


//操作函数的定义
void init (Person *,Reference *); 		//初始化整个数据结构
void print_person (Person const*tem_person);		//打印一个人员的信息
void inset (Person *);		//增加一个新员工记录
void delete (void);		//删除一个员工记录
void change(void);		//改变多表一个域的信息,并重新正确的链入员工记录
void serach(void);	//对相应的域进行查询

int main (void)
{
	Person test_one;
	Reference reference_test;
	init(&test_one, &reference_test);
	print_person (&test_one);
	inset (&test_one);
	return 0;
}

void init (Person *test_one, Reference *reference_test)
{
	strcpy (reference_test->mark_string,"test");
	reference_test->r_links = NULL;
	reference_test->l_person= test_one;
	test_one->id = 20;
	//test_one->r_id = reference_test;
        test_one->l_id = NULL;	
	strcpy (test_one->person_name, "test_name");
	strcpy (test_one->work, "teacher");
	strcpy (test_one->workplace, "school");
	test_one->r_work = test_one->l_work = NULL;
	test_one->r_workplace = test_one->l_workplace = NULL;
}

void print_person (Person const*tem_person)
{
	printf ("*******************************************\n");
	printf ("ID:             %d\nName:           %s\nWork:           %s\nWorkplace:      %s\n", tem_person->id,tem_person->person_name, tem_person->work, tem_person->workplace);
	printf ("*******************************************\n");
}

void inset (Person *old_person)
{
	Person new_person;
	printf ("Input the id:");
	while ((scanf ("%d",&new_person.id)) != 1)
	{
		printf ("Error while input\n Try again:");
		while ((getchar()) != '\n' )
			continue;
	}
	printf ("Input the name:");
	while (scanf ("%s", new_person.person_name) != 1)
	{
		printf ("Error while input\nTry again:");
		while ((getchar()) != '\n' )
			continue;
	}
	printf ("Input the work:");
	while (scanf ("%s", new_person.work) != 1)
	{
		printf ("Error while input\nTry again:");
		while ((getchar()) != '\n' )
			continue;
	}
	printf ("Input the workplace:");
	while (scanf ("%s", new_person.workplace) != 1)
	{
		printf ("Error while input\nTry again:");
		while ((getchar()) != '\n' )
			continue;
	}
	//表的连接
}

