#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("ayedaemon");
MODULE_DESCRIPTION("Eudyptula task1");


static int hello_world_init(void)
{
  printk(KERN_DEBUG "Hello World!\n");
  return 0;
}


static void hello_world_exit(void)
{
  printk(KERN_DEBUG "Bye Bye World!\n");
}


module_init(hello_world_init);
module_exit(hello_world_exit);
