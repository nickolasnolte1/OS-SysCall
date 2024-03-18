#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>

asmlinkage long sys_expresioncerrada(const char __user *expression) {
    char ch;
    long balance = 0;
    long i = 0;

    while (true) {
        if (copy_from_user(&ch, &expression[i], 1)) {
            return -EFAULT; 
        }
        
        if (ch == '\0') { 
            break;
        }

        if (ch == '(' || ch == '[') { 
            balance++;
        } else if (ch == ')' || ch == ']') { 
            balance--;
            if (balance < 0) { 
                return 0; 
            }
        }
        i++; 
    }

    
    return (balance == 0) ? 1 : 0;
}

