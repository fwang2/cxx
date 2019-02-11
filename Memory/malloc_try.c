#include <stdio.h>
#include <stdlib.h>

void try_malloc(int offset, unsigned int size)
{
  char * buf;
  buf = (char *) malloc(size);
  if (buf != NULL) {
    printf("pass: offset is %d, %u \n", offset, size);
  } else {
    printf("fail: offset is %d, %u \n", offset, size);
    exit(1);
  }
  free(buf);
} 
/*
 * if size is negative, it fails
 * if size is 0, it is ok
 */

void neg_malloc(int size)
{
  char *buf;
  buf = (char *) malloc(size);
  if (buf != NULL) {
    printf("pass: %i \n",  size);
  } else {
    printf("fail: %i \n",  size);
    exit(1);
  }
  free(buf);
}


int main(int argc, char *argv[])
{
  unsigned long i, size;

  size = 1 << 20;

  printf("asking for: %u --> ", size);
  try_malloc(i, size);
  for (;;) {
    size=size+1024*1024;
    printf("asking for: %u --> ", size);
    try_malloc(-1, size);
   }
  return 0;

}
