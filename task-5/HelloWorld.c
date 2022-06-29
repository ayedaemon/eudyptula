// SPDX-License-Identifier: GPL-2.0+

#include <linux/usb.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hid.h>

#define VENDOR_ID1	(0x058f)
#define PRODUCT_ID1	(0x6387)
#define VENDOR_ID2 	(0x0930)
#define PRODUCT_ID2 (0x6545)

static int hello_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
	pr_alert("device plugged in\n");
	return 0;
}

static void hello_disconnect(struct usb_interface *interface)
{
	pr_alert("device disconnected.\n");
}

static const struct usb_device_id id_table[] = {
	{
		USB_INTERFACE_INFO(		// Register with class info
			USB_INTERFACE_CLASS_HID, 
	 		USB_INTERFACE_SUBCLASS_BOOT,
	  		USB_INTERFACE_PROTOCOL_KEYBOARD
		)
	},
    {
        USB_DEVICE(		// Register with vendor_id:prod_id
            VENDOR_ID1, 
            PRODUCT_ID1
        )
    },
	{
        USB_DEVICE(		// Register with vendor_id:prod_id
            VENDOR_ID2, 
            PRODUCT_ID2
        )
    },
	{},  // End node - always null
};

MODULE_DEVICE_TABLE(usb, id_table);

static struct usb_driver hello_driver = {
	.name = "ayedaemonUSBdriver",
	.probe = hello_probe,
	.disconnect = hello_disconnect,
	.id_table = id_table,
};

static int __init hello_init(void)
{
	int retval;
	pr_debug("Hello World!\n");
	retval = usb_register(&hello_driver);
	if (retval)
		printk(KERN_ERR "USB driver not registered");
	else
		printk(KERN_ERR "USB driver registered this time");
	return retval;
}

static void __exit hello_exit(void)
{
	pr_debug("See you later.\n");
	usb_deregister(&hello_driver);
	printk(KERN_ERR "USB driver deregistered");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ayedaemon");
MODULE_DESCRIPTION("Eudyptula task5");


