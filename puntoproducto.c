#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h> 

asmlinkage long sys_puntoproducto(int __user *result, const int __user *v1, const int __user *v2, int len_v1, int len_v2) {
    long dot = 0;
    int i;
    int buffer1, buffer2;

    if (len_v1 != len_v2 || len_v1 <= 0) {
        return -EINVAL;
    }

    for (i = 0; i < len_v1; i++) {
        if (get_user(buffer1, &v1[i]) || get_user(buffer2, &v2[i])) {
            return -EFAULT;
        }
        dot += buffer1 * buffer2; 
    }

    if (put_user(dot, result)) {
        return -EFAULT;
    }

    return 0;
}
