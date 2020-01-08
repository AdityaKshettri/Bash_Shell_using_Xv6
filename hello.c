#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int main()
{
char *argv[2];
argv[0] = "ls";
//argv[1] = 0;
if(fork() == 0) {
exec("ls",argv);
exit();
}
exit();
}

