# 结构体

## 结构定义

当需要表示一些有关联的数据时，结构体（Structure）是一种非常有用的数据类型。在 C 语言中，结构体是由一组不同类型的变量组成的用户自定义数据类型，可以将其看作是一种新的复合数据类型。

结构体的定义使用 `struct` 关键字，具体语法如下：

```c
struct 结构体名称 {
  数据类型 成员变量1;
  数据类型 成员变量2;
  //...
  数据类型 成员变量n;
};
```

下面是一个结构体的示例，定义了一个 `Person` 结构体，包含了姓名、年龄和性别这三个成员变量：

```c
struct Person {
  char name[20];
  int age;
  char gender;
};
```



## 指向结构的指针

指向结构的指针是指一个指针变量，它存储了一个结构体变量的内存地址，可以通过该指针间接地访问和修改这个结构体变量的成员。

在C语言中，声明指向结构的指针可以使用如下语法：

```c
struct 结构体类型 *指针变量名;
```

例如，如果有一个名为`Person`的结构体类型，其中包含`name`和`age`两个成员变量，可以通过如下方式声明一个指向`Person`结构体的指针变量：

```c
struct Person *p;
```

之后可以通过`p->name`和`p->age`访问或修改结构体变量的成员，其中`->`是一个用于结构体指针的运算符。

指向结构的指针在操作复杂数据结构、动态内存分配和函数调用等场景中非常有用。



例如

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	char name[20];
	int age;
	int score;
};

struct student *create_student(char *name, int age, int score)
{
	struct student *p = (struct student *)malloc(sizeof(struct student));
	strcpy(p->name, name);
	p->age = age;
	p->score = score;
	return p;
};

int main()
{
	struct student *s1;
	s1 = create_student("Tom", 20, 90);
	//  s1 所指向的结构体对象的成员进行操作，例如：

	printf("Name: %s, Age: %d, Score: %d\n", s1->name, s1->age, s1->score);
	// 记得在程序结束前释放动态分配的内存空间

	free(s1);
	return 0;
}
```



## 结构体函数

在 C 语言中，没有类的概念，因此也不存在类的成员函数。但是可以在结构体中定义函数，这种函数称为结构体函数。结构体函数和普通函数的定义方式相同，只是在结构体内部定义。

```c
#include <stdio.h>

struct student {
  char name[50];
  int age;
  float gpa;

  // 结构体函数
  void display() {
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("GPA: %f\n", gpa);
  }
};

int main() {
  struct student s = {"Alice", 20, 3.5};
  s.display();
  return 0;
}


```



## 结构体嵌套

```c
typedef struct node  //define a node structure
{
  int data;
  struct node *next;
} node;


typedef struct Stack  //define a stack structure
{
  node* head;  //head pointer  node* represents a pointer to a node structure
  int size;   //stack size
} Stack;
```

在这段代码中，struct node 是一个自定义的结构体类型，表示链表中的节点。每个节点包含两个成员变量: data表示节点存储的数据，next 是一个指向下一个节点的指针。因此，next 成员变量的类型是 struct node*，即指向 struct node 类型的指针。*

*在定义链表时，我们需要使用 struct node 类型来表示每个节点。因此next 成员变量的类型也需要是 struct node*，用来指向下一个节点。这样我们就可以通过 node->next 来访问链表中的下一个节点

需要注意的是，这里使用了嵌套的结构体定义，即在 struct node 内部定义了一个 struct node* 类型的成员变量。这种嵌套的结构体定义可以方便地表示复杂的数据结构，如链表、树等



# typedef

使用 typedef 可以将 `struct student` 定义为一个新的类型名，从而可以使程序更加简洁易读。以下是使用 typedef 重写该程序的示例：

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    int score;
} student;

student *create_student(char *name, int age, int score) {
    student *p = (student *) malloc(sizeof(student));
    strcpy(p->name, name);
    p->age = age;
    p->score = score;
    return p;
}

int main() {
    student *s1 = create_student("Tom", 20, 90);
    printf("Name: %s, Age: %d, Score: %d\n", s1->name, s1->age, s1->score);
    free(s1);
    return 0;
}
```

在这个新的程序中，`struct student` 被重命名为 `student`。这意味着在程序中，我们可以直接使用 `student` 来代替 `struct student`。由于 `student` 现在是一个新的类型名，因此在程序中创建变量时，可以直接使用 `student` 而不需要在变量名前面加上 `struct`。

此外，我们也可以在 `create_student` 函数中使用 `student` 来代替 `struct student`。由于在函数中已经进行了类型定义，因此在函数体内不需要再次使用 `struct` 来指定结构体类型。