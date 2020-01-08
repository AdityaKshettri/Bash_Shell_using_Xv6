#include "types.h"
#include "user.h"
#include "fcntl.h"

//in case of errors
void quit(char *s)
{
  printf(2, "%s error\n", s);
  exit();
}

//used to fork
int fork1(void)
{
  int pid;
  pid = fork();
  if(pid == -1)
    quit("fork");
  return pid;
}
/*char** strtok(char *str1,char *str2,char **newString)
{
    int i=0,j=0,ctr=0;
    char newString[100][100]; 
    for(i=0;i<=(strlen(str1));i++)
    {
        
        if(str1[i]==str2[0])
        {
            newString[ctr][j]='\0';
            ctr++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
            newString[ctr][j]=str1[i];
            j++;
        }
    }
    return newString;
}*/

void runcmd(char *buf)
{
  char newstr[10][10];
  int i=0,j=0,ctr=0;
  for(i=0;i<=(strlen(buf));i++)
  {
  if(buf[i]==' ')
  {
     newstr[ctr][j]='\0';
     ctr++;  //for next word
     j=0;    //for next word, init index to 0
  }
  else
  {
  newstr[ctr][j]=buf[i];
  j++;
  }
  }
  
  
  if (ctr==0)
  {
  char *str[2];
  newstr[0][strlen(newstr[0])-1]='\0';
  str[0]=newstr[0];
  exec(str[0],str);
  exit();
  }
  if (ctr==1)
  {
  
  char *str[3];
  
  str[0]=newstr[0];
  str[1]=newstr[1];
  exec(str[0],str);
  exit();
  }
  if (ctr==2)
  {
  char *str[4];
  //newstr[0][strlen(newstr[0])]='\0';
  str[0]=newstr[0];
  str[1]=newstr[1];
  str[2]=newstr[2];
  exec(str[0],str);
  exit();
  }
  if (ctr==3)
  {
  char *str[5];
  str[0]=newstr[0];
  str[1]=newstr[1];
  str[2]=newstr[2];
  str[3]=newstr[3];
  exec(str[0],str);
  exit();
  }

}



int getcmd(char *buf, int nbuf)
{
  printf(2, "bash>> ");
  memset(buf, 0, nbuf);
  gets(buf, nbuf);
  if (buf[0]=='e' && buf[1]=='x' && buf[2]=='i' && buf[3]=='t')
  exit();
  if(buf[0] == 0) // EOF
    return -1;
  return 0;
}
int main(int argc,char *argv[])
{
  static char buf[100]; //size of aggument given in the shell 
  int fd; //checks for file descriptors

  // Ensure that three file descriptors are open.
  while((fd = open("console", O_RDWR)) >= 0){
    if(fd >= 3){
      close(fd);
      break;
    }
  }

  // when argc=1
  if (argc==1)
  {
  //infinite loop bash shell
  while(getcmd(buf, sizeof(buf)) >= 0)
  {
    /*int fd2;
    if ((fd2 = open("history", O_RDWR)) < 0)
   {
    printf(1, "copy: error initializing file: history");
    exit();
    }
   printf(fd2,"%s",buf);
   close(fd2);*/
   //checks for change directory
    if(buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' ')
    {    
      buf[strlen(buf)-1] = 0;  // chop 
       printf(2,"cd <%s>",buf+3);
       
      //calls change directory for lenght buf+3
      if(chdir(buf+3) < 0)
        printf(2, "cannot cd %s\n", buf+3);
      continue;
    }
    
    //forks the process
    if(fork1() == 0)
      runcmd(buf);
    wait();
  }
  } 
  //if we need a shell script
  if (argc==2)
  {
  //file descriptor
  int fd1;
  fd1=open(argv[1],O_RDONLY);
  if (fd1<0)
  printf(2,"ERROR");
  if (fd1>0)
  {
  memset(buf,0,sizeof(buf));
  //reads the file till end of file
  while(fgetline(fd1,buf,sizeof(buf))>=0)
  {
  if (buf[0]==0)
  continue;
  printf(1,"%s",buf);
  if(fork1() == 0)
  runcmd(buf);
  wait();
  }
  }
  }
  exit();
}
