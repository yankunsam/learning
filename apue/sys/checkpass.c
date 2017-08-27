#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <shadow.h>

int main(int argc,char **argv)
{
	char *input_pass,*cryptedpass;
	struct spwd *shadowline;

	if(argc < 2)
	{
		fprintf(stderr,"Usage...\n");
		exit(1);
	}

	input_pass = getpass("Password:");
	/*if error*/

	shadowline = getspnam(argv[1]);
	/*if error*/

	cryptedpass = crypt(input_pass,shadowline->sp_pwdp);
	/*if error*/

	if(strcmp(shadowline->sp_pwdp,cryptedpass) == 0)
		puts("ok!");
	else
		puts("Failed!");

	exit(0);
}






