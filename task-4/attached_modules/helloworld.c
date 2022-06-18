// SPDX-License-Identifier: GPL-2.0+

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int hello_init(void)
{
	pr_debug("Hello World!\n");
	return 0;
}

static void hello_exit(void)
{
	pr_debug("See you later.\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ayedaemon");
MODULE_DESCRIPTION("Just a module");
