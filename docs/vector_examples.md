### **vector\_examples.md** (Vector Usage Examples)

**Vector Usage Examples**
=========================

**1\. Creating a Vector**
-------------------------

```   
#include "Vector.h"  
int main() {      
    Vector vec; // Creates an empty vector      
    return 0;  }   
```

2\. Adding Elements using **push\_back**
----------------------------------------
```   
vec.push_back(10); 
 vec.push_back(20);  
 vec.push_back(30);   
 ```

_The vector now contains: \[10, 20, 30\]_

3\. Accessing Elements using **operator\[\]**
---------------------------------------------

```   
std::cout << vec[0]; // Outputs: 10  
std::cout << vec[2]; // Outputs: 30   
```

4\. Accessing Elements using **at()**
-------------------------------------

```   
try {      
    std::cout << vec.at(1); // Outputs: 20      
    std::cout << vec.at(5); // Throws an error (out of bounds)  
    } 
    catch (const std::out_of_range& e) {      
        std::cerr << "Error: " << e.what() << std::endl;  
        }   
```

5\. Removing the Last Element using **pop\_back**
-------------------------------------------------

```
vec.pop_back(); // Removes the last element (30)   
```

_The vector now contains: \[10, 20\]_

6\. Checking **Size** and **Capacity**
----------------------------------

```  
std::cout << "Size: " << vec.size();     // Outputs: 2  
std::cout << "Capacity: " << vec.capacity(); // Might be larger than size   
```

7\. Clearing the Vector
---------------------------

```
vec.clear(); // Removes all elements  
std::cout << vec.size(); // Outputs: 0   
```

8\. Checking if Vector is Empty
-----------------------------------
```
if (vec.empty()) {      
    std::cout << "Vector is empty";  
    }   
```