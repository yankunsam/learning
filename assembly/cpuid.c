#include <stdio.h>
int main(void)
{
    unsigned int info = 1;
    unsigned int eax,ebx,ecx,edx;
    unsigned int _eax = info, _ebx, _ecx, _edx;
    asm volatile(
# ifdef __i386__
            "xchg %%ebx, %%esi;" /* save ebx (for PIC) */
            "cpuid;"
            "xchg %%esi, %%ebx;" /* restore ebx & pass to caller */
            : "=S" (_ebx),
# else
            "cpuid;"
            : "=b" (_ebx),
# endif
            "+a" (_eax), "=c" (_ecx), "=d" (_edx)
            : /* inputs: eax is handled above */

            );
    eax = _eax;
    ebx = _ebx;
    ecx = _ecx;
    edx = _edx;
    printf("ebx is %d\n",(ebx & 0xff0000) >> 16);
    return 0;

}
