# get_next_line - File Descriptor Line Reader

[![License: MIT](https://img.shields.io/badge/license-MIT-green?style=for-the-badge)](LICENSE)
[![Language C](https://img.shields.io/badge/language-C-blue?style=for-the-badge)](https://en.wikipedia.org/wiki/C_(programming_language))
[![42 Kocaeli](https://img.shields.io/badge/42-Kocaeli-black?style=for-the-badge)](https://www.42kocaeli.com.tr)

> A function that reads and returns one line at a time from a file descriptor, introducing static variables and state management in C. This project demonstrates advanced file I/O handling, dynamic memory management, and efficient buffer processing.

## 📖 Table of Contents
* [About The Project](#-about-the-project)
* [Key Features & Technical Skills](#-key-features--technical-skills)
* [Technical Implementation](#-technical-implementation)
* [How To Use](#-how-to-use)
  * [Prerequisites](#prerequisites)
  * [Compilation](#compilation)
  * [Usage Example](#usage-example)
* [Buffer Size Configuration](#-buffer-size-configuration)
* [What I Learned](#-what-i-learned)
* [Project Requirements](#-project-requirements)
* [License](#-license)
* [Contact](#-contact)

## 🎯 About The Project

get_next_line is a function that reads a line from a file descriptor, built as part of **42 School's curriculum**. This project introduces one of C's most powerful concepts: **static variables**, which allow the function to maintain state across multiple calls without using global variables.

**Function Prototype:**
```c
char *get_next_line(int fd);
```
Returns a line read from the file descriptor, including the terminating `\n` character (if present).

**Why This Project Matters:**
- Introduces **static variables** for state retention across function calls
- Develops skills in **file descriptor management** and low-level file I/O
- Requires **dynamic buffer handling** with configurable buffer sizes
- Teaches **memory-efficient** line reading without loading entire files
- Builds foundation for handling multiple file descriptors simultaneously

The result is a reusable function that can read any text file line by line, making it an essential utility for file processing in C.

## 🔧 Key Features & Technical Skills

This project demonstrates proficiency in:

| Technical Skill | Implementation |
|----------------|----------------|
| **Static Variables** | Persistent state management across function calls |
| **File Descriptor I/O** | Direct interaction with file descriptors using read() |
| **Dynamic Memory Management** | Efficient allocation and deallocation strategies |
| **Buffer Management** | Configurable buffer sizes via compiler flags |
| **String Manipulation** | Line extraction, concatenation, and memory handling |
| **Edge Case Handling** | EOF, empty files, missing newlines, large/small buffers |
| **Multiple FD Management** | Simultaneous handling of multiple file descriptors (bonus) |
| **Code Standards** | Strict adherence to [Norminette](https://github.com/42School/norminette) coding style |

**Code Quality Standards:**
* ✅ Works with any buffer size (1, 42, 9999, 10000000+)
* ✅ Compiled with `-Wall -Wextra -Werror` flags
* ✅ Zero memory leaks
* ✅ No global variables used
* ✅ Norminette compliant (42's strict coding standard)

## 🔍 Technical Implementation

### Core Components

**1. Static Variable Usage**
```c
static char *buffer_storage;  // Retains leftover data between calls
```
- Maintains state across function invocations
- Stores remaining data after extracting a line
- Automatically initialized to NULL on first call

**2. Buffer Reading Strategy**
- Reads `BUFFER_SIZE` bytes at a time from file descriptor
- Accumulates data until `\n` is found or EOF is reached
- Minimizes read() calls for efficiency

**3. Line Extraction Algorithm**
- Searches for newline character in accumulated buffer
- Extracts line including `\n` (or until EOF)
- Preserves remaining data in static variable for next call

**4. Memory Management**
- All allocations tracked and properly freed
- Handles partial reads across multiple calls
- Cleans up static storage on EOF or error

### Notable Implementation Challenges

**1. Static Variables & State Management**
- First exposure to maintaining state across function calls
- Understanding static variable lifetime and scope
- Managing persistent data without global variables

**2. Flexible Buffer Size Handling**
- Must work with BUFFER_SIZE from 1 to millions
- Efficient memory usage regardless of buffer configuration
- Testing edge cases with extreme values

**3. Multiple File Descriptors (Bonus)**
- Array of static buffers indexed by file descriptor
- Switching between different files without losing position
- Managing memory for multiple concurrent reads

**4. Edge Cases**
- Files without trailing newline
- Empty files
- Very long lines (larger than BUFFER_SIZE)
- Single character buffer sizes
- EOF detection and cleanup

### Compilation Flags
The buffer size is configurable at compile time:
```bash
-D BUFFER_SIZE=42    # Sets buffer to 42 bytes
```

## 🚀 How To Use

### Prerequisites

- C compiler (gcc or clang)
- UNIX-like operating system (Linux, macOS)

### Compilation

**1. Clone the repository:**
```bash
git clone https://github.com/beratbosnak/get_next_line.git
cd get_next_line
```

**2. Compile with desired buffer size:**
```bash
# Standard compilation (mandatory)
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_main.c -o gnl

# Bonus compilation (multiple file descriptors)
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c your_main.c -o gnl_bonus
```

### Usage Example

**Example 1: Reading a File**
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int     fd;
    char    *line;
    
    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    
    // Read file line by line
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    return (0);
}
```

**Example 2: Multiple File Descriptors (Bonus)**
```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int     fd1, fd2;
    char    *line1, *line2;
    
    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    
    // Alternate reading from both files
    line1 = get_next_line(fd1);
    line2 = get_next_line(fd2);
    
    printf("File 1: %s", line1);
    printf("File 2: %s", line2);
    
    free(line1);
    free(line2);
    
    close(fd1);
    close(fd2);
    return (0);
}
```

## ⚙️ Buffer Size Configuration

The `BUFFER_SIZE` is crucial for performance and testing:

```bash
# Small buffer (tests frequent read() calls)
cc -D BUFFER_SIZE=1 ...

# Standard buffer
cc -D BUFFER_SIZE=42 ...

# Large buffer (tests memory efficiency)
cc -D BUFFER_SIZE=10000000 ...
```

**Why it matters:**
- Tests edge cases (BUFFER_SIZE = 1)
- Simulates real-world scenarios (BUFFER_SIZE = 4096)
- Validates memory efficiency (BUFFER_SIZE = 10000000)

Your implementation must work correctly with **any** buffer size!

## 💡 What I Learned

This project provided valuable experience in several advanced C programming concepts:

### Core Technical Skills
- **Static Variables**: First hands-on experience with static storage duration and function-local persistence
- **File Descriptor Operations**: Direct use of `read()` system call for low-level file I/O
- **State Management**: Maintaining state across function calls without global variables
- **Buffer Strategies**: Implementing efficient buffering with configurable sizes
- **Memory Efficiency**: Reading files without loading them entirely into memory

### Software Engineering Practices
- **Modular Design**: Separating core logic (get_next_line.c) from utilities (get_next_line_utils.c)
- **Edge Case Handling**: EOF detection, missing newlines, empty files, various buffer sizes
- **Testing**: Extensive testing with different buffer sizes and file types
- **Code Reusability**: Building a utility function for use in future projects
- **Resource Management**: Proper file descriptor and memory cleanup

### Problem-Solving Approaches
- **Algorithm Design**: Designing line extraction logic that works across read() boundaries
- **Debugging Complex State**: Tracing static variable state across multiple calls
- **Performance Optimization**: Minimizing read() syscalls while maintaining correctness

**Impact**: This function has been integrated into subsequent 42 School projects requiring file processing, providing reliable line-by-line reading.

## 📋 Project Requirements

This project was developed according to 42 School's strict requirements:

### Mandatory Constraints
- ✅ Written entirely in C
- ✅ Follows [Norminette](https://github.com/42School/norminette) coding standard
- ✅ Compiled with `-Wall -Wextra -Werror` flags
- ✅ No crashes (segfaults, bus errors, double free)
- ✅ Zero memory leaks
- ✅ Returns line with `\n` (unless EOF without `\n`)
- ✅ Works with any BUFFER_SIZE value
- ✅ Handles standard input and regular files

### External Functions Allowed
- `read` - Reading from file descriptors
- `malloc`, `free` - Dynamic memory management

### Forbidden
- ❌ Using libft (must implement utilities from scratch)
- ❌ `lseek()` function
- ❌ Global variables

### Additional Notes
- **Bonus Part**: Implemented (multiple file descriptor support)
  - Bonus features: Single static variable manages all file descriptors
  - Can read from fd 3, then 4, then 3 again without losing position
  - Uses array indexed by fd for state storage
- **Testing**: Thoroughly tested with buffer sizes: 1, 42, 9999, 10000000
- **Undefined Behavior**: File changes during reading, binary files (as per project specification)

### File Structure
Mandatory files:
- `get_next_line.c` - Main implementation
- `get_next_line_utils.c` - Helper functions
- `get_next_line.h` - Header file

Bonus files:
- `get_next_line_bonus.c` - Multiple FD implementation
- `get_next_line_utils_bonus.c` - Bonus utilities
- `get_next_line_bonus.h` - Bonus header

## ⚖ License

This project is licensed under the MIT License. See the [`LICENSE`](LICENSE) file for more details.

## 📫 Contact

**Berat Boşnak**

- 💼 LinkedIn: [linkedin.com/in/beratbosnak](https://www.linkedin.com/in/beratbosnak)
- 🐙 GitHub: [@beratbosnak](https://github.com/beratbosnak)

---

<div align="center">

*This project is part of the 42 School curriculum - a peer-to-peer learning environment that emphasizes practical skills, problem-solving, and collaboration.*

**42 School** | **Kocaeli Campus** | **2023**

</div>