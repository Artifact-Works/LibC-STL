### **vector\_api.md** (Vector API Reference)

# Vector API Reference

**1\. Constructor**

#### Vector()

*   Creates an empty vector with zero size and default capacity.
    

**2\. push\_back**


#### void push\_back(T value)

*   Adds an element to the end of the vector.
*   Increases the size by 1.
*   Resizes the capacity if needed.
    

**3\. pop\_back**


#### void pop\_back()

*   Removes the last element of the vector.
*   Decreases the size by 1.
*   Does nothing if the vector is empty.
    

**4\. size**

#### size\_t size() const

*   Returns the number of elements currently stored in the vector.
    

**5\. capacity**

#### size\_t capacity() const

*   Returns the total allocated capacity of the vector. 
*   The capacity increases dynamically as more elements are added.
    

**6\. at**


#### T& at(size\_t index)

*   Returns a reference to the element at the specified index.
*   Throws an error if the index is out of bounds.
    

**7\. operator\[\]**

#### T& operator\[\](size\_t index)

*   Returns a reference to the element at the given index.   
*   Does not perform bounds checking.
    

**8\. clear**

#### void clear()

*   Removes all elements from the vector.
*   Resets the size to zero but may retain allocated capacity.
    

**9\. empty**

#### bool empty() const

*   Returns true if the vector has no elements, otherwise false.