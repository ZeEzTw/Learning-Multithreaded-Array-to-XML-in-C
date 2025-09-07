# Learning Multithreaded Array-to-XML in C

This is a learning project where I experiment with:  
- Multithreaded programming in C (`pthread`)  
- Writing and manipulating XML files  
- Converting arrays into XML format  

## Project Goal

The goal of this project is to understand how threads work and how they can be used to speed up repetitive data processing tasks.  

⚠️ Educational project – code written for practice and learning purposes.

## Observations

- When running the code using **multithreading** with **5,000,000 iterations**, the average execution time was **~11 seconds**.  
- Running the same task **normally (without threads)** took **~30 seconds**.  
- The performance difference increases as the project size and data volume grow.  
- For smaller datasets, the difference is not significant, and sometimes multithreading can even be slower.  
- **Conclusion:** Multithreading is very useful, especially for large projects and intensive operations.  
