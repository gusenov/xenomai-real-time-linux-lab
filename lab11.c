#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/mman.h>
#include <native/task.h>
#include <native/timer.h>
#include <rtdk.h>

RT_TASK demo_task;
RT_TASK task2;

void demo(void *arg)
{
  RT_TASK *curtask;
  RT_TASK_INFO curtaskinfo;

  // hello world
  rt_printf("Hello World!\n");

  // запрос текущей задачи
  curtask = rt_task_self();
  rt_task_inquire(curtask, &curtaskinfo);

  // печатаем имя задачи
  rt_printf("Task name : %s \n", curtaskinfo.name);
}

void task2_foo(void *arg)
{
  rt_printf("%s", (const char *)arg);
}

int main(int argc, char* argv[])
{
  char str[10] ;

  // выполняем авто-инициализацию rt_print buffers если задача этого не сделала...
  rt_print_auto_init(1);

  // Запрет использования swap для программы...
  mlockall(MCL_CURRENT | MCL_FUTURE);

  rt_printf("start task\n");

  /*
  * Arguments: &task,
  *   name,
  *   stack size (0=default),
  *   priority,
  *   mode (FPU, start suspended, ...)
  */

  sprintf(str, "hello");

  rt_task_create(&demo_task, str, 0, 50, 0);

  /*
  * Arguments: &task,
  *   task function,
  *   function argument
  */

  rt_task_start(&demo_task, &demo, 0);

  rt_task_create(&task2, "second task", 0, 40, 0);
  rt_task_start(&task2, &task2_foo, "Gussenov\n");
}
