#include<stdio.h>
#include<signal.h>
#include<strings.h>
#include<stdlib.h>

void siga(int signum, siginfo_t *p1, void *p2)
{
	printf("pid=%d, uid=%d \n", p1->si_pid, p1->si_uid);
	printf("I am process function\n");
	sleep(5);
}

int main()
{
	struct sigaction act;
	act.sa_sigaction = siga;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	int ret;
	ret = sigaction(SIGINT, &act, NULL);
	if(-1 == ret)
	{
		perror("sigaction");
		return -1;
	}
	while(1);
	return 0;	
}
