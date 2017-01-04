#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
struct ima
{
    int i;
    struct cdev *cdev;
};
struct ima my_ima;
struct file_operations my_file_operations;
static int __init my_init(void)
{
    struct cdev *my_cdev = cdev_alloc();
    alloc_chrdev_region(&(my_cdev->dev),0,1,"my_cdev");
    cdev_add(my_cdev,my_cdev->dev,1);
    my_cdev->owner = THIS_MODULE;
    my_cdev->ops = &my_file_operations;
    my_cdev->count = 0;

    my_ima.cdev = my_cdev;
    my_cdev->count = my_cdev->count + 1;

    printk("I am here\n");

	return 0;
}
static void __exit my_exit(void)
{
    printk("I am leaving\n");
}
module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("Sam");
MODULE_LICENSE("GPL");
