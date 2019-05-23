# arduino-samples

## docker - arduino environment

```bash
docker build -t arduino .
docker run -it -v $(pwd)/projects:/usr/src/app arduino bash
```

All-in-one

```bash
docker build -t arduino . && docker run -it -v $(pwd)/projects:/usr/src/app arduino bash
gcc -o hello hello.c
./hello
```
