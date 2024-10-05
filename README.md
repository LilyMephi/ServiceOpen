# Динамическая библиотека для создания DBus-сервиса с функцией чтения файла

Эта динамическая библиотека предоставляет средства для создания DBus-сервиса, который читает указанный файл. Для компиляции и установки библиотеки вам потребуется использовать `qmake` и `make`. 

## Установка

1. Клонируйте репозиторий или скачайте исходный код библиотеки:
```bash
   git clone https://github.com/LilyMephi/ServiceOpen.git
   cd ServiceOpen
```
3. Создайте проект с помощью `qmake`:
```bush
   qmake ServiceOpen.pro
```
3. Соберите библиотеку:
```bash
   make
```
4. Перед запуском приложения, экспортируйте переменную окружения `LD_LIBRARY_PATH`, указывая путь к вашей библиотеке:

```bash
   export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path/to/lib/ServiceOpen
```
5. В папке `example` пример использования данной библиотеки
```bash
   qmake example.pro
   make
   ./ServiceOpen /path/to/file
```
Также в файле `example.pro` нужно изменить путь до библиотеки
   
