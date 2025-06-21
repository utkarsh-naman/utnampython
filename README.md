This is utnampython built on cpython version 3.11.9
=============================
Majority of the code belongs to the original cpython which can be found at https://github.com/python/cpython

## INSTALLATION:

I have installers for utnampython which can be found [here](https://drive.google.com/drive/folders/1qS09KcC88XSNJdAcVEQfB4pTZX_6b9XQ?usp=sharing)
### Windows
installer for 64 bit architecture is [here](https://drive.google.com/drive/folders/1uzGMSMbgpVJE2tHNc0Xbj4LI8z-FxsgF?usp=drive_link)
installer for 32 bit architecture is [here](https://drive.google.com/drive/folders/1cBtAahgBm5sAM3RF0_GzjQCExs_gBFtf?usp=sharing)


## Build:

### Windows

#### 64 bit
```
PCbuild\build.bat -p x64 -c Release
```

#### 32 bit
```
PCbuild\build.bat -p win32 -c Release
```


## Built-In Functions
### 1. tte(string_var)
this tte() function takes a string as input and returns the python expression for that mathematical expression string\
e.g: 1
```
print(tte("13pi12"))
```
Output:
```
13*math.pi*12
```
e.g: 2
```
print(tte("2pilnlnln134^e/17sqrtpi"))
```
Output:
```
2*math.pi*(math.log(math.log(math.log(134))))**math.e/(17)*(math.sqrt(math.pi))
```

### 2. write_out(filename)
this function saves the output of the latest program on terminal and copies it in a txt file. It takes the filename you want to save the file with and append date and time suffix with it and creates the file.

just add the write_out() at the end of your code
```
for i in range(1, 11, 1):
    print(i)
write_out()
```

## Built-in Lib
### utnalgo
#### utnalgo/Graph
```
from utnalgo.Graph.traversal import bfs, dfs, dijkstra, a_star, bellman_ford
```
