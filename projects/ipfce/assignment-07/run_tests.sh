#!/bin/bash

echo "Running local tests for IPFCE Assignment 7..."

# Clean up old test files
echo "Cleaning up old test output files..."
rm -f tests/test_output_exercise*.txt

# Initialize counters
total_tests=0
passed_tests=0
failed_exercises=()

# Function to test an exercise
test_exercise() {
    local exercise_num=$1
    echo "Testing Exercise $exercise_num..."
    total_tests=$((total_tests + 1))
    
    # Determine compilation flags based on exercise
    local compile_flags="-Iinclude -std=c11"
    if [ "$exercise_num" -eq 1 ]; then
        compile_flags="$compile_flags -lm"  # Add math library for exercise 1
    fi
    
    # Try to compile the test
    if gcc $compile_flags -o "tests/test_exercise$exercise_num" "tests/test_exercise$exercise_num.c" "exercise$exercise_num.c" 2> "tests/test_output_exercise$exercise_num.txt"; then
        # Run the test with timeout to prevent hanging
        timeout 10s "./tests/test_exercise$exercise_num" >> "tests/test_output_exercise$exercise_num.txt" 2>&1
        local exit_code=$?
        
        if [ $exit_code -eq 0 ]; then
            echo "✓ Exercise $exercise_num tests passed"
            passed_tests=$((passed_tests + 1))
        else
            echo "✗ Exercise $exercise_num tests failed"
            failed_exercises+=("$exercise_num")
            if [ $exit_code -eq 124 ]; then
                echo "Tests timed out after 10 seconds" >> "tests/test_output_exercise$exercise_num.txt"
            fi
            echo "Error details saved to tests/test_output_exercise$exercise_num.txt"
        fi
        
        rm -f "tests/test_exercise$exercise_num"
    else
        echo "✗ Exercise $exercise_num compilation failed"
        failed_exercises+=("$exercise_num")
        echo "Error details saved to tests/test_output_exercise$exercise_num.txt"
    fi
}

# Test each exercise
test_exercise 1
test_exercise 2

echo ""
echo "📋 Test Summary: $passed_tests/$total_tests passed"
if [ ${#failed_exercises[@]} -eq 0 ]; then
    echo "🎉 All tests passed!"
else
    echo "❌ Failed exercises: ${failed_exercises[*]}"
fi
echo ""
echo "📁 Check tests/test_output_exercise*.txt files for detailed results"
