# Get Next Line

## Introduction
Get Next Line is a project that is part of the curriculum for the Hive Helsinki Coding School. Through this project, I learned the use of static variables in C and usage of the read function. Yet, the key learning for me in this project was appropriate use of the dynamic memory allocation (malloc) and free.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Tests](#tests)
- [License](#license)

## Installation Instructions
To use the Get Next Line function, follow these steps:
1. Clone the repository to your local machine using `git clone [https://github.com/Lauri-Litovuo/get_next_line.git] get_next_line`
2. Navigate to the project directory using `cd get_next_line`
3. Compile the project using makefile or compiler commands e.g.: `cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.h main.c`

## Usage
To use the Get Next Line function, follow these steps:
1. Include the header file in your C program using `#include "get_next_line.h"`
2. Call the function `get_next_line` with the file descriptor and a pointer to a string as arguments
3. The function will return 1 if a line has been read, 0 if the end of file has been reached, and -1 if an error has occurred

Here is an example of how to use the function:
```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Tests
When testing the Get Next Line function, keep in mind that both the buffer size and the line size can be of very different values, and a file descriptor does not only point to regular files. You can assign your own buffer size with flag `-D BUFFER_SIZE=n`.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
