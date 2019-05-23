# arduino-samples

## docker - arduino environment

```bash
docker build -t arduino .
docker run -it -v $(pwd)/projects:/usr/src/app arduino bash
```

All-in-one

```bash
docker build -t arduino .
docker run -it -v $(pwd)/private:/usr/src/app arduino bash
gcc -I /usr/lib/avr/include -o main main.c && ./main
./main
```
