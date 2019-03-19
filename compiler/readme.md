# How compiler works
1.  Generate Assembly language code  
```
g++ -S math.cpp
```
2. Generate Pre-processed file  
```
g++ -E math.cpp -o binary.i
```
3. Create object file using (it can be viewed in readable format by running instruction 1.)  
```
g++ -c math.cpp
```
