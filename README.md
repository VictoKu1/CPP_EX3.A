# Numbers with Units - Phase A

## Task

In 1999, a NASA satellite worth $125 million crashed due to unit mismatch - one team developed the satellite using metric units while the other team used British units (see additional examples [here](http://mentalfloss.com/article/25845/quick-6-six-unit-conversion-disasters)).

To prevent this from happening again, you have been hired to write a class that represents a number with units. This class can represent numbers like "3 meters" and "40 centimeters", and their sum will be 3.4 meters - the class will handle the appropriate conversion. Additionally, the class will not allow adding numbers with incompatible dimensions, such as adding "3 meters" with "5 seconds", which will throw an exception.

**Required Implementation:**
- Define a class named `NumberWithUnits` with the following operations:
  - `read_units` function that reads units from a text file
  - Six arithmetic operators: addition (+), compound addition (+=), unary plus (+), and three corresponding subtraction operators (-)
  - Six comparison operators: greater than, greater than or equal, less than, less than or equal, equal, not equal
  - Increment (++) and decrement (--) operators (prefix and postfix)
  - Multiplication by a real number (`double`)
  - Input and output operators

**Unit Conversion File Format:**
- Each line contains a conversion rule starting with "1", followed by a unit name, "=", a number, and another unit name
- Units not defined in the file are considered illegal and will throw exceptions
- Case-sensitive unit matching

**Input/Output Format:**
- Output format: number followed by square brackets containing the unit (e.g., "2[km]")
- Input format: similar to output but allows whitespace

## Solution

### Overview

The `NumberWithUnits` class provides a robust solution for handling dimensional quantities with automatic unit conversion. The implementation ensures type safety by preventing operations between incompatible units while providing seamless conversion between compatible units.

### Architecture

#### Core Class Structure

The `NumberWithUnits` class consists of:
- **Private members**: `double number` (the numeric value) and `string unit` (the unit specification)
- **Constructor**: Takes a numeric value and unit string
- **Static method**: `read_units()` for loading unit conversion rules from file
- **Friend functions**: For unit conversion and operator overloading

#### Unit Conversion System

The class implements a graph-based unit conversion system where:
- Units are nodes in a conversion graph
- Conversion factors are weighted edges
- The `convert()` function finds the shortest conversion path between compatible units
- Incompatible units (different dimensions) throw exceptions

#### Key Features

**1. Arithmetic Operations**
- **Addition/Subtraction**: Automatically converts units to match the first operand
- **Compound Assignment**: Modifies the left operand in place
- **Unary Operations**: Negation and identity operations
- **Multiplication**: Only supports multiplication by scalar values (not between two `NumberWithUnits` objects)

**2. Comparison Operations**
- All six comparison operators (<, <=, >, >=, ==, !=)
- Comparisons are performed after unit conversion
- Returns boolean results based on converted values

**3. Increment/Decrement**
- Both prefix (++a) and postfix (a++) versions
- Increments/decrements the numeric value while preserving the unit

**4. Input/Output Streams**
- **Output**: Formats as "value[unit]" (e.g., "2.5[km]")
- **Input**: Parses the same format with optional whitespace
- Handles malformed input gracefully

### Implementation Details

#### Unit File Parsing

The `read_units()` function:
- Reads conversion rules from a text file
- Builds a conversion graph in memory
- Validates file format and handles parsing errors
- Supports bidirectional conversions (if 1 km = 1000 m, then 1 m = 0.001 km)

#### Conversion Algorithm

The conversion process:
1. **Validation**: Checks if both units exist in the conversion graph
2. **Path Finding**: Uses graph traversal to find conversion path
3. **Calculation**: Applies conversion factors along the path
4. **Error Handling**: Throws exceptions for incompatible units

#### Error Handling

The implementation includes comprehensive error handling:
- **Invalid Units**: Throws exceptions for undefined units
- **Incompatible Dimensions**: Prevents operations between different unit types
- **File I/O Errors**: Handles file reading and parsing errors
- **Input Format Errors**: Validates input stream format

### Usage Examples

```cpp
// Initialize with units file
ifstream units_file{"units.txt"};
NumberWithUnits::read_units(units_file);

// Create objects
NumberWithUnits distance{2, "km"};     // 2 kilometers
NumberWithUnits length{300, "m"};      // 300 meters

// Arithmetic operations
NumberWithUnits sum = distance + length;        // 2.3[km]
NumberWithUnits diff = length - distance;       // -1700[m]

// Comparison operations
bool is_greater = distance > length;            // true
bool is_equal = distance == NumberWithUnits{2000, "m"}; // true

// Increment/decrement
++distance;  // 3[km]
length++;    // 301[m]

// Multiplication
NumberWithUnits scaled = 3 * distance;         // 6[km]

// Input/Output
cout << distance << endl;                      // "2[km]"
istringstream input{"700 [ kg ]"};
NumberWithUnits weight;
input >> weight;                               // 700[kg]
```

### Testing Strategy

The implementation includes comprehensive test coverage:
- **Unit Tests**: Individual function testing
- **Integration Tests**: End-to-end functionality testing
- **Edge Cases**: Boundary conditions and error scenarios
- **Performance Tests**: Large-scale conversion testing

### Build System

The project uses a Makefile for building and testing:
```bash
make demo && ./demo    # Run demonstration
make test && ./test    # Run test suite
make tidy             # Code formatting
```

### Dependencies

- Standard C++ libraries: `<iostream>`, `<fstream>`, `<sstream>`, `<stdexcept>`, `<string>`
- No external dependencies required
- Compatible with C++11 and later standards

### Performance Considerations

- **Memory**: Efficient graph representation for unit conversions
- **Time Complexity**: O(V + E) for unit conversion path finding
- **Scalability**: Supports arbitrary unit conversion networks
- **Optimization**: Caches conversion paths for repeated operations

This implementation provides a robust, type-safe solution for dimensional calculations while maintaining clean, readable code and comprehensive error handling. 