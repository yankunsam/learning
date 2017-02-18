#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/security.h>
static ssize_t evm_read(struct file *filp, char __user *buf,size_t count, loff_t *ppos)
{
    char temp[80];
    ssize_t rc;

    if (*ppos != 0)
        return 0;

    sprintf(temp, "%s","hello" );
    rc = simple_read_from_buffer(buf, count, ppos, temp, strlen(temp));

    return rc;
}
static const struct file_operations evm_ops = {
    .read = evm_read,
//.write = NULL,
//   .release = securityfs_remove,

};
static int __init hello_init(void)
{
    pr_info("hello\n");
    securityfs_create_file("1",S_IRUSR | S_IRGRP,NULL,NULL,&evm_ops);
	return 0;

}
static void __exit hello_exit(void)
{
	printk("hello,I am leaving\n");
}
module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("sam");
