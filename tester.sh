#!/bin/bash

# Function to execute the code
execute_code() {
    ./philo 4 210 100 100 &
    local pid=$!
    sleep 10
    if ps -p $pid > /dev/null; then
        # Process is still running, return success
		kill $pid
        return 0
    fi
    # Process has finished, return failure
    return 1
}

# Main script
failed=false
for ((i = 1; i <= 100; i++)); do
    echo "Running iteration $i"
    execute_code
    if [ $? -ne 0 ]; then
        echo "Execution failed on iteration $i"
        failed=true
        break
    fi
done

if [ "$failed" = false ]; then
    echo "All executions completed successfully."
else
    echo "Execution terminated due to failure."
fi
