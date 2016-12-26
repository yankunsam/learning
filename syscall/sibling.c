#include <stdio.h>
#include <sys/sysinfo.h>
int main()
{
    printf("%d processors\n",get_nprocs());
    return 0;
}
