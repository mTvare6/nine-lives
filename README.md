# Nine lives

### Building
```sh
make
```


### Installing
```sh
make install
```

### Configuring

```c
#define CUSTOMFILE 1
```
Set CUSTOMFILE(L#10) to 0 to use the default array(L#22) of characters(use the same words instead of reading from file)


```c
#define LIVES 9
```
Set LIVES(L#8) to any number of chances you want

### Usage
When the CUSTOMFILE is set to 1, the program needs to file to read the words from, an example given is ./words.txt 
```
./nine-lives words.txt
```

