# Projectlyzer

Projectlyzer is a command-line tool for analyzing source code projects. It provides a summary of the files in a directory, including the number of lines, file size, and last modification date. It also calculates the total number of lines and the total size of all files in the directory.

## Features

-   List files in a directory
-   Display the number of lines in each file
-   Display the size of each file
-   Display the last modification date of each file
-   Calculate the total number of lines in the project
-   Calculate the total size of the project
-   Sort files by last modification date
-   Real-time updates

## Installation and Building

To build the project, you need a C++ compiler that supports C++20 and `make`.

1.  Clone the repository:
    ```bash
    git clone https://github.com/HassanIQ777/Projectlyzer.git
    ```
2.  Navigate to the project directory:
    ```bash
    cd projectlyzer
    ```
3.  Build the project using the Makefile:
    ```bash
    make
    ```
    This will create an executable named `projectlyzer` in the root directory.

## Usage

Run the tool by providing the path to the directory you want to analyze:

```bash
./projectlyzer <directory_path>
```

The output will be a table with the following columns:

-   **Filename:** The name of the file.
-   **Lines:** The number of lines in the file.
-   **Size:** The size of the file.
-   **Last Modification:** The last modification date and time of the file.

The tool will also display the total number of lines and the total size of all files in the directory. The output will be updated every second.

## libutils Library

Projectlyzer uses the `libutils` library, which is a collection of utility classes and functions for C++. The library is located in the `libutils` directory and includes the following modules:

-   `benchmark.hpp`: A simple benchmarking utility.
-   `binarycache.hpp`: A utility for saving and loading data in binary format.
-   `cliparser.hpp`: A command-line argument parser.
-   `color.hpp`: A utility for adding colors to console output.
-   `file.hpp`: A comprehensive file management utility.
-   `funcs.hpp`: A collection of miscellaneous utility functions.
-   `log.hpp`: A simple logging utility.
-   `random.hpp`: A random number generation utility.
-   `strutils.hpp`: A collection of string manipulation utilities.
-   `table.hpp`: A utility for creating and displaying tables in the console.
-   `texteditor.hpp`: A simple text editor.
-   `timer.hpp`: A timer utility.
-   `tokenizer.hpp`: A string tokenizer.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
