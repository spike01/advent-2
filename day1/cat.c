// cat takes N file names as command-line arguments, concatenates their
// contents, and writes the result to its standard output.
//
// For this task, it is not necessary to use malloc(3), but you can get away
// with a globally allocated char buffer[4096] array.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096
char buffer[BUFFER_SIZE];

int main(int argc, char *const *argv)
{
  if (argc < 2) {
    printf("Error getting file name(s) to cat\n");
    exit(1);
  }

  int i, fd;

  for (i = 1; i < argc; i++) {
    fd = open(argv[i], O_RDONLY);
    if (fd == -1) {
      printf("Error opening file: %s\n", argv[i]);
      exit(1);
    }

    ssize_t bytes_read = 0;
    ssize_t bytes_written = 0;

    do {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

        if (bytes_written != bytes_read) {
            printf("Error copying");
        }

        if (bytes_read < 0) {
            printf("Error reading from file");
        }
    } while (bytes_read > 0);

    close(fd);
  }


  exit(0);
}

// Syscall signatures:
//
// read(2)
// #include <unistd.h>
//
// ssize_t
// read(int fildes, void *buf, size_t nbyte);
//
// open(2)
// #include <fcntl.h>
//
// int
// open(const char *path, int oflag, ...);
//
// write(2)
// #include <unistd.h>
//
// ssize_t
// write(int fildes, const void *buf, size_t nbyte);
//
// close(2)
// #include <unistd.h>
//
// int
// close(int fildes);
