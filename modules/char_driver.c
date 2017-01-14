#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/kernel.h>
struct ima
{
    int i;
    struct cdev *cdev;
};
int ima_open(struct inode *inode,struct file *filp)
{	
	struct ima *temp;
	temp = container_of(inode->i_cdev,struct ima,cdev);
	filp->private_data = temp;
	if( (filp->f_flags & O_ACCMODE) == O_WRONLY)
	{
		printk("Opened");
	}
	return 0;
}

struct ima my_ima;
struct file_operations my_file_operations = {
	.owner = THIS_MODULE,
	.open = ima_open,
};
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
