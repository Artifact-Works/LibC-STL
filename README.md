# LibC-STL: A C Implementation of Standard Template Library (STL)

## Overview

C-STL is a project aimed at implementing a subset of the functionality provided by the C++ Standard Template Library (STL) in pure C. The motivation behind this project stems from the efficiency and versatility of the C++ STL, which has been widely acclaimed as one of the most efficient code libraries in C++. This projects aims at implementing C++ STL in C as efficient and as easy to use as possible.

## Motivation
The C++ STL is renowned for its rich collection of data structures, algorithms, and utilities, which simplify and streamline the process of software development in C++. Recognizing the value and efficiency of the STL, this project seeks to bridge this gap by bringing some of the essential features of the STL to the C programming language.

## Project Goals
- Implement core data structures such as vectors, linked lists, stacks, queues, maps, and sets in C.
- Develop efficient algorithms for common operations like sorting, searching, and manipulation of data structures.
- Provide a user-friendly interface and intuitive API for easy integration into C projects.
- Ensure compatibility and portability across different platforms and compilers.
- Foster a community of contributors and users to collaborate on further enhancements and improvements.

## Key Features
- **Vector**: Resizable arrays similar to vectors in C++. [Example](#example)
- **Iterators**: C++ style iterators to iterate containers efficiently.
- **Linked List**: Singly linked lists, doubly linked lists, and circular linked lists. [to be implemened]
- **Stacks and Queues**: Implementations using arrays or linked lists. [to be implemened]
- **Maps and Sets**: Hash maps or binary search trees for key-value pairs and unique elements. [to be implemened]
- **String Manipulation**: Functions for manipulating strings, including concatenation, substring extraction, and searching. [to be implemened]
- **Algorithms**: Common algorithms for sorting, searching, and manipulation of sequences. [to be implemened]
- **Error Handling**: Mechanisms for error handling and exception management. [to be implemened]

# Contributing
Contributors are welcomed add more functionalities or fixes..
- Raise an issue about the about feature you want to add and wait for it to assigned to you.
- Or check any existing issue if you want to work on them [Issues](https://github.com/SharonIV0x86/LibC-STL/issues)
- Edit your code and open the PR, documentation will be taken care of. Feel free to share if you have anything extra to add in docs.
- Make sure to add block comments above your added feature.

## License
This project is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute the code according to the terms of the license.

### Note from maintainer
This project serves as a learning endeavor for me to explore dynamic memory management in C, gaining insights into the STL in C++, and honing skills in library design and DSA. I'm eager to see this project flourish and evolve further.

## Example
```c
#include <stdio.h>
#include "./include/Vector.h"

typedef struct mystruct
{
    int data;
    char *name;
} MyStruct;

int main()
{
    Vector *int_vec = vector_create(sizeof(int));

    int values[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++)
    {
        vector_push_back(int_vec, &values[i]);
    }

    printf("Integer Vector:\n");
    for (size_t i = 0; i < vector_size(int_vec); i++)
    {
        printf("%d ", *(int *)vector_at(int_vec, i));
    }
    printf("\n");

    vector_destroy(int_vec);

    Vector *double_vec = vector_create(sizeof(double));

    double dvalues[] = {1.1, 2.2, 3.3, 4.4};
    for (int i = 0; i < 4; i++)
    {
        vector_push_back(double_vec, &dvalues[i]);
    }

    printf("Double Vector:\n");
    for (size_t i = 0; i < vector_size(double_vec); i++)
    {
        printf("%.1f ", *(double *)vector_at(double_vec, i));
    }
    printf("\n");

    vector_destroy(double_vec);
    MyStruct v1 = {10, "Jasper"};
    MyStruct v2 = {20, "Kasper"};
    MyStruct v3 = {30, "Hasper"};
    MyStruct v4 = {40, "Gasper"};

    Vector *custom_vec = vector_create(sizeof(MyStruct));
    vector_push_back(custom_vec, &v1);
    vector_push_back(custom_vec, &v2);
    vector_push_back(custom_vec, &v3);
    vector_push_back(custom_vec, &v4);
     
    for(size_t i = 0; i < vector_size(custom_vec); i++){
        MyStruct *item = (MyStruct*)vector_at(custom_vec, i);
        printf("%d %s\n", item->data, item->name);
    }

    return 0;
}


```
## Error Handling

All functions that modify vectors return predefined error codes.  

| Error Code         | Description                          |
|--------------------|----------------------------------|
| `SUCCESS (1)`     | Operation successful              |
| `FAILURE (0)`     | Generic failure                  |
| `ERR_INVALID_TYPE (-1)` | Invalid data type for vector  |
| `ERR_OUT_OF_MEMORY (-2)` | Memory allocation failed     |
| `ERR_INDEX_OUT_OF_BOUNDS (-3)` | Index out of range     |
| `ERR_NULL_POINTER (-4)` | Null pointer detected        |

### Example Usage:
```c
Vector *vec = create_vector(5, INT);
if (!vec) {
    printf("Error: Vector creation failed\n");
}

int status = push_back_int(vec, 10);
if (status != SUCCESS) {
    printf("Error: push_back_int failed with error code %d\n", status);
}
yaml
Copy
Edit

## Feedback and Support
If you have any feedback, suggestions, or questions regarding the project, please feel free to open an issue.

## Acknowledgements
We would like to express our gratitude to the creators and maintainers of the C++ STL, whose work has inspired this project. Additionally, we thank all contributors and users for their valuable feedback and contributions.
