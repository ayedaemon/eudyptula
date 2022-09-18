// SPDX-License-Identifier: GPL-2.0+

#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

// message formatting
#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

// Device name
#define MISC_DEVICE_NAME "eudyptula"


// Custom read operation
static ssize_t misc_read(struct file *filp, char __user *buff, size_t cnt, loff_t *offt)
{
	char *my_id = "ayedaemon\n";
	int my_id_len = strlen(my_id)+1;

	pr_info("[begin] offt=%ld\n", *offt);
	if (*offt != 0)
		return 0;

	if ((cnt < my_id_len) ||
		(copy_to_user(buff, my_id, my_id_len)))
		return -EINVAL;

	*offt += cnt;
	pr_info("[ end ] offt=%ld\n", *offt);
	return cnt;
}


// Custom write operation
static ssize_t misc_write(struct file *filp, const char __user *buff, size_t cnt, loff_t *offt)
{
	char *my_id = "ayedaemon";
	int my_id_len = strlen(my_id);
	char temp[my_id_len+1]; // size = 10; including the null byte
	int return_value;

	if ((cnt != my_id_len+1) ||                                 // Check input size (mainly to prevent overflows)
		(copy_from_user(temp, buff, my_id_len)) ||              // Copy 9 bytes from userland
		(strncmp(temp, my_id, my_id_len))) {                      // finally, compare 9 bytes

		pr_info("%s (%d) ~~ %s (%d)\n", temp, strlen(temp), my_id, strlen(my_id));
		return_value = -EINVAL;
	} else {
		pr_info("%s (%d) ~~ %s (%d)\n", temp, strlen(temp), my_id, strlen(my_id));
		return_value = cnt;
	}

	return return_value
}


// Operations structure
const struct file_operations misc_fops = {
	.read = misc_read,
	.write = misc_write,
};


// Misc Device structure
static struct miscdevice my_misc_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = MISC_DEVICE_NAME,
	.fops = &misc_fops,
};


// Entry point
static int hello_world_init(void)
{
	int ret = misc_register(&my_misc_device);

	pr_info("Hello from module; Return %d\n", ret);
	if (ret < 0)
		return -EFAULT;
	return 0;
}


// Exit point
static void hello_world_exit(void)
{
	misc_deregister(&my_misc_device);
	pr_info("Exiting from module\n");
}



module_init(hello_world_init);
module_exit(hello_world_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("ayedaemon");
MODULE_DESCRIPTION("Eudyptula task6");
