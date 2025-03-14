#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

#include "Fixed.hpp"

// Helper function to test and print results
void testOperation(const std::string& testName, const Fixed& a, const Fixed& b, 
                   Fixed (*operation)(const Fixed&, const Fixed&), 
                   float expectedValue, bool expectException = false) {
    std::cout << "Test: " << testName << " | ";
    std::cout << "a=" << a.toFloat() << ", b=" << b.toFloat() << " | ";
    
    try {
        Fixed result = operation(a, b);
        if (expectException) {
            std::cout << "ERROR: Expected exception, but got result: " << result.toFloat() << std::endl;
        } else {
            float resultValue = result.toFloat();
            float diff = std::abs(resultValue - expectedValue);
            std::cout << "Result: " << resultValue << " | ";
            std::cout << "Expected: " << expectedValue << " | ";
            
            // Calculate relative error for non-zero expected values
            if (std::abs(expectedValue) > 1e-6) {
                float relativeError = diff / std::abs(expectedValue);
                std::cout << "Rel. Error: " << relativeError * 100 << "% | ";
                
                if (relativeError < 0.01) { // Allow 1% error due to fixed-point precision
                    std::cout << "PASS" << std::endl;
                } else {
                    std::cout << "FAIL (Result differs)" << std::endl;
                }
            } else {
                // For values close to zero, check absolute error
                if (diff < 0.01) {
                    std::cout << "PASS" << std::endl;
                } else {
                    std::cout << "FAIL (Result differs)" << std::endl;
                }
            }
        }
    } catch (const std::exception& e) {
        if (expectException) {
            std::cout << "PASS (Got expected exception: " << e.what() << ")" << std::endl;
        } else {
            std::cout << "FAIL (Unexpected exception: " << e.what() << ")" << std::endl;
        }
    }
}

// Operation wrapper functions
Fixed add(const Fixed& a, const Fixed& b) { return a + b; }
Fixed subtract(const Fixed& a, const Fixed& b) { return a - b; }
Fixed multiply(const Fixed& a, const Fixed& b) { return a * b; }
Fixed divide(const Fixed& a, const Fixed& b) { return a / b; }

int main() {
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "==== FIXED POINT ARITHMETIC TEST SUITE ====\n" << std::endl;
    
    // ===== ADDITION TESTS =====
    std::cout << "\n==== ADDITION TESTS ====\n" << std::endl;
    
    // Basic addition
    testOperation("Basic addition (positive)", Fixed(5.5f), Fixed(2.25f), add, 7.75f);
    testOperation("Basic addition (negative)", Fixed(-3.75f), Fixed(-1.25f), add, -5.0f);
    testOperation("Mixed sign addition", Fixed(10.5f), Fixed(-7.25f), add, 3.25f);
    
    // Addition with zero
    testOperation("Addition with zero", Fixed(42.125f), Fixed(0), add, 42.125f);
    testOperation("Zero addition", Fixed(0), Fixed(-17.625f), add, -17.625f);
    
    // Small number addition
    testOperation("Small number addition", Fixed(0.001953125f), Fixed(0.001953125f), add, 0.00390625f);
    
    // Overflow tests
    int maxInt = std::numeric_limits<int>::max();
    testOperation("Overflow addition", Fixed::fromRawBits(maxInt - 100), Fixed(1.0f), add, 0, true);
    testOperation("Underflow addition", Fixed::fromRawBits(std::numeric_limits<int>::min() + 100), Fixed(-1.0f), add, 0, true);

    // ===== SUBTRACTION TESTS =====
    std::cout << "\n==== SUBTRACTION TESTS ====\n" << std::endl;
    
    // Basic subtraction
    testOperation("Basic subtraction (positive)", Fixed(10.5f), Fixed(3.25f), subtract, 7.25f);
    testOperation("Basic subtraction (negative)", Fixed(-5.75f), Fixed(2.25f), subtract, -8.0f);
    testOperation("Mixed sign subtraction", Fixed(10.5f), Fixed(-7.25f), subtract, 17.75f);
    
    // Subtraction with zero
    testOperation("Subtraction from zero", Fixed(0), Fixed(5.5f), subtract, -5.5f);
    testOperation("Subtract zero", Fixed(42.125f), Fixed(0), subtract, 42.125f);
    
    // Small number subtraction
    testOperation("Small number subtraction", Fixed(0.00390625f), Fixed(0.001953125f), subtract, 0.001953125f);
    
    // Overflow tests
    testOperation("Overflow subtraction", Fixed::fromRawBits(maxInt - 100), Fixed(-1.0f), subtract, 0, true);
    testOperation("Underflow subtraction", Fixed::fromRawBits(std::numeric_limits<int>::min() + 100), Fixed(1.0f), subtract, 0, true);

    // ===== MULTIPLICATION TESTS =====
    std::cout << "\n==== MULTIPLICATION TESTS ====\n" << std::endl;
    
    // Basic multiplication
    testOperation("Basic multiplication (positive)", Fixed(3.5f), Fixed(2.0f), multiply, 7.0f);
    testOperation("Basic multiplication (negative)", Fixed(-2.5f), Fixed(4.0f), multiply, -10.0f);
    testOperation("Mixed sign multiplication", Fixed(3.5f), Fixed(-2.0f), multiply, -7.0f);
    testOperation("Negative * negative", Fixed(-3.5f), Fixed(-2.0f), multiply, 7.0f);
    
    // Multiplication with zero and one
    testOperation("Multiply by zero", Fixed(42.125f), Fixed(0), multiply, 0.0f);
    testOperation("Multiply by one", Fixed(42.125f), Fixed(1), multiply, 42.125f);
    
    // Fractional multiplication
    testOperation("Fractional multiplication", Fixed(0.5f), Fixed(0.5f), multiply, 0.25f);
    testOperation("Fractional multiplication (precise)", Fixed(1.5f), Fixed(1.5f), multiply, 2.25f);
    
    // Overflow tests
    testOperation("Overflow multiplication", Fixed(32000.0f), Fixed(100.0f), multiply, 0, true);
    testOperation("Underflow multiplication", Fixed(-32000.0f), Fixed(100.0f), multiply, 0, true);

    // ===== DIVISION TESTS =====
    std::cout << "\n==== DIVISION TESTS ====\n" << std::endl;
    
    // Basic division
    testOperation("Basic division (positive)", Fixed(10.0f), Fixed(2.0f), divide, 5.0f);
    testOperation("Basic division (negative)", Fixed(-10.0f), Fixed(2.0f), divide, -5.0f);
    testOperation("Mixed sign division", Fixed(10.0f), Fixed(-2.0f), divide, -5.0f);
    testOperation("Negative / negative", Fixed(-10.0f), Fixed(-2.0f), divide, 5.0f);
    
    // Division with one
    testOperation("Division by one", Fixed(42.125f), Fixed(1), divide, 42.125f);
    
    // Fractional division
    testOperation("Fractional division", Fixed(1.0f), Fixed(2.0f), divide, 0.5f);
    testOperation("Fractional division (precise)", Fixed(1.0f), Fixed(8.0f), divide, 0.125f);
    
    // Division by very small number (potential overflow)
    testOperation("Division by small number", Fixed(1000.0f), Fixed(0.001953125f), divide, 512000.0f, true);
    
    // Division by zero
    testOperation("Division by zero", Fixed(42.125f), Fixed(0), divide, 0, true);
    
    // ===== PRECISION TESTS =====
    std::cout << "\n==== PRECISION TESTS ====\n" << std::endl;
    
    // Test with the smallest representable value
    float smallestValue = 1.0f / (1 << 8);  // Assuming 8 fractional bits
    testOperation("Smallest representable value", Fixed(smallestValue), Fixed(1.0f), multiply, smallestValue);
    
    // Test precision chain
    Fixed a(1.0f);
    Fixed b(10.0f);
    Fixed c = a / b;     // c = 0.1
    Fixed d = c * b;     // d should be close to 1.0f again
    std::cout << "Precision chain test: 1.0 / 10.0 * 10.0 = " << d.toFloat() 
              << " (error: " << std::abs(d.toFloat() - 1.0f) << ")" << std::endl;
    
    // ===== LIMIT TESTS =====
    std::cout << "\n==== LIMIT TESTS ====\n" << std::endl;
    
    // Test with values close to limits
    float maxFixed = Fixed::fromRawBits(std::numeric_limits<int>::max()).toFloat();
    float minFixed = Fixed::fromRawBits(std::numeric_limits<int>::min()).toFloat();
    
    std::cout << "Maximum representable value: " << maxFixed << std::endl;
    std::cout << "Minimum representable value: " << minFixed << std::endl;
    
    // Test approaching limits
    testOperation("Near max + small value", Fixed::fromRawBits(std::numeric_limits<int>::max() - 1000), 
                 Fixed::fromRawBits(900), add, 0, true);
    
    std::cout << "\nAll tests completed.\n" << std::endl;
    
    return 0;
}
