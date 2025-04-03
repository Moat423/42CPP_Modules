#include <iostream>
#include <ostream>
#include "Point.hpp"
#include <limits>

int	main( void ) 
{
    std::cout << "=== TRIANGLE POINT CONTAINMENT TEST SUITE ===\n" << std::endl;
    std::cout << "Requirements: returns true if the Point is inside the triangle," << std::endl;
    std::cout << "returns false if on vertex, on line or outside area of triangle\n" << std::endl;
    
    // Print true and false instead of 0 and 1
    std::cout << std::boolalpha;
    
    int testNr = 0;
    
    // Define a triangle for most tests
	float	x0 = 0.0f;
	float	y0 = 0.0f;

	float	x1 = 10;
	float	y1 = 0;

	float	x2 = 5;
	float	y2 = 10;

    Point a(0.0f, 0.0f);      // Origin
    Point b(10.0f, 0.0f);     // 10 units right from origin
    Point c(5.0f, 10.0f);     // 5 units right, 10 units up (forming a triangle)
    
	std::cout << "actual area of the triange, from FLOATS: " << std::abs(x0 * (y1 - y2) + x1 * (y2 - y0) + x2 * (y0 - y1)) / 2 << std::endl;
    // Test 1: Point clearly inside the triangle
    std::cout << "Test " << ++testNr << ": Point clearly inside the triangle" << std::endl;
    Point insidePoint(5.0f, 3.0f);
    std::cout << "Expected: true, Result: " << bsp(a, b, c, insidePoint) << "\n" << std::endl;

    // Test 2: Point clearly outside the triangle
    std::cout << "Test " << ++testNr << ": Point clearly outside the triangle" << std::endl;
    Point outsidePoint(15.0f, 15.0f);
    std::cout << "Expected: false, Result: " << bsp(a, b, c, outsidePoint) << "\n" << std::endl;

    // Test 3: Point exactly on vertex A
    std::cout << "Test " << ++testNr << ": Point exactly on vertex A" << std::endl;
    Point onVertexA(0.0f, 0.0f);  // Same as vertex A
    std::cout << "Expected: false, Result: " << bsp(a, b, c, onVertexA) << "\n" << std::endl;

    // Test 4: Point exactly on vertex B
    std::cout << "Test " << ++testNr << ": Point exactly on vertex B" << std::endl;
    Point onVertexB(10.0f, 0.0f);  // Same as vertex B
    std::cout << "Expected: false, Result: " << bsp(a, b, c, onVertexB) << "\n" << std::endl;

    // Test 5: Point exactly on vertex C
    std::cout << "Test " << ++testNr << ": Point exactly on vertex C" << std::endl;
    Point onVertexC(5.0f, 10.0f);  // Same as vertex C
    std::cout << "Expected: false, Result: " << bsp(a, b, c, onVertexC) << "\n" << std::endl;

    // Test 6: Point exactly on edge AB
    std::cout << "Test " << ++testNr << ": Point exactly on edge AB (bottom edge)" << std::endl;
    Point onEdgeAB(5.0f, 0.0f);  // Middle of bottom edge
    std::cout << "Expected: false, Result: " << bsp(a, b, c, onEdgeAB) << "\n" << std::endl;

    // Test 7: Point exactly on edge BC
    std::cout << "Test " << ++testNr << ": Point exactly on edge BC (right edge)" << std::endl;
    Point onEdgeBC(7.5f, 5.0f);  // Middle-ish of right edge
    std::cout << "Expected: false, Result: " << bsp(a, b, c, onEdgeBC) << "\n" << std::endl;

    // Test 8: Point exactly on edge CA
    std::cout << "Test " << ++testNr << ": Point exactly on edge CA (left edge)" << std::endl;
    Point onEdgeCA(2.5f, 5.0f);  // Middle-ish of left edge
    std::cout << "Expected: false, Result: " << bsp(a, b, c, onEdgeCA) << "\n" << std::endl;

    // Test 9: Point just inside the triangle (very close to edge AB)
    std::cout << "Test " << ++testNr << ": Point just inside the triangle (near bottom edge)" << std::endl;
    Point justInside1(5.0f, 0.1f);  // Just above bottom edge
    std::cout << "Expected: true, Result: " << bsp(a, b, c, justInside1) << "\n" << std::endl;

    // Test 10: Point just inside the triangle (very close to edge BC)
    std::cout << "Test " << ++testNr << ": Point just inside the triangle (near right edge)" << std::endl;
    Point justInside2(7.4f, 5.0f);  // Just left of right edge
    std::cout << "Expected: true, Result: " << bsp(a, b, c, justInside2) << "\n" << std::endl;

    // Test 11: Point just inside the triangle (very close to edge CA)
    std::cout << "Test " << ++testNr << ": Point just inside the triangle (near left edge)" << std::endl;
    Point justInside3(2.6f, 5.0f);  // Just right of left edge
    std::cout << "Expected: true, Result: " << bsp(a, b, c, justInside3) << "\n" << std::endl;

    // Test 12: Point just outside the triangle (very close to edge AB)
    std::cout << "Test " << ++testNr << ": Point just outside the triangle (near bottom edge)" << std::endl;
    Point justOutside1(5.0f, -0.1f);  // Just below bottom edge
    std::cout << "Expected: false, Result: " << bsp(a, b, c, justOutside1) << "\n" << std::endl;

    // Test 13: Point just outside the triangle (very close to edge BC)
    std::cout << "Test " << ++testNr << ": Point just outside the triangle (near right edge)" << std::endl;
    Point justOutside2(7.6f, 5.0f);  // Just right of right edge
    std::cout << "Expected: false, Result: " << bsp(a, b, c, justOutside2) << "\n" << std::endl;

    // Test 14: Point just outside the triangle (very close to edge CA)
    std::cout << "Test " << ++testNr << ": Point just outside the triangle (near left edge)" << std::endl;
    Point justOutside3(2.4f, 5.0f);  // Just left of left edge
    std::cout << "Expected: false, Result: " << bsp(a, b, c, justOutside3) << "\n" << std::endl;

    // Test 15: Point just outside a vertex (very close to vertex A)
    std::cout << "Test " << ++testNr << ": Point just outside vertex A" << std::endl;
    Point nearVertexA(-0.1f, -0.1f);  // Just outside vertex A
    std::cout << "Expected: false, Result: " << bsp(a, b, c, nearVertexA) << "\n" << std::endl;

    // Test 16: Degenerate triangle (points in a line)
    std::cout << "Test " << ++testNr << ": Degenerate triangle (points in a line)" << std::endl;
    Point lineA(0.0f, 0.0f);
    Point lineB(5.0f, 5.0f);
    Point lineC(10.0f, 10.0f);  // These three points form a line
    Point onLinePoint(2.5f, 2.5f);  // Point on the line
    std::cout << "Expected: false, Result: " << bsp(lineA, lineB, lineC, onLinePoint) << "\n" << std::endl;

    // Test 17: Point at centroid (center) of triangle
    std::cout << "Test " << ++testNr << ": Point at centroid (center) of triangle" << std::endl;
    Point center(5.0f, 3.333f);  // Approximate centroid of original triangle
    std::cout << "Expected: true, Result: " << bsp(a, b, c, center) << "\n" << std::endl;

    // Test 18: Different order of vertices (shouldn't affect result)
    std::cout << "Test " << ++testNr << ": Different order of vertices" << std::endl;
    std::cout << "Expected: true, Result: " << bsp(b, c, a, insidePoint) << "\n" << std::endl;

	// Test 19: big triangle
	std::cout << "max: " << (std::numeric_limits<int>::max() >> 8) << std::endl;
    std::cout << "Test " << ++testNr << ": Big triangle" << std::endl;
    Point A21(8607, 0.0f);
    Point B21(0.0f, 8607);
    Point C21(0.0f, 0.0f);
    Point P21(100.0f, 100.0f);
    std::cout << "Expected: true, Result: " << bsp(A21, B21, C21, P21) << "\n" << std::endl;
    /**/
    /*// Test that doesn't work for fixed points: Very tiny triangle to test precision*/
    /*std::cout << "Test " << ++testNr << ": Very tiny triangle to test precision" << std::endl;*/
    /*Point tinyA(0.0f, 0.0f);*/
    /*Point tinyB(0.010f, 0.0f);*/
    /*Point tinyC(0.0f, 0.010f);*/
    /*Point tinyInside(0.00390625f, 0.00390625f);  // Inside the tiny triangle*/
    /*std::cout << "Expected: true, Result: " << bsp(tinyA, tinyB, tinyC, tinyInside) << "\n" << std::endl;*/
    /**/
    /*// Test that doesn't work for fixed points: Original test*/
    /*std::cout << "Test " << ++testNr << ": Original test from example" << std::endl;*/
    /*Point originalA(0.0f, 0.0f);*/
    /*Point originalB(0.0f, 1.0f);*/
    /*Point originalC(1.0f, 0.0f);*/
    /*Point originalPoint(0.5f, 0.5f);*/
    /*std::cout << "Expected: true, Result: " << bsp(originalA, originalB, originalC, originalPoint) << "\n" << std::endl;*/
	return 0;
}
