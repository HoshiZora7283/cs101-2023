#include<stdio.h>
#include<string.h> 
typedef struct employee{
	int em_id;
	char em_name[10];
	int em_age;
	char em_phone[12];
	float em_salary;
}employee_t;
void employee_info(employee_t my_emp){
	printf("em_id = %d\n",my_emp.em_id);
	printf("em_name = %s\n",my_emp.em_name);
	printf("em_age = %d\n",my_emp.em_age);
	printf("em_phone = %s\n",my_emp.em_phone);
	printf("em_salary = %f\n",my_emp.em_salary);
}
int main(){
	printf("sizeof(employee_t) = %d\n",sizeof(employee_t));
	employee_t my_emp;
	my_emp.em_id=50;
	strcpy(my_emp.em_name,"mango");
	my_emp.em_age=18;
	strcpy(my_emp.em_phone,"0912345678");
	my_emp.em_salary=1000.30;
	employee_info(my_emp);
	return 0;
}
