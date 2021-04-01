Варианты запуска:

1)Создать временную директорию(к примеру "tmp")  и в ней прописать "cmake .." и "make",
затем в директории выше появится исполнительный файл "main" запустить его "./main"
НАПРИМЕР: "mkdir tmp && cd tmp && cmake .. && make && ./main"

2)Скомпилировать самому с помощью gcc
"gcc -o main -std=c99 main.c ./library/array.c ./library/lib_int_algebra.c ./library/lib_float_algebra.c"
