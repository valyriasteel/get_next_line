# get_next_line

![get_next_line](https://img.shields.io/badge/get_next_line-C%20Function-blue.svg)

## 📌 Project Description
`get_next_line` is a function that reads a file or standard input line by line. It efficiently handles file descriptors and dynamically allocates memory to return the next line each time it is called.

## 📂 Features
- Reads a line from a file descriptor.
- Works with any file, including standard input (`stdin`).
- Handles multiple file descriptors simultaneously.
- Dynamically allocates memory to construct lines of any length.

## ⚙️ Installation
To compile the library, run:

```sh
cc get_next_line.c get_next_line_utils.c main.c -o my_program
```

## 🚀 Usage
To use `get_next_line` in your project, include the header file:

```c
#include "get_next_line.h"
```

Compile your program with:

```sh
cc get_next_line.c get_next_line_utils.c main.c -o my_program
```

### Example Usage
#### Example: Reading from a File
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) return 1;
    
    char *line;
    while ((line = get_next_line(fd))) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

#### Example: test.txt
```c
first line
second line
third line
```

Compile and run:
```sh
cc get_next_line.c get_next_line_utils.c main.c -o my_program
./my_program
```

#### Expected Output (for `test.txt` containing sample lines):
```
first line
second line
third line
```

## 📜 License
This project is licensed under the **[MIT License](LICENSE)**.

## 📧 Contact
For any questions or feedback, feel free to reach out via GitHub!

