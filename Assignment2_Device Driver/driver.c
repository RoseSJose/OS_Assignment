#include<linux/init.h>      
#include<linux/module.h>    
#include<linux/fs.h>        
#include<asm/uaccess.h>     
#include<linux/kernel.h>    

MODULE_LICENSE("GPL");      //module has a free license under the GNU General Public License


static char BUF_KERNAL[100];   //driver local buffer
static int OPEN_DEVICE(struct inode *inod, struct file *fil);
static ssize_t READ_DEVICE(struct file *filep,char *buf,size_t len,loff_t *off);          
static ssize_t WRITE_DEVICE(struct file *flip,const char *buff,size_t len,loff_t *off);
static int CLOSE_DEVICE(struct inode *inod,struct file *fil);


static struct file_operations fops=
{
    .read=READ_DEVICE, 
    .write=WRITE_DEVICE, 
    .open=OPEN_DEVICE,   
    .release=CLOSE_DEVICE, 
};

 
static int entry(void)   //during insmod
{

    int target=register_chrdev(240,"mydevice",&fops);
    if(target<0)
        printk(KERN_ALERT "Device registration failed.\n");
    else
        printk(KERN_ALERT "Device registred.\n");
    return 0;
}

static void exiting(void) //during rmmod
{
    unregister_chrdev(240,"device");
    printk(KERN_ALERT "exit");
}

static int OPEN_DEVICE(struct inode *inod, struct file *fil)
{
    printk(KERN_ALERT "The device is opened");
    return 0;
}

static ssize_t READ_DEVICE(struct file *filep, char *buf, size_t len, loff_t *off)
{
    printk(KERN_ALERT "The device is reading");
    copy_to_user(buf,BUF_KERNAL,len); 
    return len;
}

static ssize_t WRITE_DEVICE(struct file *flip, const char *buf, size_t len, loff_t *off)
{
    printk(KERN_ALERT "The device is writing");
    copy_from_user(BUF_KERNAL,buf,len); 
    BUF_KERNAL[len]=0;
    return len;
}


static int CLOSE_DEVICE(struct inode *inod,struct file *fil)
{
    printk(KERN_ALERT "The device is closed\n");
    return 0;
}

 
module_init(entry);
module_exit(exiting);



