# 📄 get_next_line – Read a Line From a File Descriptor in C

![get\_next\_line](https://img.shields.io/badge/get__next__line-line%20reader-blue.svg)
![License](https://img.shields.io/badge/license-MIT-blue)
![Made with C](https://img.shields.io/badge/made%20with-C-blue)

## 📑 Table of Contents

* [Project Description](#-project-description)
* [How It Works](#️-how-it-works)
* [Compilation](#️-compilation)
* [Usage](#-usage)
* [Expected Output](#-expected-output)
* [Buffer Size Configuration](#-buffer-size-configuration)
* [Bonus Part](#-bonus-part)
* [Project Structure](#-project-structure)
* [License](#-license)
* [Contact](#-contact)

---

## 📌 Project Description

**get\_next\_line** is a function that reads a line from a file descriptor, returning it one line at a time — each call continues from where the last one left off.

This project focuses on understanding file I/O in C, managing memory safely, and handling static variables across function calls.

> 🧠 This project was built to strengthen my low-level programming skills in C by implementing a custom line-reading function using file descriptors and dynamic memory management.

---

## ⚙️ How It Works

* Reads from a given file descriptor (`fd`) until a newline `\n` or EOF is found.
* Returns a dynamically allocated string for each line.
* Manages internal buffering and memory for multiple function calls.
* Uses a static variable to retain state between reads.

```c
char *get_next_line(int fd);
```

---

## ⚙️ Compilation

Clone the repository and compile with your desired buffer size:

```bash
git clone https://github.com/valyriasteel/get_next_line.git
cd get_next_line
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

---

## 🚀 Usage

Include the header and call the function:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

> 🧪 You can test `get_next_line` using your own `main.c` or compare its output with known test files.

---

## 📤 Expected Output

Assume `file.txt` contains:

```
Hello
World!
Test123
```

The output will be:

```
Hello
World!
Test123
```

---

## 🔧 Buffer Size Configuration

The `BUFFER_SIZE` is defined via compiler flags:

```bash
-D BUFFER_SIZE=42
```

You can adjust it during compilation:

```bash
cc -D BUFFER_SIZE=128 ...
```

---

## 🎁 Bonus Part

The bonus version supports:

* **Multiple file descriptors**: reading from several files in parallel
* Bonus files:

  * `get_next_line_bonus.c`
  * `get_next_line_bonus.h`
  * `get_next_line_utils_bonus.c`

Compile bonus version like this:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

Use it the same way as the main version.

---

## 📁 Project Structure

All files are located in the root directory:

```
get_next_line/
├── get_next_line.c              # Main implementation
├── get_next_line_utils.c        # Helper functions
├── get_next_line.h              # Header file
├── get_next_line_bonus.c        # Bonus version
├── get_next_line_utils_bonus.c  # Bonus helpers
├── get_next_line_bonus.h        # Bonus header
└── README.md                    # Documentation
```

---

## 📜 License

This project is licensed under the **MIT License**. See [LICENSE](LICENSE) for details.

---

## 📬 Contact

For questions, issues, or contributions:

* GitHub: [valyriasteel](https://github.com/valyriasteel)
* Feel free to open an [issue](https://github.com/valyriasteel/get_next_line/issues) or [pull request](https://github.com/valyriasteel/get_next_line/pulls)!

> 📝 *This project and its documentation are written in English to ensure accessibility for a global audience.*

---

**Keywords**: get\_next\_line, 42 school project, file descriptor, C programming, memory handling, line reader
