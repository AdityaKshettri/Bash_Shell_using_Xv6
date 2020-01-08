#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"

char buf[100];

void edit(int fd,char* filename)
{
  int n;
  int fp;
  
  if ((fp = open(filename, O_CREATE | O_RDWR)) < 0) 
{                         
    printf(1, "error %s\n", filename);            
    exit();
  }
  memset (buf,'\0',sizeof(buf));
  while((n = read(fd, buf, sizeof(buf))) > 0)
{                                

if (buf[0]=='e' && buf[1]=='x' && buf[2]=='i' && buf[3]=='t')
{
break;
}
    // write(1, buf, n);                                                     
    printf(fp, "%s", buf);
    memset (buf,'\0',sizeof(buf));
  }
  close(fp);
  if(n < 0){
    printf(1, "editor: read error\n");                                      
    exit();
  }
}

int main(int argc, char *argv[])
{

  if(argc <= 2){
    char* filename = "default.txt";                                           // Defalut file if user doesn't provide any file
    if(argv[1])
      filename = argv[1]; 
    edit(0,filename);                                                        // Calling the femto function 
    exit();
  }
  exit();
}
