/*一个利用 多表 的数据结构例子。把信息分成了不同的域，每个域（除姓名外）都有一个索引表
 * 我利用双向链表来实现多表。
 * 双向链表需要一个表头,表头不储存数据
 * 把表头当作全局变量 可以更好的操作
 */
#include <stdio.h>
#include <string.h>
#define MAX_STRING 25
#define LISTHEAD  "0000"
//每个人的链表结构
//四个个人数据储存，四对共8个指针
typedef struct person *pperson;
typedef struct person 
{
	char person_name[MAX_STRING];
	pperson r_person, l_person;
	int id;
	pperson r_id, l_id;
	char work[MAX_STRING];
	pperson r_work, l_work;
	char workplace[MAX_STRING];
	pperson  r_workplace, l_workplace;
} Person;

/*建立索引的数据结构
 *l_links 和r_links指向同一个域的前后索引
 *r_person 指向下一个人
 */
typedef struct reference *preference;
typedef struct reference {
	char mark_string[MAX_STRING];
	preference l_links, r_links ;
        pperson r_person;	
} Reference;


//操作函数的定义
void init (void); 		//初始化整个数据结构
void print_person (Person const*tem_person);		//打印一个人员的信息
Person* inset ();		//增加一个新员工记录
void delete (Person *);		//删除一个员工记录
void change (Reference *);		//改变多表一个域的信息,并重新正确的链入员工记录
void search (Reference *, char []);	//对相应的域进行查询

Reference *list_id;
Reference *list_work;
Reference *list_workplace;//还未初始化
Person *list_person;
int main (void)
{
	Person* person;
	init();
	person = inset();
	print_person(person);
	delete(person);
	return 0;
}

void init (void)
{
	list_id = (Reference *)malloc(sizeof (Reference));
	list_work  = (Reference *)malloc(sizeof (Reference));
	list_workplace = (Reference *)malloc(sizeof (Reference));
	list_person = (Person *)malloc(sizeof (Person));

	list_id->l_links = list_id->r_links = NULL;
	list_id->r_person = NULL;

	list_work->l_links = list_work->r_links = NULL;
	list_work->r_person = NULL;

	list_workplace->l_links = list_workplace->r_links = NULL;
	list_workplace->r_person = NULL;

	strcpy (list_person->person_name,LISTHEAD);
	list_person->l_person = NULL;
	list_person->r_person = NULL;
	list_person->r_id = list_person->l_id = NULL;
	list_person->r_work = list_person->l_work = NULL;
	list_person->r_workplace = list_person->l_workplace = NULL;

//	person->id = 20;
//        person->l_id = NULL;	
//	strcpy (person->person_name, "test_name");
//	strcpy (person->work, "teacher");
//	strcpy (person->workplace, "school");
//	person->r_person = person->l_person = NULL;
//	person->r_work = person->l_work = NULL;
//	person->r_workplace = person->l_workplace = NULL;

//	snprintf (list_id->mark_string, sizeof (int), "%d", person->id); 
//	strncpy (list_work->mark_string, person->work, sizeof (person->work)); 
//	strncpy (list_workplace->mark_string, person->workplace, sizeof (person->workplace));
}

void print_person (Person const*tem_person)
{
	printf ("*******************************************\n");
	printf ("ID:             %d\nName:           %s\nWork:           %s\nWorkplace:      %s\n", tem_person->id,tem_person->person_name, tem_person->work, tem_person->workplace);
	printf ("*******************************************\n");
}

Person* inset (void)
{
	Person *tem_list_person = list_person;
	Reference *tem_list_id = list_id;
	Reference *tem_list_work = list_work;
	Reference *tem_list_workplace = list_workplace;

	Person *new_person = (Person *)malloc(sizeof (Person));
	printf ("Input the id:");
	while ((scanf ("%d",&new_person->id)) != 1)
	{
		printf ("Error while input\n Try again:");
		while ((getchar()) != '\n' )
			continue;
	}
	printf ("Input the name:");
	while (scanf ("%s", new_person->person_name) != 1)
	{
		printf ("Error while input\nTry again:");
		while ((getchar()) != '\n' )
			continue;
	}
	printf ("Input the work:");
	while (scanf ("%s", new_person->work) != 1)
	{
		printf ("Error while input\nTry again:");
		while ((getchar()) != '\n' )
			continue;
	}
	printf ("Input the workplace:");
	while (scanf ("%s", new_person->workplace) != 1)
	{
		printf ("Error while input\nTry again:");
		while ((getchar()) != '\n' )
			continue;
	}

	//tem_list_person = tem_list_person->r_person;
	while (tem_list_person->r_person != NULL)
		tem_list_person = tem_list_person->r_person;
	//old_person->l_id = old_person->r_id = NULL;
	//old_person->l_work = old_person->r_id = NULL;
	//old_person->l_workplace = old_person->l_workplace = NULL;
	//表的连接
	//old_person->l_person = NULL;
	//old_person->r_person = new_person;
	tem_list_person->r_person = new_person;
	new_person->l_person = tem_list_person;
	new_person->r_person = NULL;
	//需要有一个比较的过程，建立索引
	while (1)//list_id
	{
		
		while (new_person->id != atoi(tem_list_id->mark_string))
		{
			if (tem_list_id->r_links != NULL)
				tem_list_id = tem_list_id->r_links;	
			else
				break;
		}
		if (new_person->id == atoi(tem_list_id->mark_string))
		{
			tem_list_person = list_id->r_person;
			while (tem_list_person != NULL && tem_list_person->r_id != NULL)
				tem_list_person = tem_list_person->r_id;
			tem_list_person->r_id= new_person;
			new_person->l_id = tem_list_person;
		}	
		break;
	}
	
	if (new_person->l_id == NULL)//如果没有，需要建立新的索引
	{
		Reference *new_list_id = (Reference *)malloc(sizeof (Reference));
		snprintf (new_list_id->mark_string, sizeof (int), "%d", new_person->id);
		while (tem_list_id->r_links != NULL)
			tem_list_id = tem_list_id->r_links;
		new_list_id->l_links = tem_list_id;
		new_list_id->r_links = NULL;
		tem_list_id->r_links = new_list_id;
		new_list_id->r_person = new_person;
	}

	while (1)//list_work
	{
		while (strcmp (new_person->work, tem_list_work->mark_string) != 0)
		{
			if (tem_list_work->r_links != NULL)
				tem_list_work = tem_list_work->r_links;
			else
				break;
		}

		if (strcmp (new_person->work, tem_list_work->mark_string) == 0)
		{
			tem_list_person = tem_list_work->r_person;
			while (tem_list_person != NULL && tem_list_person->r_work != NULL)
				tem_list_person = tem_list_person->r_work;
			tem_list_person->r_work = new_person;
			new_person->l_work = tem_list_person;
		}
		break;
	}

	if (new_person->l_work == NULL)//当找不到相应索引时，建立
	{
		Reference *new_list_work = (Reference *)malloc(sizeof (Reference));
		strcpy (new_list_work->mark_string, new_person->work);
		while (tem_list_work->r_links != NULL)
			tem_list_work = tem_list_work->r_links;
		new_list_work->l_links = tem_list_work;
		new_list_work->r_links = NULL;
		tem_list_work->r_links = new_list_work;
		new_list_work->r_person = new_person;
	}

	while (1)//list_workplace
	{
		while (strcmp (new_person->workplace, tem_list_workplace->mark_string) != 0)
		{
			if (tem_list_workplace->r_links != NULL)
				tem_list_workplace = tem_list_workplace->r_links;
			else
				break;
		}

		if (strcmp (new_person->workplace, tem_list_workplace->mark_string) == 0)
		{
			tem_list_person = tem_list_workplace->r_person;
			while (tem_list_person != NULL && tem_list_person->r_workplace != NULL)
				tem_list_person = tem_list_person->r_workplace;
			tem_list_person->r_workplace = new_person;
			new_person->l_workplace = tem_list_person;
		}
		break;
	}

	if (new_person->l_workplace == NULL)//当没有相应索引时，建立
	{
		Reference *new_list_workplace = (Reference *)malloc(sizeof (Reference));
		strcpy (new_list_workplace->mark_string, new_person->workplace);
		while (tem_list_workplace->r_links != NULL)
			tem_list_workplace = tem_list_workplace->r_links;
		new_list_workplace->l_links = tem_list_workplace;
		new_list_workplace->r_links = NULL;
		tem_list_workplace->r_links = new_list_workplace;
		new_list_workplace->r_person = new_person;
	}
	return new_person;
}

void delete (Person *delete_person)
{
	//删除前，把表重排
	if (delete_person->person_name == LISTHEAD)
	{
		printf ("Can't delete\n");
			return ;
	}

	if (delete_person->r_person != NULL )
	{
		(delete_person->l_person)->r_person = delete_person->r_person;
		(delete_person->r_person)->l_person = delete_person->l_person;
	}
	else 
		(delete_person->l_person)->r_person = delete_person->r_person;
	//删除前，把域整理下
	if (delete_person->l_id == NULL)//这里需要注意，l_id是否是NULL用来判断是否是第一个数据
	{
		list_id->r_person = delete_person->r_id;
		//if (delete_person->r_id != NULL)
		//	(delete_person->r_id)->l_id = NULL;
	}
	else
	{
		(delete_person->l_id)->r_id = delete_person->r_id;
		if (delete_person->r_id != NULL)
			(delete_person->r_id)->l_id = delete_person->l_id;
	}


	if (delete_person->l_work == NULL)//这里需要注意，l_work是否是NULL用来判断是否是第一个数据
	{
		list_work->r_person = delete_person->r_work;
		//if (delete_person->r_work != NULL)
		//	(delete_person->r_work)->l_work = NULL;
	}
	else
	{
		(delete_person->l_work)->r_work = delete_person->r_work;
		if (delete_person->r_work != NULL)
			(delete_person->r_work)->l_work = delete_person->l_work;
	}
	
	if (delete_person->l_workplace == NULL)//这里需要注意，l_workplace是否是NULL用来判断是否是第一个数据
	{
		list_workplace->r_person = delete_person->r_workplace;
		//if (delete_person->r_workplace != NULL)
		//	(delete_person->r_workplace)->l_workplace = NULL;
	}
	else
	{
		(delete_person->l_workplace)->r_workplace = delete_person->r_workplace;
		if (delete_person->r_workplace != NULL)
			(delete_person->r_workplace)->l_workplace = delete_person->l_workplace;
	}
	
	free (delete_person);
	(delete_person->l_person)->r_person = NULL;

}

void search (Reference *search_list,char search_string[MAX_STRING])//需要输入，你需要查询的是何种索引类别
{
	Reference *tem_search_list = search_list;
	while (tem_search_list->r_links != NULL)
	{
		
	}	
}
