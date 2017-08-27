#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define TIMESTRSIZE		1024
#define FMTSTRSIZE		1024

int main(int argc,char **argv)
{
	time_t stamp;
	struct tm *tm;
	char timestr[TIMESTRSIZE];	
	char fmt[FMTSTRSIZE] = {'\0'};
	int ch;
	FILE *fp = stdout;

	stamp = time(NULL);
	tm = localtime(&stamp);	

	while(1)
	{
		ch = getopt(argc,argv,"-y:mdH:MS");
		if(ch < 0)
			break;
		
		switch(ch)
		{
			case 1:
					if(fp == stdout)
					{
							fp = fopen(argv[optind-1],"w");
							if(fp == NULL)
							{
									perror("fopen()");
									fp = stdout;		
							}
					}
				break;
			case 'y':
				if(strcmp(optarg,"2") == 0)
					strncat(fmt,"%y ",FMTSTRSIZE);
				else if(strcmp(optarg,"4") == 0)
						strncat(fmt,"%Y ",FMTSTRSIZE);
					 else
						fprintf(stderr,"Invalid argument of -y\n");
				break;
			case 'm':
				strncat(fmt,"%m ",FMTSTRSIZE);	
				break;
			case 'd':
				strncat(fmt,"%d ",FMTSTRSIZE);	
				break;
			case 'H':
				if(strcmp(optarg,"12") == 0)
                    strncat(fmt,"%I(%P) ",FMTSTRSIZE);
                else if(strcmp(optarg,"24") == 0)
                        strncat(fmt,"%H ",FMTSTRSIZE);
                     else
                        fprintf(stderr,"Invalid argument of -y\n");

				break;
			case 'M':
				strncat(fmt,"%M ",FMTSTRSIZE);
				break;
			case 'S':
				strncat(fmt,"%S ",FMTSTRSIZE);
				break;
			default:
				break;
		}

	}

	strncat(fmt,"\n",FMTSTRSIZE);
	strftime(timestr,TIMESTRSIZE,fmt,tm);	
	fputs(timestr,fp);

	if(fp != stdout)
		fclose(fp);

	exit(0);
}




